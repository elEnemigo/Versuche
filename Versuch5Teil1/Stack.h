/**
 * @file Stack.h
 *
 * content: Class defining a software stack
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "ListElem.h"

/**
* @brief The class implementing a software stack
*/
class Stack
{
private:
	ListElem* head;     ///< Head of stack
	ListElem* tail;     ///< Tail of stack

public:
    /**
    * @brief Constructor of this class. Initializes both head and tail to NULL
    */
    Stack();

    /**
    * @brief Prints each element in the stack in the reverse order they were placed in
    */
    void ausgabe() const;

    /**
    * @brief Literally "pushes" an element onto the stack
    *
    * @param data  The element to be pushed on the stack
    */
    void push(Student& data);

    /**
    * @brief Literally "pops" an element off the stack
    *
    * @param data  The element in which to store the "popped" value
    * @return Returns false if there's not a single element in the list. Otherwise true.
    */
    bool pop(Student& data);
};
#endif
