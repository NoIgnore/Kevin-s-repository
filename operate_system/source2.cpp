#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct pcb//进程结构体
{
	string pid = "hhj";
	int status = 0;//blocked 1, ready 2, running 3
	vector<string> child;
	string parent = "hhj";
	int priority = 0;//0-init,1-user,2-system
	int resource_occupied[4] = { 0 }; //当前占有四类资源数
	int blocked_resc_type = 0;//引起阻塞资源的种类的类型：1，2，3，4
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
string running_pid = "hhj";
void information_ouccupy(pcb a)
{
	cout << a.resource_occupied[0] << " " << a.resource_occupied[1] << " " << a.resource_occupied[2] << " " << a.resource_occupied[2] << endl;
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
	cout << "init" << endl;
}
void create(string pid, string parent, string child, int priority)
{
	pcb a;
	a.pid = pid;
	a.priority = priority;
	a.parent = parent;
	a.child.push_back(child);
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		if (a.pid == it->pid)
		{
			cout << "Don't create the process which is created before!" << endl;
			return;
		}
	}
	int num[3] = { 0 };
	for (int i = 2; i >= 0; i--)
	{
		for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
		{
			if (it->pid != "hhj")
			{
				num[i]++;
			}
		}
	}
	switch (a.priority)
	{
	case 2:
		if (num[2] == 0)//如果最高优先级没有ready进程
		{
			if (running_pid == "hhj")//如果running为空
			{
				running_pid = a.pid;
				a.status = 3;
			}
			else
			{
				a.status = 2;
				ready_array[a.priority].push_back(a);
			}
		}
		else
		{
			a.status = 2;
			ready_array[a.priority].push_back(a);
		}
		break;
	case 1:
		if (num[2] == 0 && num[1] == 0)//如果最高优先级有ready进程
		{
			if (running_pid == "hhj")//如果running为空
			{
				running_pid = a.pid;
				a.status = 3;
			}
			else
			{
				a.status = 2;
				ready_array[a.priority].push_back(a);
			}
		}
		else
		{
			a.status = 2;
			ready_array[a.priority].push_back(a);
		}
		break;
	case 0:
		if (num[2] == 0 && num[1] == 0 && num[0] == 0)//如果最高优先级有ready进程
		{
			if (running_pid == "hhj")//如果running为空
			{
				running_pid = a.pid;
				a.status = 3;
			}
			else
			{
				a.status = 2;
				ready_array[a.priority].push_back(a);
			}
		}
		else
		{
			a.status = 2;
			ready_array[a.priority].push_back(a);
		}
		break;
	}
	all_process_list.push_back(a);
}
pcb release(string pid)
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
	for (int i = 2; i >= 0; i--)
	{
		vector<pcb>::iterator it2 = blocked_array[i].begin();
		while (blocked_array[i].size() != 0 && it2 != blocked_array[i].end())
		{
			if (it2->blocked_resc_type != 0)
			{
				int num1 = it2->blocked_resc_type;
				if (it2->resource_occupied[num1 - 1] <= resource_list[num1 - 1].availa_num)
				{
					it2->status = 2;
					resource_list[num1 - 1].availa_num -= it2->resource_occupied[num1 - 1];
					pcb hhh = *it2;
					ready_array[hhh.priority].push_back(hhh);
					blocked_array[i].erase(it2);
					it2 = blocked_array[i].begin();
				}
				else
				{
					it2++;
				}
			}
			else
			{
				it2++;
			}
		}
	}
	return a;
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
void deletechild(string pid)
{
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		if (it->pid == pid)
		{
			for (vector<string>::iterator it2 = it->child.begin(); it2 != it->child.end(); it2++)
			{
				if (*it2 == pid)
				{
					it->child.erase(it2);
					return;
				}
			}
		}
	}
}
void destory(string pid)
{
	pcb a = release(pid);
	for (int i = 0; i < 3; i++)
	{
		int uu = 0;
		for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
		{
			if (it->pid == pid)
			{
				ready_array[i].erase(it);
				uu = 1;
				break;
			}
		}
		if (uu == 1)break;
	}
	for (int i = 0; i < 3; i++)
	{
		int uu = 0;
		for (vector<pcb>::iterator it = blocked_array[i].begin(); it != blocked_array[i].end(); it++)
		{
			if (it->pid == pid)
			{
				blocked_array[i].erase(it);
				uu = 1;
				break;
			}
		}
		if (uu == 1)break;
	}
	if (running_pid == pid)running_pid = "hhj";//如果正在运行的模块的PID值等于要删除的模块的PID值，则运行状态为空
	/*for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		if (it->pid == pid)
		{
			if (it->parent != "hhj")it->parent = "hhj";
			vector<string>::iterator it2 = it->child.begin();
			if (it->child.size() != 0)
			{
				for (int i = 0; i < it->child.size(); i++)
				{
					destory(it->child[i]);
				}
			}
			all_process_list.erase(it);
			return;
		}
	}*/
	vector<pcb>::iterator it3 = all_process_list.begin();
	while (all_process_list.size() != 0 && it3 != all_process_list.end())
	{
		if (it3->pid == pid)
		{
			if (it3->parent != "hhj")deletechild(it3->parent);
			vector<string>::iterator it2 = it3->child.begin();
			if (it3->child.size() != 0)
			{
				for (int i = 0; i < it3->child.size(); i++)
				{
					destory(it3->child[i]);
				}
			}
		}
		vector<pcb>::iterator it3 = all_process_list.begin();
		if (it3->pid == pid)
		{
			all_process_list.erase(it3);
			return;
		}
	}
}
void request(int rid, int num)
{
	pcb runningman;
	if (running_pid == "hhj")
	{
		cout << "No process is running! Can't request! Please at least create a process firstly!" << endl;
		return;
	}
	if (resource_list[rid - 1].availa_num < num)
	{
		//cout << "Not enough resource" << endl;
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
		int num[3] = { 0 };
		for (int i = 2; i >= 0; i--)
		{
			for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
			{
				if (it->pid != "hhj")
				{
					num[i]++;
				}
			}
		}
		if (num[0] == 0 && num[1] == 0 && num[2] == 0)running_pid = "hhj";
		else
		{
			for (int i = 2; i >= 0; i--)
			{
				int uu = 0;
				for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
				{
					if (it->pid != "hhj")
					{
						it->status = 3;
						running_pid = it->pid;
						ready_array[i].erase(it);
						uu = 1;
						break;
					}
				}
				if (uu == 1)break;
			}
		}
	}
	else
	{
		for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
		{
			if (it->pid == running_pid)
			{
				it->resource_occupied[rid - 1] += num;
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
	runningman.status = 2;
	ready_array[runningman.priority].push_back(runningman);
	for (int i = 2; i >= 0; i--)
	{
		for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
		{
			if (it->pid != "hhj")
			{
				it->status = 3;
				running_pid = it->pid;
				ready_array[i].erase(it);
				return;
			}
		}
	}
}
void list_all_process()
{
	cout << "list_all_process:  " << endl;
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		cout << it->pid << " " << it->priority << " " << it->status << "----";
		information_ouccupy(*it);
	}
}
void list_all_resources()
{
	cout << "list all resouces:   " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << resource_list[i].rid << " init_num: " << resource_list[i].init_num << " availa_num: " << resource_list[i].availa_num << endl;
	}
}
void list_all_blocked()
{
	cout << "list all blocked process:   " << endl;
	for (int i = 2; i >= 0; i--)
	{
		for (vector<pcb>::iterator it = blocked_array[i].begin(); it != blocked_array[i].end(); it++)
		{
			if (it->pid != "hhj")
			{
				cout << it->pid << " priority: " << it->priority << " status: " << it->status << "----";
				information_ouccupy(*it);
				cout << "blocked-type is: " << it->blocked_resc_type << endl;
			}
		}
	}
}
void list_all_ready()
{
	cout << "list all ready process:   " << endl;
	for (int i = 2; i >= 0; i--)
	{
		for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
		{
			if (it->pid != "hhj")
			{
				cout << it->pid << " priority: " << it->priority << " status: " << it->status << "----";
				pcb hhj2 = *it;
				cout << endl << "hhj2_pid: " << hhj2.pid;
				information_ouccupy(*it);
			}
		}
	}
}

int main()
{
	init_resource_list();
	ifstream fin2;
	string pathname = "C:/Users/12091/Desktop/11.txt";
	fin2.open(pathname);
	string command = "be";
	string pid_name, re_name;
	int pid_priority, need_r_num;
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
			create(pid_name, running_process.pid, _null.pid, pid_priority);
			new_pcb = search_process_information(pid_name);
			if (running_process.pid != "hhj")running_process.child.push_back(new_pcb.pid);
		}
		else if (command == "de")
		{
			fin2 >> pid_name;
			getline(fin2, rubbish);
			destory(pid_name);
		}
		else if (command == "to")
		{
			getline(fin2, rubbish);
			timeout();
		}
		else if (command == "req")
		{
			fin2 >> re_name >> need_r_num;
			getline(fin2, rubbish);
			if (re_name == "R1")
			{
				request(1, need_r_num);
			}
			else if (re_name == "R2")
			{
				request(2, need_r_num);
			}
			else if (re_name == "R3")
			{
				request(3, need_r_num);
			}
			else if (re_name == "R4")
			{
				request(4, need_r_num);
			}
		}
		else if (command == "rel")
		{
			fin2 >> pid_name;
			getline(fin2, rubbish);
			release(pid_name);
		}
		else if (command == "lap")
		{
			getline(fin2, rubbish);
			list_all_process();
		}
		else if (command == "lar")
		{
			getline(fin2, rubbish);
			list_all_resources();
		}
		else if (command == "lrdy")
		{
			getline(fin2, rubbish);
			list_all_ready();
		}
		else if (command == "lab")
		{
			getline(fin2, rubbish);
			list_all_blocked();
		}
		else if (command == "exit")
		{
			cout << "exit!!!" << endl;
			return 0;
		}
		//cout << running_pid << " is running..." << endl;
		cout << running_pid << endl;
	}
}