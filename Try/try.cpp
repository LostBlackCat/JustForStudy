#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdexcept>
#include<exception>
void terminate_handle()
{
	std::cerr << "Terminalte.\n;";
}
class A
{
public:
	A();
	~A();
	explicit A(int);
	int data;
private:
};

A::A()
{
}

A::~A()
{
}
class B :public A
{
public:
	B();
	B(int);
	~B();

private:

};

B::B()
{
}

B::B(int a)
{
	A::data = a;

}
B::~B()
{
}
int main()
{
	using std::fstream;
	using std::cout;
	using std::cin;
	//cout << std::right << std::setw(10) << 'T';
	//fstream a;
	//a.open("a.txt",std::ios::out|std::ios::in/*|std::ios::app*/);
	//if (!a)
	//{
	//	return 0;
	//}
	//a << "Test\n";
	//cout << !a;
	//a.seekg(2);
	//a.seekg(3,std::ios::beg);
	//a.seekg(-2, std::ios::cur);
	//char * b=new char[100];
	//a >> b;
	//cout << std::endl<<b;
	std::set_new_handler(terminate_handle);
	std::exception expA{"expAAA"};
	//cout << expA.what();
	std::runtime_error::exception rteA;
	set_terminate(terminate_handle);
	try
	{
		throw(B(1));
		throw(expA);
		
	}
	catch (A  & a)
	{
		std::cout << "A called\n";
	}
	catch (std::exception &exp)
	{
		std::cout << exp.what();
	}
	
	return 0;
}
