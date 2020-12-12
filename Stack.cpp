#include <iostream>
#include <cstddef>
#include "Stack.h"
using namespace std;


Stack::Stack()
{
    //Default Constructor
    //Initalizes top to NULL
    StackFramePtr top = NULL;
}

Stack::Stack(StackFramePtr other)
{
    //Constructor for another object
    top = other;
}

Stack::Stack(const Stack& stack_obj)
//Copy Constructor
//Copy object to another on initalisation
//Initalizes a copy of the stack object to be created upon initialization
{
    if (stack_obj.top == NULL)
    {
        top = NULL;
    }
    else
    {
        StackFramePtr temp = stack_obj.top;
        StackFramePtr end;

        try
        {
            end = new StackFrame;
            end->data = temp->data;
            top = end;

            temp = temp->link;

            while (temp != NULL)
            {
                end->link = new StackFrame;
                end = end->link;
                end->data = temp->data;
                temp = temp->link;
            }

            end->link = NULL;

            //throw std::bad_alloc(); 
        }
        catch (std::bad_alloc& ba)
        {
            std::cerr << "bad_alloc caught: " << ba.what();
        }
    }
}


Stack::~Stack()
{
    //Destructor
    //Deletes stack and frees memory
    //Pops all values in stack at end of program, return to heap
    char next;
    while (!empty())
    {
        next = pop();
    }
}


void Stack::operator=(const Stack& stack_obj)
{
    //Overload Assignment Operator
    //Copy object to another on assignment
    //Assigns the value of stack_object to another upon assignment
    if (stack_obj.top == NULL)
    {
        top = NULL;
    }
    else
    {
        StackFramePtr temp = stack_obj.top;
        StackFramePtr end;

        try
        {
            end = new StackFrame;
            end->data = temp->data;
            top = end;

            temp = temp->link;
            while (temp != NULL)
            {
                end->link = new StackFrame;
                end = end->link;
                end->data = temp->data;
                temp = temp->link;

            }
            end->link = NULL;
        }
        catch (std::bad_alloc& ba)
        {
            std::cerr << "bad_alloc caught: " << ba.what();
        }
    }
}


StackFramePtr Stack::get_top()
{
    //Accessor for top
    //Returns value at top of stack
    return top;
}


void Stack::push(char the_symbol)
{
    //Precondition: Stack NULL, or stack with values
    //Postcondition: New value added to stack at the top
    //top = the_symbol
    StackFramePtr tempPtr;
    tempPtr = new StackFrame;

    tempPtr->data = the_symbol;
    tempPtr->link = top;
    top = tempPtr;
}


char Stack::pop()
{
    //Precondition: Stack must have values 
    //Postcondition: top removed from stack
    if (empty())
    {
        cout << "Error: Cannot pop an empty list!";
        exit(1);
    }
    else
    {
        try
        {
            char result = top->data;

            StackFramePtr temp_ptr;
            temp_ptr = top;
            top = top->link;

            delete temp_ptr;

            return result;
        }
        catch (std::bad_alloc& ba)
        {
            std::cerr << "bad_alloc caught: " << ba.what();
        }
    }
}

bool Stack::empty() const
{
    //Checks if stack is empty 
    //Return true if yes, otherwise false if not.
    return (top == NULL);
}

//Recursive function 
void Stack::insertBottom(char the_symbol)
{
    //Precondition
    //Postcondition
    if (top == NULL)
    {
        push(the_symbol);
        return;
    }

    else
    {
        char val1;
        val1 = top->data;
        pop();
        insertBottom(the_symbol);
        push(val1);

    }
}

void Stack::reverse()
{
    //Precondition
    //Postcondition
    //
    // NOT allowed to use another stack, queue, array, vector, linked list, etc.
    // NOT allowed to use loop constructs like for, while, etc. Instead, you should use a recursive algorithm to implement this.
    if (top != NULL)
    {
        char val1;
        val1 = top->data;
        pop();
        reverse();
        insertBottom(val1);
    }
}

