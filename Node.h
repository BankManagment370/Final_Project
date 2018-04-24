#ifndef NODE_TYPE_H
#define NODE_TYPE_H
template <class  Type>
struct Node { 
	Type data;
	Node<Type> *next;
};

#endif
