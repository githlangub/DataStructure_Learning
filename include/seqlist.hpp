#ifndef _SEQLIST_HPP
#define _SEQLIST_HPP

#include"list.hpp"

template<typename ElemType>
class SeqList:
	public List<ElemType>
{
	public:
		//物理实现相关
		SeqList(void);   //创建
		~SeqList();   //销毁
		void ListClear(void);   //清空

		//元素操作相关
		void ElemInsert(ElemType ,unsigned );	//增加元素
		void ElemDelete(unsigned );	//删除元素
		void ElemSet(ElemType ,unsigned );   //改变元素
		ElemType ElemGet(unsigned );   //查找元素
		void ListPrint(void);   //遍历输出，纵向，不支持合成类型
	private:
		ElemType* elem;   //元素存储空间基址
		unsigned listsize;   //以sizeof(Elemtype)为单位
};
#endif

