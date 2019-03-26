#ifndef _NODE_HPP
#define _NODE_HPP

template<typename ElemType>
class Node
{
	public:
		Node(ElemType );
		Node(void);
		virtual
			~Node();

		inline
			ElemType DataRead(void);   //读取数据
		inline
			void DataWrite(ElemType );   //写入数据

		void LinkNext(Node* );   //连接下一个节点
		Node* RemoveNext(void);   //断开下一个节点
		inline
			Node* GetNext(void);  //获取下一个节点的地址
	protected:
		ElemType data;
		Node* next;
};



template<typename ElemType>
class Node_Dou:
	public Node<ElemType>
{
	public:
		Node_Dou(ElemType );
		Node_Dou(void);
		~Node_Dou();

		void LinkPrior(Node_Dou* );   //连接上一个节点
		Node_Dou* RemovePrior(void);   //断开上一个节点
		inline
			Node_Dou* GetPrior(void);   //获取上一个节点地址
	protected:
		Node_Dou* prior;
};

#endif

