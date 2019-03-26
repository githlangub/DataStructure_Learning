#ifndef _LINKLIST_DOU_TPP
#define _LINKLIST_DOU_TPP

#include<iostream>
#include"../include/linklist_dou.hpp"
#include"node.tpp"

template<typename ElemType>
LinkList_Dou<ElemType>::LinkList_Dou(void)
{
	//添加头节点，长度置零
	this->head=this->tail=new Node_Dou<ElemType>;
	this->len=0;

	std::cout<<"Double-Direction linklist successfully initial!"<<std::endl;
}

template<typename ElemType>
LinkList_Dou<ElemType>::~LinkList_Dou()
{
	Node_Dou<ElemType>* prev=(Node_Dou<ElemType>*)(this->head);
	Node_Dou<ElemType>* next=NULL;
	this->head=this->tail=NULL;
	do
	{
		next=(Node_Dou<ElemType>*)(prev->GetNext());
		delete prev;
		prev=next;
	}while(prev);

	std::cout<<"Double-Direction linklist destroyed!";
}

#endif
