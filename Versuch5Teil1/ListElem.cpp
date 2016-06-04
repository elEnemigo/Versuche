/**
 * @file ListElem.cpp
 *
 * content: Class defining a singly linked list
 */

#include "ListElem.h"
#include "Student.h"


ListElem::ListElem(const Student& firstData, ListElem* const nextElement)
: data(firstData),
next(nextElement)
{

}

void ListElem::setData(const Student& newData)
{
    data = newData;
}

void ListElem::setNext(ListElem* const nextElement)
{
	next = nextElement;
}

Student ListElem::getData() const
{
    return data;
}

ListElem* ListElem::getNext() const
{
    return next;
}
