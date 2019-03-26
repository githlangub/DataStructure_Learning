#ifndef _STACK_TPP
#define _STACK_TPP

#include<iostream>
#include"../include/stack.hpp"
#include"../include/linklist.hpp"

template<typename ElemType>
Stack<ElemType>::Stack(void)
{
	this->data=new LinkList<ElemType>;   //创建一个线性表以存放数据
	this->len=0;   //长度置零

	std::cout<<"A stack has been created!"<<std::endl;
}



template<typename ElemType>
Stack<ElemType>::~Stack(void)
{
	delete this->data;   //释放存储空间

	std::cout<<"The stack has been destroyed!"<<std::endl;
}



template<typename ElemType>
void Stack<ElemType>::Clear(void)
{
	this->data->Clear();   //清空存储空间
	len=0;   //长度置0零
}

template<typename ElemType>
void Stack<ElemType>::Push(ElemType elem)
{
	this->data->Insert(elem,this->len+1);   //表尾插入
	this->len++;   //长度加一
}



template<typename ElemType>
ElemType Stack<ElemType>::Pop(void)
{
	//判断是否为空栈
	if(this->len)
	{
		ElemType elem=this->data->Get(len);
		this->data->Delete(this->len);   //删除表尾
		this->len--;   //长度减一
		return elem;
	}
	else
	{
		unsigned err_code{1};   //异常点1
		throw err_code;
	}
}



template<typename ElemType>
ElemType Stack<ElemType>::GetTop(void)
{
	//判断是否为空栈
	if(this->len)
	{
		return this->data->Get(this->len);   //返回表尾
	}
	else
	{
		unsigned err_code{2};   //异常点2
		throw err_code;
	}
}



template<typename ElemType>
void Stack<ElemType>::Print(void)
{
	//判断是否为空栈
	if(this->len)
	{
		this->data->Print();   //遍历输出
	}
	else
	{
		unsigned err_code{3};   //异常点3
		throw err_code;
	}
}



template<typename ElemType>
inline
	unsigned Stack<ElemType>::GetLength(void)
{
	return len;
}



template<typename ElemType>
inline
	bool Stack<ElemType>::IsEmpty(void)
{
	return !len;
}

#endif
