#include <iostream>
#include "operate.h"
using namespace std;
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
			if (running_process.pid != "NoProcess")running_process.child.push_back(new_pcb.pid);
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
		running_pid == "NoProcess" ? cout << "No process is running" << endl : cout << running_pid << endl;
	}
}