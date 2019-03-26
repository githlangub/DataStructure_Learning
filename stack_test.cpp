#include<iostream>
#include"../include/stack.hpp"
using namespace std;

int main()
{
	Stack<int> stack_1;
	Stack<int>* pS=&stack_1;
	cout<<"Length is "<<pS->GetLength()<<endl;

	for(int i=1;i<=10;i++)
	{
		pS->Push(i);
	}
	pS->Print();
	cout<<"Length is "<<pS->GetLength()<<endl;
	for(int i=1;i<=10;i++)
	{
		cout<<pS->Pop()<<endl;
	}

	return 0;
}
