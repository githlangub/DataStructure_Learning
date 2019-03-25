#ifndef _NODE_HPP
#define _NODE_HPP

template<typename ElemType>
class Node
{
	public:
		Node(ElemType );
		Node(void);
		virtual ~Node();

		inline ElemType DataRead(void);   //读取数据
		inline void DataWrite(ElemType );   //写入数据

		void LinkNext(Node* );   //连接下一个节点
		Node* RemoveNext(void);   //断开下一个节点
		inline Node* GetNext(void);  //获取下一个节点的地址
	protected:
		ElemType data;
		Node* next;
};



template<typename ElemType>
class Node_DouDir: public Node<ElemType>
{
	public:
		Node_DouDir(ElemType );
		Node_DouDir(void);
		~Node_DouDir();

		void LinkPrior(Node_DouDir* );
		Node_DouDir* RemovePrior(void);
		inline Node_DouDir* GetPrior(void);
	protected:
		Node_DouDir* prior;
};

#endif

