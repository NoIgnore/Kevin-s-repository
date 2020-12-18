#pragma once
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct pcb//进程结构体
{
	string pid = "NoProcess";
	int status = 0;//blocked 1, ready 2, running 3
	vector<string> child;
	string parent = "NoProcess";
	int priority = 0;//0-init,1-user,2-system
	int resource_occupied[4] = { 0 }; //当前占有四类资源数
	int blocked_resc_type = 0;//引起阻塞资源的种类的类型：1，2，3，4
};
struct rcb//资源结构体
{
	int rid = 0;//资源号
	int init_num = 0;//资源初始数
	int availa_num = 0;//资源现在可用的数量
};
vector<pcb> all_process_list;//记录所有的进程信息
vector<vector<pcb>> ready_array(3, vector<pcb>(20));//0-init,1-user,2-system
vector<vector<pcb>> blocked_array(3, vector<pcb>(20));//0-init,1-user,2-system
vector<rcb> resource_list;
string running_pid = "NoProcess";
void information_ouccupy(pcb a)
{
	cout << a.resource_occupied[0] << " " << a.resource_occupied[1] << " " << a.resource_occupied[2] << " " << a.resource_occupied[3] << endl;
}
void init_resource_list()
{
	for (int i = 0; i < 4; i++)
	{
		rcb a;//定义资源R
		a.rid = i + 1;//定义资源Ri
		a.init_num = i + 1; //4类资源，R1，R2，R3，R4，每类资源Ri有i个
		a.availa_num = a.init_num;//初始化时可用数等于分配数
		resource_list.push_back(a);//将每个资源压入总资源vector队列
	}
	cout << "init" << endl;
}
void create(string pid, string parent, string child, int priority)//创建进程的操作
{
	pcb a;
	a.pid = pid;
	a.priority = priority;
	a.parent = parent;
	if (child != "NoProcess")a.child.push_back(child);
	for (vector<pcb>::iterator it7 = all_process_list.begin(); it7 != all_process_list.end(); it7++)
	{//将创建的进程压入其父进程的子节点的队列中
		if (it7->pid == parent)
		{
			it7->child.push_back(pid);
		}
	}
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{//不能重复创建相同的进程
		if (a.pid == it->pid)
		{
			cout << "Don't create the process which is created before!" << endl;
			return;
		}
	}
	int num[3] = { 0 };
	for (int i = 2; i >= 0; i--)
	{//统计各个优先级的进程数量
		for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
		{
			if (it->pid != "NoProcess")
			{
				num[i]++;
			}
		}
	}
	switch (a.priority)
	{
	case 2://最高优先级
		if (num[2] == 0)//如果最高优先级没有ready进程
		{
			if (running_pid == "NoProcess")//如果running为空
			{
				running_pid = a.pid;//当前进程即为运行中
				a.status = 3;
			}
			else//否则就压入当前优先级的就绪队列
			{
				a.status = 2;
				ready_array[a.priority].push_back(a);
			}
		}
		else//否则就压入当前优先级的就绪队列
		{
			a.status = 2;
			ready_array[a.priority].push_back(a);
		}
		break;
	case 1://中等优先级
		if (num[2] == 0 && num[1] == 0)//如果前两个优先级都没有有ready进程
		{
			if (running_pid == "NoProcess")//如果running为空
			{
				running_pid = a.pid;//当前进程即为运行中
				a.status = 3;
			}
			else//否则就压入当前优先级的就绪队列
			{
				a.status = 2;
				ready_array[a.priority].push_back(a);
			}
		}
		else//否则就压入当前优先级的就绪队列
		{
			a.status = 2;
			ready_array[a.priority].push_back(a);
		}
		break;
	case 0:
		if (num[2] == 0 && num[1] == 0 && num[0] == 0)//如果3个优先级都没有ready进程
		{
			if (running_pid == "NoProcess")//如果running为空
			{
				running_pid = a.pid;//当前进程即为运行中
				a.status = 3;
			}
			else//否则就压入当前优先级的就绪队列
			{
				a.status = 2;
				ready_array[a.priority].push_back(a);
			}
		}
		else//否则就压入当前优先级的就绪队列
		{
			a.status = 2;
			ready_array[a.priority].push_back(a);
		}
		break;
	}
	all_process_list.push_back(a);
}
void release(string pid)
{
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		if (it->pid == pid)
		{
			for (int i = 0; i < 4; i++)//将每类占用的资源放回可用资源列表中然后清零
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
			if (it2->blocked_resc_type != 0)//如果阻塞类型非零
			{
				int num1 = it2->blocked_resc_type;
				if (it2->resource_occupied[num1 - 1] <= resource_list[num1 - 1].availa_num)
				{//若阻塞的进程所请求的资源数小于可用资源则将其分配进就绪队列里
					it2->status = 2;
					resource_list[num1 - 1].availa_num -= it2->resource_occupied[num1 - 1];
					it2->blocked_resc_type = 0;
					pcb hhh = *it2;
					for (vector<pcb>::iterator it3 = all_process_list.begin(); it3 != all_process_list.end(); it3++)
					{//在记录所有进程的列表中更新该进程信息
						if (it3->pid == it2->pid)
						{
							*it3 = hhh;
							break;
						}
					}
					ready_array[hhh.priority].push_back(hhh);//压入就绪队列
					blocked_array[i].erase(it2);//阻塞队列中删除该信息
					it2 = blocked_array[i].begin();//指针重新指向开头判断是否循环
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
	release(pid);//释放该进程的资源
	for (int i = 0; i < 3; i++)//若在就绪队列中删除信息
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
	for (int i = 0; i < 3; i++)//若在阻塞队列中则删除信息
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
	if (running_pid == pid)running_pid = "NoProcess";//如果正在运行的模块的PID值等于要删除的模块的PID值，则运行状态为空
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
					if (a.child[i] != "NoProcess")destory(a.child[i]);//递归删除子节点
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
							it4->child.pop_back();//删除该进程的子节点信息
						}
					}
					all_process_list.erase(it4);//从所有进程的列表中擦除该进程
					return;
				}
			}
		}
		it3++;
	}
}
void request(int rid, int num)//进程对资源的请求函数
{
	pcb runningman;//定义局部的正在运行的进程
	if (running_pid == "NoProcess")
	{
		cout << "No process is running! Can't request! Please at least create a process firstly!" << endl;
		return;//如果没有进程正在运行，则无法请求资源
	}
	if (resource_list[rid - 1].availa_num < num)//如果剩余的资源不够
	{
		for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
		{
			if (it->pid == running_pid)
			{
				runningman = *it;
				break;
			}
		}
		runningman.blocked_resc_type = rid;//写入导致阻塞的资源种类
		runningman.resource_occupied[rid - 1] += num;
		runningman.status = 1;//状态blocked=1
		blocked_array[runningman.priority].push_back(runningman);//将当前进程装入阻塞队列
		int num[3] = { 0 };
		for (int i = 2; i >= 0; i--)
		{
			for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
			{
				if (it->pid != "NoProcess")
				{
					num[i]++;
				}
			}
		}
		if (num[0] == 0 && num[1] == 0 && num[2] == 0)running_pid = "NoProcess";//如果就绪队列没有进程
		else
		{
			for (int i = 2; i >= 0; i--)//由优先级最高的就绪队列里逐一寻找非空进程
			{
				int uu = 0;
				for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
				{
					if (it->pid != "NoProcess")
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
	else//如果剩余的资源足够
	{
		for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
		{
			if (it->pid == running_pid)
			{
				it->resource_occupied[rid - 1] += num;//该进程占用资源量要加上请求量
				resource_list[rid - 1].availa_num -= num;//资源列表减少相应的请求量
			}
		}
	}
}
void timeout()
{
	pcb runningman;
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		if (it->pid == running_pid)//将全局变量的运行进程的pid赋予局部函数的runningman变量
		{
			it->status = 2;//将当前正在运行的进程状态转换为就绪状态
			runningman = *it;
			break;
		}
	}
	ready_array[runningman.priority].push_back(runningman);//压入就绪队列
	for (int i = 2; i >= 0; i--)
	{
		for (vector<pcb>::iterator it = ready_array[i].begin(); it != ready_array[i].end(); it++)
		{//就绪队列从最高优先级依次指向，将第一个进程转换为运行状态并在就绪队列中删除该信息
			if (it->pid != "NoProcess")
			{
				it->status = 3;
				running_pid = it->pid;
				ready_array[i].erase(it);
				for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
				{
					if (it->pid == running_pid)//将全局变量的运行进程的pid赋予局部函数的runningman变量
					{
						it->status = 3;//将当前就绪状态的进程转换为正在运行
						break;
					}
				}
				return;
			}
		}
	}
}
void list_all_process()//所有进程列表的查看函数
{
	cout << "list_all_process:  " << endl;
	for (vector<pcb>::iterator it = all_process_list.begin(); it != all_process_list.end(); it++)
	{
		cout << it->pid << " " << it->priority << " " << it->status << "----";
		information_ouccupy(*it);
	}
}
void list_all_resources()//资源列表的查看函数
{
	cout << "list all resouces:   " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << resource_list[i].rid << " init_num: " << resource_list[i].init_num << " availa_num: " << resource_list[i].availa_num << endl;
	}
}
void list_all_blocked()//该函数列出所有阻塞队列
{
	cout << "list all blocked process:   " << endl;
	for (int i = 2; i >= 0; i--)//优先级从高到低
	{
		for (vector<pcb>::iterator it = blocked_array[i].begin(); it != blocked_array[i].end(); it++)
		{
			if (it->pid != "NoProcess")
			{
				cout << it->pid << " priority: " << it->priority << " status: " << it->status << "----";
				information_ouccupy(*it);//输出进程详细信息的函数
				cout << "blocked-type is: " << it->blocked_resc_type << endl;//列出阻塞资源的类型
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
			if (it->pid != "NoProcess")
			{
				cout << it->pid << " priority: " << it->priority << " status: " << it->status << "----";
				information_ouccupy(*it);//输出进程详细信息的函数
			}
		}
	}
}