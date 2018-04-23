#pragma once
#ifndef BANK_STACK.H
#define BANK_STACK.H

template <class  Type>
class Bank_Stack {
public:
	Bank_Stack();
	~Bank_Stack();
	bool isEmpty() const;
	bool isFull() const;
	void push(Type item);
	Type pop();
	Type top() const;
	void displayStack();


};




#endif // !BANK_STACK.H

