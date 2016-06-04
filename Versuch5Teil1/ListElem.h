/**
 * @file ListElem.h
 *
 * content: Class defining a singly linked list
 */

#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

/**
* @brief The class implementing the list
*/
class ListElem
{
private:
	Student data;
	ListElem* next;

public:
    /**
    * @brief Constructor of this class. Initializes both 'data' and 'next' to
    * the values provided by the caller.
    *
    * @param firstData  Data of type 'Student' to initialize 'data' with
    * @param nextElement  Pointer to the next element in this list to initialize 'next' with
    */
	ListElem(const Student& firstData, ListElem* const nextElement);

	/**
    * @brief Sets 'data' for this particular element to the caller provided value
    *
    * @param newData  Data to be copied into this element
    */
	void setData(const Student& newData);

    /**
    * @brief Sets the next element to the one the caller provided
    *
    * @param nextElement  Next element in this list
    */
	void setNext(ListElem* const nextElement);

    /**
    * @brief Retrieves the data stored in this element
    *
    * @return Returns a struct of type 'Student' stored in this element
    */
	Student getData() const;

    /**
    * @brief Retrieves the next element following this one
    *
    * @return Returns a pointer to the next element in the list
    */
    ListElem* getNext() const;
};
#endif
