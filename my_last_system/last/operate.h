#pragma once
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct pcb//���̽ṹ��
{
	string pid = "hhj";
	int status = 0;//blocked 1, ready 2, running 3
	vector<string> child;
	string parent = "hhj";
	int priority = 0;//0-init,1-user,2-system
	int resource_occupied[4] = { 0 }; //��ǰռ��������Դ��
	int blocked_resc_type = 0;//����������Դ����������ͣ�1��2��3��4
};
struct rcb//��Դ�ṹ��
{
	int rid = 0;//��Դ��
	int init_num = 0;//��Դ��ʼ��
	int availa_num = 0;//��Դ���ڿ��õ�����
	rcb* next = nullptr;
};
vector<pcb> all_process_list;//��¼���еĽ�����Ϣ
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
		a.init_num = i + 1; //4����Դ��R1��R2��R3��R4��ÿ����ԴRi��i��
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
	if (child != "hhj")a.child.push_back(child);
	for (vector<pcb>::iterator it7 = all_process_list.begin(); it7 != all_process_list.end(); it7++)
	{
		if (it7->pid == parent)
		{
			it7->child.push_back(pid);
		}
	}
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
		if (num[2] == 0)//���������ȼ�û��ready����
		{
			if (running_pid == "hhj")//���runningΪ��
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
		if (num[2] == 0 && num[1] == 0)//���������ȼ���ready����
		{
			if (running_pid == "hhj")//���runningΪ��
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
		if (num[2] == 0 && num[1] == 0 && num[0] == 0)//���������ȼ���ready����
		{
			if (running_pid == "hhj")//���runningΪ��
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
	if (running_pid == pid)running_pid = "hhj";//����������е�ģ���PIDֵ����Ҫɾ����ģ���PIDֵ��������״̬Ϊ��
	vector<pcb>::iterator it3 = all_process_list.begin();
	while (all_process_list.size() != 0 && it3 != all_process_list.end())
	{
		int uu = 0;
		pcb a;
		if (it3->pid == pid)
		{
			a = *it3;
			if (a.child.size() != 0)
			{
				for (int i = 0; i < a.child.size(); i++)
				{
					if (a.child[i] != "hhj")destory(a.child[i]);
				}
			}
			uu = 1;
		}
		if (uu == 1)
		{
			for (vector<pcb>::iterator it4 = all_process_list.begin(); it4 != all_process_list.end(); it4++)
			{
				if (it4->pid == pid)
				{
					if (it4->child.size() != 0)
					{
						int register1 = it4->child.size();
						for (int i = 0; i < register1; i++)
						{
							it4->child.pop_back();
						}
					}
					all_process_list.erase(it4);
					return;
				}
			}
		}
		it3++;
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