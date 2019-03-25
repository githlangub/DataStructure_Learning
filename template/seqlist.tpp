#ifndef _SEQLIST_TPP
#define _SEQLIST_TPP

#include<iostream>
#include"../include/seqlist.hpp"

#define LIST_INIT_SIZE 100
#define LIST_INCREASE 50



template<typename ElemType>
SeqList<ElemType>::SeqList(void)
{
	//分配空间
	this->elem=new ElemType[LIST_INIT_SIZE];   //异常点

	//初始化
	this->len=0;
	this->listsize=LIST_INIT_SIZE;

	std::cout<<"SqList initial success!"<<std::endl;
}



template<typename ElemType>
SeqList<ElemType>::~SeqList()
{
	//释放空间
	delete[] this->elem;

	std::cout<<"SqList destroyed!"<<std::endl;
}



template<typename ElemType>
void SeqList<ElemType>::ListClear(void)
{
	this->len=0;
}



template<typename ElemType>
void SeqList<ElemType>::ElemInsert(ElemType elem,unsigned pos)
{
	//检查pos是否为合法值
	if(pos<1||pos>this->len+1)
	{
		unsigned err_code=1;
		throw err_code;   //异常点1
	}
	
	//检查是否长度到达上限
	if(this->len==this->listsize)   
	{
		//分配新空间
		ElemType* newbase=new ElemType[listsize+LIST_INCREASE];
		this->listsize+=LIST_INCREASE;

		//旧内容复制到新空间
		for(int i=0;i<pos-1;i++)
			newbase[i]=this->elem[i];
		newbase[pos-1]=elem;
		for(int i=pos-1;i<this->len;i++) 
			newbase[i+1]=this->elem[i];

		//指向新空间
		this->elem=newbase;
	}
	else
	{
		//pos位置开始所有元素往后移一位
		for(int i=this->len;i>=pos;i--)   //此处巨坑,int和unsigned混用有问题
			this->elem[i]=this->elem[i-1];
		this->elem[pos-1]=elem;
	}

	//总长度加一
	this->len+=1;
}



template<typename ElemType>
void SeqList<ElemType>::ElemDelete(unsigned pos)
{
	//检查pos合法性
	if(pos<1||pos>this->len)
	{
		unsigned err_code=2;   //异常点2
		throw err_code;
	}

	//从pos+1开始,元素往前移动一位
	for(int i=pos-1;i<=(this->len-1)-1;i++)
	{
		this->elem[i]=this->elem[i+1];
	}

	//总长度减一
	this->len-=1;
}

	
	
template<typename ElemType>
void SeqList<ElemType>::ElemSet(ElemType elem,unsigned pos)
{
	//检查pos合法性
	if(pos<1||pos>this->len)
	{
		unsigned err_code=3;
		throw err_code;   //异常点3
	}

	//赋值
	this->elem[pos-1]=elem;
}

	
	
template<typename ElemType>
ElemType SeqList<ElemType>::ElemGet(unsigned pos)
{
	//检查pos是否合法
	if(pos<1||pos>this->len)
	{
		unsigned err_code=4;
		throw err_code;   //异常点4
	}
	return this->elem[pos-1];
}

	
	
template<typename ElemType>
void SeqList<ElemType>::ListPrint(void)
{
	for(int i=1;i<=this->GetLength();i++)
	{
		std::cout<<this->ElemGet(i)<<std::endl;
	}

	//能否用<<控制符控制,或利用重载???
}

#endif

