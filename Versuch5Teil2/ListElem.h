/**
 * @file ListElem.h
 *
 * content: List element to be used in a data structure
 */

#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

/**
 * @brief An element which can be stored in a data structure
 *
 * The type of data stored here is @ref Student.
 *
 */
class ListElem
{
private:
    Student data;                                           ///< the actual data
    ListElem *next;                                         ///< pointer to the next element in list

public:
    ListElem(const Student &pData, ListElem *const pNext);   ///< @brief constructor with variable initialisation
    /* setter */
    void setData(const Student &pData);
    void setNext(ListElem *const pNext);
    /* getter */
    Student getData() const;
    ListElem *getNext() const;
};

#endif
