#ifndef _LINKLIST_TPP
#define _LINKLIST_TPP

#include<iostream>
#include"../include/linklist.hpp"
#include"node.tpp"

template<typename ElemType>
LinkList<ElemType>::LinkList(void)
{
	//添加头节点，长度置零
	head=tail=new Node<ElemType>;
	this->len=0;

	std::cout<<"Linklist successfully initial!"<<std::endl;
}

	
	
template<typename ElemType>
LinkList<ElemType>::~LinkList()
{
	//从头节点开始迭代释放空间
	Node<ElemType>* prev=this->head;
	Node<ElemType>* next=NULL;
	head=tail=NULL;   //头尾指针回收
	do
	{
		next=prev->GetNext();
		delete prev;
		prev=next;
	}while(prev);

	std::cout<<"Linklist destroyed!"<<std::endl;
}

	
	
template<typename ElemType>
void LinkList<ElemType>::Clear(void)
{
	//从第一个节点开始迭代释放空间
	Node<ElemType>* prev=this->head->GetNext();
	Node<ElemType>* next;
	while(prev)
	{
		next=prev->GetNext();
		delete prev;
		prev=next;
	}

	//长度置零
	this->len=0;

	//尾指针指向头节点
	this->tail=this->head;

	std::cout<<"Linklist has been clear!"<<std::endl;
}

	
	
template<typename ElemType>
void LinkList<ElemType>::Insert(ElemType elem,unsigned pos)
{
	//检查pos合法性
	if(pos<1||pos>this->len+1)
	{
		unsigned err_code{1};
		throw err_code;   //异常点1
	}

	//开辟新节点
	Node<ElemType>* newnode=new Node<ElemType>{elem};

	//取得前节点地址
	Node<ElemType>* prior=this->LocateAddr(pos-1);

	//后节点断开连到新节点上
	newnode->LinkNext(prior->RemoveNext());

	//新节点连到前节点上
	prior->LinkNext(newnode);

	//若在最后插入，则尾指针指向新节点
	if(pos==this->len+1)
		this->tail=newnode;

	//总长度加一
	this->len++;
}

	
	
template<typename ElemType>
void LinkList<ElemType>::Delete(unsigned pos)
{
	//检查pos合法性
	if(pos<1||pos>this->len)
	{
		unsigned err_code=2;
		throw err_code;   //异常点2
	}

	//前节点与当前节点断开，并释放当前节点
	Node<ElemType>* last=this->LocateAddr(pos-1);   //前趋节点地址
	Node<ElemType>* next=last->GetNext()->GetNext();   //后继节点地址
	delete last->RemoveNext();   //释放当前节点

	//前趋节点与后继节点连接
	last->LinkNext(next);

	//若删除最后一个节点，则尾指针指向前一个节点
	if(pos==this->len)
		this->tail=last;

	//总长度减一
	this->len--;
}



template<typename ElemType>
void LinkList<ElemType>::Set(ElemType elem,unsigned pos)
{
	this->LocateAddr(pos)->DataWrite(elem);
}



template<typename ElemType>
ElemType LinkList<ElemType>::Get(unsigned pos)
{
	return this->LocateAddr(pos)->DataRead();
}



template<typename ElemType>
void LinkList<ElemType>::Print(void)
{
	//从第一个节点开始迭代输出
	Node<ElemType>* prev=this->head->GetNext();
	while(prev)
	{
		std::cout<<prev->DataRead()<<std::endl;
		prev=prev->GetNext();
	}
}

	
	
template<typename ElemType>
Node<ElemType>* LinkList<ElemType>::LocateAddr(unsigned pos)
{
	//检查pos合法性
	if(pos<0||pos>this->len)
	{
		unsigned err_code{5};
		throw err_code;
	}

	//寻址优化
	if(pos==this->len)
		//若在最后插入，直接返回尾指针
		return this->tail;
	else
	{
		//通过迭代取得地址
		Node<ElemType>* prev=this->head;
		for(unsigned count=0;count!=pos;count++)
		{
			prev=prev->GetNext();
		}
	
		//返回地址
		return prev;
	}
}

#endif
