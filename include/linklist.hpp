#ifndef _LINKLIST_HPP
#define _LINKLIST_HPP

#include"list.hpp"
#include"node.hpp"

template<typename ElemType>
class LinkList:
	public List<ElemType>
{
	public:
		//物理实现相关
		LinkList(void);   //创建
		virtual 
			~LinkList();   //销毁
		void ListClear(void);   //清空

		//元素操作相关
		virtual
			void ElemInsert(ElemType ,unsigned );	//增加元素
		virtual
			void ElemDelete(unsigned );	//删除元素
		void ElemSet(ElemType ,unsigned );   //改变元素
		ElemType ElemGet(unsigned );   //查找元素
		void ListPrint(void);   //遍历输出，纵向，不支持合成类型
	protected:
		Node<ElemType>* head;   //头指针
		Node<ElemType>* tail;   //尾指针

		virtual
			Node<ElemType>* LocateAddr(unsigned );   //根据位置获取节点地址(包括头结点)
};

#endif

