#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct pcb//进程结构体
{
	string pid = "hhj";
	int status = 0;//blocked 1, ready 2, running 3
	pcb* child = nullptr;
	pcb* parent = nullptr;
	int priority = 0;//0-init,1-user,2-system
	int resource_occupied[4] = { 0 }; //当前占有四类资源数
	int blocked_resc_type = 0;//引起阻塞资源的种类的类型：1，2，3，4
	pcb* next = nullptr;
};
struct rcb//资源结构体
{
	int rid = 0;//资源号
	int init_num = 0;//资源初始数
	int availa_num = 0;//资源现在可用的数量
	rcb* next = nullptr;
};
vector<pcb> all_process_list;//记录所有的进程信息
vector<vector<pcb>> ready_array(3, vector<pcb>(20));//0-init,1-user,2-system
vector<vector<pcb>> blocked_array(3, vector<pcb>(20));//0-init,1-user,2-system
vector<rcb> resource_list;
string running_pid = "hhj2";
void rcb_list_append(rcb* a, rcb b)
{
	a->next = &b;
}
void pcb_list_append(pcb* a, pcb b)
{
	a->next = &b;
}
void init_resource_list()
{
	for (int i = 0; i < 4; i++)
	{
		rcb a;
		a.rid = i + 1;
		a.init_num = i + 1; //4类资源，R1，R2，R3，R4，每类资源Ri有i个
		a.availa_num = a.init_num;
		resource_list.push_back(a);
	}
}
void create(string pid, pcb parent, pcb child, int priority)
{
	pcb a;
	a.pid = pid;
	if (parent.pid != "hhj") {
		a.parent = &parent;
		a.parent->child = &a;
	}
	if (child.pid != "hhj")
	{
		a.child = &child;
		a.child->parent = &a;
	}//原文件用append
	a.priority = priority;
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		if (a.pid == it->pid)
		{
			cout << "Don't create the process which is created before!" << endl;
			return;
		}
	}
	if (ready_array[0][0].pid!= "hhj")
	{
		if (running_pid == "hhj2")
		{
			running_pid = a.pid;
			a.status = 3;
		}
		else
		{
			a.status = 2;
			ready_array[1].push_back(a);
		}
	}
	else
	{
		a.status = 2;
		ready_array[1].push_back(a);
	}
	all_process_list.push_back(a);
	//省略sort ready步骤
}
pcb release1(string pid)
{
	pcb a;
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		if (it->pid == pid)
		{
			a = *it;
			for (int i = 0; i < 4; i++) 
			{
				resource_list[i].availa_num += it->resource_occupied[i];
				it->resource_occupied[i] = 0;
			}
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{ 
		for (vector<pcb>::iterator it2 = blocked_array[i].begin(); it2 != blocked_array[i].end(); it2++)
		{
			if (it2->blocked_resc_type == 0)continue;
			else
			{
				int num1 = it2->blocked_resc_type;
				if (it2->resource_occupied[num1 - 1] <= resource_list[num1 - 1].availa_num)
				{
					it2->status = 2;
					resource_list[num1 - 1].availa_num -= resource_list[num1 - 1].availa_num;
					blocked_array[i].erase(it2);
					ready_array[it2->priority].push_back(*it2);
				}
				else
				{
					continue;
				}
			}
		}
	}
	return a;
}
void destory(string pid)
{
	pcb a = release1(pid);
	for (int i = 0; i < 3; i++)
	{
		for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
		{
			if (it->pid == pid)
			{
				ready_array[i].erase(it);
			}
		}
	}
	if (running_pid == pid)running_pid = "hhj2";//如果正在运行的模块的PID值等于要删除的模块的PID值，则运行状态为空
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		if (it->pid == pid)all_process_list.erase(it);
	}
	if (a.child)
	{
		destory(a.child->pid);//递归调用删除该PCB的子进程PCB
	}
}
void request(int rid, int num) 
{
	pcb runningman;
	if (running_pid == "hhj2")
	{
		cout << "No process is running! Can't request!" << endl;
		return;
	}
	if (resource_list[rid - 1].availa_num < num)
	{
		cout << "Not enough resource" << endl;
		for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
		{
			if (it->pid == running_pid)
			{
				runningman = *it;
				break;
			}
		}
		runningman.blocked_resc_type = rid;
		runningman.resource_occupied[rid - 1] += num;
		runningman.status = 1;//blocked=1
		blocked_array[runningman.priority].push_back(runningman);
		if (ready_array[0][0].pid == "hhj" && ready_array[1][0].pid == "hhj" && ready_array[2][0].pid == "hhj")running_pid = "hhj2";
		else
		{
			for (int i = 2; i >=0 ; i--)
			{
				if (ready_array[i][0].pid != "hhj")
				{
					running_pid = ready_array[i][0].pid;
					ready_array[i][0].status = 3;
					vector<pcb>::iterator it = ready_array[i].begin();
					ready_array[i].erase(it);
					break;
				}
			}
		}
	}
	else
	{
		for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
		{
			if (it->pid == running_pid)
			{
				runningman.resource_occupied[rid - 1] += num;
				resource_list[rid - 1].availa_num -= num;
			}
		}
	}
}
void timeout()
{
	pcb runningman;
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		if (it->pid == running_pid)
		{
			runningman = *it;
			break;
		}
	}
	ready_array[runningman.priority].push_back(runningman);
	runningman.status = 2;
	for (int i = 2; i >= 0; i--)
	{
		if (ready_array[i][0].pid != "hhj")
		{
			running_pid = ready_array[i][0].pid;
			ready_array[i][0].status = 3;
			vector<pcb>::iterator it = ready_array[i].begin();
			ready_array[i].erase(it);
			break;
		}
	}
}
void list_all_process()
{
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		cout << it->pid << " " << it->priority << " " << it->status << endl;
	}
}
void list_all_resources()
{
	for (int i = 0; i < 4; i++)
	{
		cout << resource_list[i].rid << " " << resource_list[i].init_num << " " << resource_list[i].availa_num << endl;
	}
}
void list_all_blocked()
{
	for (int i = 3; i > 0; i--)
	{
		for (int j = 0; j < 20; j++)
		{
			if (blocked_array[i][j].pid != "hhj")
			{
				cout << blocked_array[i][j].pid << " " << blocked_array[i][j].priority << " " << blocked_array[i][j].status << endl;
			}
			else
			{
				break;
			}
		}
	}
}
void list_all_ready()
{
	for (int i = 3; i > 0; i--)
	{
		for (int j = 0; j < 20; j++)
		{
			if (ready_array[i][j].pid != "hhj")
			{
				cout << ready_array[i][j].pid << " " << ready_array[i][j].priority << " " << ready_array[i][j].status << endl;
			}
			else
			{
				break;
			}
		}
	}
}
pcb search_process_information(string pid)
{
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		if (it->pid == pid) {
			return *it;
		}
	}
	pcb new3;
	return new3;
}
int main()
{
	init_resource_list();
	ifstream fin2;
	string pathname = "C:/Users/12091/Desktop/11.txt";
	fin2.open(pathname);
	string command = "be";
	string pid_name;
	int pid_priority;
	pcb running_process, new_pcb, register_pcb;
	while (command != "exit")
	{
		running_process = search_process_information(running_pid);
		string rubbish;
		fin2 >> command;
		pcb _null;
		if (command == "cr")
		{
			fin2 >> pid_name >> pid_priority;
			getline(fin2, rubbish);
			create(pid_name, running_process, _null, pid_priority);
			new_pcb = search_process_information(pid_name);
			if (running_process.pid != "hhj")running_process.child = &new_pcb;
		}
		else if (command == "de")
		{
			fin2 >> pid_name;
			destory(pid_name);
		}
		else if (command == "to")
		{
			timeout();
		}
		else if (command == "req")
		{
			fin2 >> pid_name >> pid_priority;
			if (pid_name == "R1")
			{
				request(1, pid_priority);
			}
			else if (pid_name == "R2")
			{
				request(2, pid_priority);
			}
			else if (pid_name == "R3")
			{
				request(3, pid_priority);
			}
			else if (pid_name == "R4")
			{
				request(4, pid_priority);
			}
		}
		else if (command == "rel")
		{
			release1(running_pid);
		}
		else if (command == "lap")
		{
			list_all_process();
		}
		else if (command == "lar")
		{
			list_all_resources();
		}
		else if (command == "lrdy")
		{
			list_all_ready();
		}
		else if (command == "lab")
		{
			list_all_blocked();
		}
		else if(command=="exit")
		{
			return 0;
		}
		cout << running_pid << endl;
	}
}