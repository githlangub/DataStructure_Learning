#ifndef _NODE_TPP
#define _NODE_TPP

#include<iostream>
#include"../include/node.hpp"

template<typename ElemType>
Node<ElemType>::Node(ElemType elem)
{
	this->data=elem;
	this->next=NULL;

	//std::cout<<"A node is added!"<<std::endl;
}

	
	
template<typename ElemType>
Node<ElemType>::Node(void)
{
	this->data=0;
	this->next=NULL;

	//std::cout<<"Head node is added!"<<std::endl;
}



template<typename ElemType>
Node<ElemType>::~Node()
{
	//std::cout<<"A node is deleted"<<std::endl;
}



template<typename ElemType>
ElemType Node<ElemType>::DataRead(void)
{
	return this->data;
}



template<typename ElemType>
void Node<ElemType>::DataWrite(ElemType elem)
{
	this->data=elem;
}



template<typename ElemType>
void Node<ElemType>::LinkNext(Node* nextnode)
{
	this->next=nextnode;
}



template<typename ElemType>
Node<ElemType>* Node<ElemType>::RemoveNext()
{
	Node<ElemType>* nextnode=this->next;
	this->next=NULL;
	return nextnode;
}



template<typename ElemType>
Node<ElemType>* Node<ElemType>::GetNext()
{
	return this->next;
}



template<typename ElemType>
Node_DouDir<ElemType>::Node_DouDir(ElemType elem)
{
	this->data=elem;
	this->next=NULL;
	this->prior=NULL;

	//std::cout<<"A double-direction-node is added!"<<std::endl;
}

	
	
template<typename ElemType>
Node_DouDir<ElemType>::Node_DouDir(void)
{
	this->data=0;
	this->next=NULL;
	this->prior=NULL;

	//std::cout<<"Head node is added!"<<std::endl;
}



template<typename ElemType>
Node_DouDir<ElemType>::~Node_DouDir()
{
	//std::cout<<"A double-direction-node is deleted"<<std::endl;
}

	
	
template<typename ElemType>
void Node_DouDir<ElemType>::LinkPrior(Node_DouDir* priornode)
{
	this->prior=priornode;
}



template<typename ElemType>
Node_DouDir<ElemType>* Node_DouDir<ElemType>::RemovePrior()
{
	Node_DouDir<ElemType>* priornode=this->prior;
	this->prior=NULL;
	return priornode;
}



template<typename ElemType>
Node_DouDir<ElemType>* Node_DouDir<ElemType>::GetPrior()
{
	return this->prior;
}

#endif










