#include<iostream>
#include"a.h"
 int main()
{
	int a =0;
	std::cout<<"Input the value to test gdb's value function:";
	std::cin>>a;
	if(a>20)
	{
		std::cout<<"a >20";
	}
	else
	{
		std::cout<<"a<=20";
	}
	test();
	//Test commit
	std::cout<<"hello world!\n";
	return 0;
}

