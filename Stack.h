#ifndef STACK_H
#define STACK_H
#include <iostream>

struct StackFrame
{
	char data;
	StackFrame* link;
};

typedef StackFrame* StackFramePtr;

class Stack
{
public:

	//Default Constructor
	Stack();

	//Copy Constructor, Destructor and Overloaded Insertion Operator
	Stack(const Stack& stack_obj);
	Stack(StackFramePtr other);
	~Stack();

	//friend ostream& operator<<(ostream& out, Stack& stack_obj);

	//Stack functions
	void push(char the_symbol);
	char pop();
	bool empty() const;

	//Implemented top() function
	//Return the top of the stack_obj
	void reverse();

	void insertBottom(char the_symbol);

	//Overloaded Assignment Operator
	void operator=(const Stack& stack_obj);

	//Accessor function for top
	StackFramePtr get_top();

	//Create copy and free functions
	void copy(StackFramePtr& newStack_obj, StackFramePtr stack_obj);

private:
	StackFramePtr top;

};

#endif