#include <iostream>
extern "C" __declspec(dllimport) void Go();
int main (int argc, char **argv)
{
	Go();
	return 0;
}
