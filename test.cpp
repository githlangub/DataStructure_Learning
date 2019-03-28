#include<iostream>
using namespace std;
class A;
class B
{
	public:
		void func1()
		{
			a.print();
		}
		A a;
	private:
		int b=2;
};
class A
{
	public:
		void print(void)
		{
			cout<<B::b<<endl;
		}
};
int main()
{
	B B1;
	B1.func1();
	return 0;
}
