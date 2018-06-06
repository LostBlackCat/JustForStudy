#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdexcept>
#include<exception>
class C
{
public:
	C();
private:
	static double cDblA;
};
C::C()
{
	std::cout << cDblA;
}
double C::cDblA = 223.34;
template<typename T>
class B;
int fun()
{
	return 0;
}
void terminate_handle()
{
	std::cerr << "Terminalte.\n;";
}
template<typename T>
class A;
template <typename T=double>
class A
{
public:
	A();
	~A();
	explicit A(int);
	friend class c;
	friend  B<double>;
	friend int fun();
	int data;
private:
	T temp;
	const char cChr = 'a';
	const static double csChrA;
};
template <typename T>
const double A<T>::csChrA = 'a';
template<typename T>
A<T>::A()
{
	std::cout << cChr<<std::endl;
	std::cout << A::csChrA;
}
template<typename T>
A<T>::~A()
{
}
template <>
class A<int>
{
public:
	A();
	~A();
	int data;

private:

};

A<int>::A()
{
}


A<int>::~A()
{
}

template<typename T>
class B :public A<T>
{
public:
	B();
	B(int);
	~B();

private:

};
template<typename T>

B<T>::B()
{
}
template<typename T>

B<T>::B(int a)
{
	A<int>::data = a;

}
template<typename T>
B<T>::~B()
{
}
template <typename T>
T add(T a, T b)
{
	std::cout << "Template called.\n";
	return a + b;
}

int add(int a, int b)
{
	return a + b;
}
int getMain();
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	if (true)
	{
		getMain();
		return 0;
	}
	using std::fstream;
	using std::cout;
	using std::cin;
	C aaa;
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
	int * intArr = new int[10];
	intArr++;
	delete --intArr;
	add(2, 3);
	std::set_new_handler(terminate_handle);
	std::exception expA{"expAAA"};
	//cout << expA.what();
	std::runtime_error::exception rteA;
	set_terminate(terminate_handle);
	A<double> dblAa;
	try
	{
		throw(B<int>(1));
		throw(expA);
		
	}
	catch (A<int>  & )
	{
		std::cout << "A called\n";
	}
	catch (std::exception &exp)
	{
		std::cout << exp.what();
	}
	return 0;
}
