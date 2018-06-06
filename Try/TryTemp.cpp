#include<iostream>
class TestA
{
public:
	TestA() 
	{
		data = 0;
	}
	TestA(int a)
	{
		data = a;
	}
	operator int()const
	{
		return this->data;
	}
private:
	int data;
};
int a(TestA a)
{
	return 0;
}
int getMain()
{
	TestA aaaa;
	a(0);
	std::cout << static_cast<int>(aaaa);
	return 0;
}