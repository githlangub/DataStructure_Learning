#ifndef _STACK_HPP
#define _STACK_HPP

#include"list.hpp"

template<typename ElemType>
class Stack
{
	public:
		//物理实现相关
		Stack(void);  //创建
		~Stack();   //销毁
		void Clear(void);   //清空

		void Push(ElemType );   //入栈
		ElemType Pop(void);   //出栈
		ElemType GetTop(void);   //获取栈顶元素
		void Print(void);   //遍历输出

		unsigned GetLength(void);   //获取长度
		bool IsEmpty(void);   //判断是否空栈
	private:
		List<ElemType>* data;
		unsigned len;
};

#endif
