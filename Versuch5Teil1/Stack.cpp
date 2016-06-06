/**
 * @file Stack.cpp
 *
 * content: Class defining a software stack
 */

#include "Stack.h"

Stack::Stack()
:head(NULL)
{
	tail = NULL;
}

void Stack::push(Student& data)
{
	ListElem* neu = new ListElem(data, NULL);

	if(head == NULL)
        tail = neu;
	else
		neu->setNext(head);

    head = neu;
}

void Stack::ausgabe() const
{
    if (head == NULL)
        std::cout << "Der Stack ist leer." << std::endl;
    else
    {
        ListElem* cursor = head;

		/**
		 while(cursor != NULL)
		 {
            std::cout << "test1" << std::endl;
		 }
		 */

		while (cursor != NULL)
		{
			std::cout << (cursor->getData()).name << ", MatNr. " << (cursor->getData()).matNr << " geb. am " << (cursor->getData()).date_of_birth << " wohnhaft in " << (cursor->getData()).adresse << std::endl;
			/**
			 if(cursor != NULL)
                std::cout << "test2";

			 else
                std::cout << "test3" << std::endl;
			 */

			cursor = cursor->getNext();
		}
	}
}

bool Stack::pop(Student& data)
{
	if  (head == NULL)
        return false;
	else if (head == tail)
	{
	    data = head->getData();
	    delete head;
	    tail = NULL;
	    head = NULL;
	}
	else
    {
        ListElem* cursor = head;

        while (cursor->getNext() != tail)
            cursor = cursor->getNext();

        data = tail->getData();

	   /*void Stack::a(Student& x)
	   {
	   	ListElem *neu =new ListElem(x, NULL);
	   	if(z == NULL)z= neu;
	   	else
	   		neu->getNext(z); y = neu;
	   	}
	   	*/

	   	tail = cursor;
	   	delete cursor->getNext();
	   	cursor->setNext(NULL);
    }

	return true;
}





