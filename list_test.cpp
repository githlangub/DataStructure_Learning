#include<iostream>
#include"../include/list.hpp"
#include"../include/seqlist.hpp"
#include"../include/linklist.hpp"
using namespace std;

int main()
{
	try   //异常处理是放在函数最后吗???
	{
		//SeqList<int> sl_1;
		LinkList<int> ll_1;
		List<int>* list_1=&ll_1;
		cout<<"Length="<<list_1->GetLength()<<endl;

		for(unsigned i=1;i<=25;i++)
			list_1->Insert(i,i);

		list_1->Delete(5);
		list_1->Set(-32767,1);
		list_1->Print();

		cout<<"End of main"<<endl;
	}
	catch(const bad_alloc& e)
	{
		cerr<<"Overflow!"<<endl;
	}
	catch(unsigned err_code)
	{
		switch(err_code)
		{
			case 1: cerr<<"Cannot insert here!"<<endl;
			case 2: cerr<<"Element does not exist, deleting failed!";
			case 3: cerr<<"No this element, rewrite failed!"<<endl;
			case 4: cerr<<"No this element!"<<endl;
			case 5: cerr<<"No this element, addressing failed!"<<endl;
		}
	}
	return 0;
}
