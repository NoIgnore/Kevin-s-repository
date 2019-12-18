//#include "pch.h"//这个写在最前头，FUCK！
#include<iostream>
#include"my_dll.h"

extern "C" {
void WHYCAN_T::hello()
{
	std::cout << "Hello,this is my dll ^_^" << std::endl;
}
}

