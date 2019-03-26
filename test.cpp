#include<iostream>
using namespace std;

class A
{};
class B:public A
{};
class C:public B
{};
int main()
{
	A* pA=new C;
	return 0;
}
