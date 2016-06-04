/**
 * @file ListElem.cpp
 *
 * content: List element to be used in a data structure
 */

#include "ListElem.h"

ListElem::ListElem(const Student &pData, ListElem *const pNext):
    data(pData), next(pNext)
{
}

/**
 * @param pData The data to be stored.
 * @return void
 */
void ListElem::setData(const Student &pData)
{
    data = pData;
}

/**
 * @param pNext A pointer to the next element of data structure.
 * @return void
 */
void ListElem::setNext(ListElem *const pNext)
{
    next = pNext;
}

/**
 * @return Student
 */
Student ListElem::getData() const
{
    return data;
}

/**
 * @return ListElem*
 */
ListElem *ListElem::getNext() const
{
    return next;
}
