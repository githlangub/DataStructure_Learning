#ifndef _LINKLIST_DOU_HPP
#define _LINKLIST_DOU_HPP

#include"node.hpp"
#include"linklist.hpp"

template<typename ElemType>
class LinkList_Dou:
	public LinkList<ElemType>
{
	public:
	LinkList_Dou(void);
	~LinkList_Dou();

	//void ElemInsert(ElemType ,unsigned );
	//void ElemDelete(unsigned );
	//private:
	//Node_Dou<ElemType>* LocateAddr(unsigned );
	//private:
	//Node_Dou<ElemType>* head;
	//Node_Dou<ElemType>* tail;
};

#endif
