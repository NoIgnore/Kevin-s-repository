#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
struct string_type
{
	string a = "0";
	string_type* next = nullptr;
};
int main()
{
	ifstream ifs("1234.txt");
	ofstream ofs("1234_.txt");
	string line;
	string abc;
	string_type* new_1 = new string_type;
	string_type* head_2 = new string_type;
	head_2 = new_1;
	for (int i = 0; i < 5; i++)
	{
		getline(ifs, line);
		string_type* process = new string_type;
		process->a = line;
		head_2->next = process;
		head_2 = head_2->next;
		cout << head_2->a << endl;
		line += " ";
		ofs << line;
	}
	line = "\n";
	ofs << line;
	for (int i = 0; i < 12; i++) 
	{
		getline(ifs, line);
		string_type* process = new string_type;
		process->a = line;
		head_2->next = process;
		head_2 = head_2->next;
		cout << head_2->a << endl;
		line += " ";
		ofs << line;
	}
	line = "\n";
	ofs << line;
	return 0;
}
