#include "Stack.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void printStack(Stack& stack_obj)
{
    //Precondition: Takes in top value from stack, creates temp 
    //Postcondition: Copies temp values into new stack recursively, using values from original stack

    StackFramePtr temp;
    temp = stack_obj.get_top();

    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->link;
    }

    cout << endl;

}

int main()
{
    //Test A: 
    //Precondition: Creates a stack
    //Postcondition: Print the stack with integers that we're passed in, and another reversed copy
    cout << "___________________________________________\n" << "Test A: " << endl;
    cout << "Stack \n";
    Stack sint1;
    sint1.push('1');
    sint1.push('3');
    sint1.push('4');
    printStack(sint1);

    Stack sint2 = sint1; //Overloaded Assignment Operator
    sint2.reverse();
    printStack(sint2);


    //Test B:
    //Precondition: Creates a stack, pushes values in
    //Postcondition: Print Stack, reverse a copy but only print its head
    cout << "___________________________________________\n" << "Test B: " << endl;
    cout << "Stack \n";
    Stack sdouble1;
    sdouble1.push('1');
    sdouble1.push('3');
    sdouble1.push('4');
    printStack(sdouble1);

    Stack sdouble2(sdouble1); //Copy constructor
    sdouble2.reverse();
    cout << "Top Value: " << sdouble2.get_top()->data << endl; //Use pointer to obtain memory value, otherwise memory leak


  //Palindrome
  //Precondition: User inputted string value
  //Postcondition: Print out palindrome using original string, and reversed character stack


    Stack string1 = sdouble1;
    string1.pop();
    string1.pop();
    string1.pop();

    cout << "___________________________________________\n" << "Test C: " << endl;
    cout << "Type in a string!\n";
    string palindromestring;
    cout << "Only strings of 9 letters will work!";
    cout << "Please input a string!: ";
    cin >> palindromestring;

    /*
    char myPalindromCharArray[palindromestring.length()];
    strcpy_s(myPalindromCharArray, palindromestring.c_str());
    string1.push(myPalindromCharArray[0]);
    string1.push(myPalindromCharArray[1]);
    string1.push(myPalindromCharArray[2]);
    string1.push(myPalindromCharArray[3]);
    string1.push(myPalindromCharArray[4]);
    string1.push(myPalindromCharArray[5]);
    string1.push(myPalindromCharArray[6]);
    string1.push(myPalindromCharArray[7]);
    string1.push(myPalindromCharArray[8]);
    printStack(string1);
    string1.reverse();
    printStack(string1);
    */
}

//Palindrome error

  /*
  for (int i = 0; i < palindromestring.length(); i++) {
    //Push values from array into stack
    //string1.push(myPalindromCharArray[i]);
  }
  */
