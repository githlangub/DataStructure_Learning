#ifndef _LIST_HPP
#define _LIST_HPP

template<typename ElemType>
class List
{
	public:
		//物理实现相关
		List(void)=default;   //创建
		virtual ~List()=default;   //销毁
		virtual void ListClear(void)=0;   //清空

		//元素操作相关
		virtual void ElemInsert(ElemType ,unsigned )=0;   //增加元素
		virtual void ElemDelete(unsigned )=0;   //删除元素
		virtual void ElemSet(ElemType ,unsigned )=0;   //改变元素
		virtual ElemType ElemGet(unsigned )=0;   //查找元素
		virtual void ListPrint(void)=0;   //遍历输出

		//属性相关
		inline unsigned GetLength(void)   //获取长度
		{
			return len;
		};
		inline bool IsEmpty(void)   //查空
		{
			return !len;
		};
	protected:
		unsigned len;   //无限长能否实现？？？
};

#endif
