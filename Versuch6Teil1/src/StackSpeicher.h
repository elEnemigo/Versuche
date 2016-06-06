/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.1: Templates und Überladen von Operatoren
 *
 * Datei:  StackSpeicher.h
 * Inhalt: generischer Stackspeicher
 */

#ifndef STACKSPEICHER_H_
#define STACKSPEICHER_H_

// StackClass
/**
 * @brief Software stack implementation
 *
 * The type of data stored here can be anything.
 *
 */
template<int size, class T>
class StackSpeicher
{
  public:
	StackSpeicher();
	void push (const T& element);
	void pop (T& element);

	// Inser your Implementation here
	void sort(const int l=0, int r=-1);

	/**
     * @brief Stream operator
     * @param out  Left side of the operator
     * @param stackSpeicher  Right side of the operator
     */
	friend std::ostream& operator << (std::ostream& out, const StackSpeicher<size, T>& stackSpeicher)
	{
        for (int i = 0; i <= stackSpeicher.index; i++)  // Iterate though each entry and << it into out
            out << stackSpeicher.space[i] << std::endl;

        return out;
    }

  private:
	T space[size];
	int index;
};

/**
 * @brief Constructor
 */
template <int size, class T>
StackSpeicher <size, T> :: StackSpeicher()
:index(-1)
{
}

/**
 * @brief Function to push an Element
 * @param e Element to save
 */
template <int size, class T>
void StackSpeicher <size, T>::push(const T& element)
{
	if (index < (size-1))
	{
		index += 1;
		space[index] = element;
	}
}

/**
 * @brief Function to retriev an Element from the Stack
 * @param e Position to save the Element
 */
template<int size, class T>
void StackSpeicher<size, T>::pop(T& element)
{
	if (index >= 0)
	{
		element = space[index];
		index -= 1;
	}
}

// Insert your Implementation here
/**
 * @brief Function to sort our stack
 *
 * This is a recursive implementation of the quicksort algorithm.
 * The two parameters define the left and right boundaries respectively of
 * successive elements to sort.
 *
 * @param l Left margin of the elements to sort. Default = 0
 * @param r Right margin of the elements to sort. -1 means to sort the entire thing. Default = -1
 */
template<int size, class T>
void StackSpeicher<size, T>::sort(const int l, int r)
{
    // Locals
    int i, j;
    T tmp;

    // An r value of -1 means we sort the entire stack
    if (r == -1)
        r = index;

    // Nothing left to sort
    if (r <= l)
        return ;

    // Partition
    // r is pivot
    i = l;
    j = r - 1;
    while (1)
    {
        while (space[i] <= space[r] && i < r)       // Find element larger than pivot (front to back). This will be swapped
            i++;
        while (space[j] >= space[r] && j >= l)      // Find element smaller than pivot (back to front)
            j--;
        if (i >= j)                                 // If the smaller element is to the left of the larger then quit
            break ;
        else                                        // Else swap larger element with pivot
        {
            // Exchange elements
            T tmp = space[i];
            space[i] = space[r];
            space[r] = tmp;
        }
    }
    // Exchange elements
    tmp = space[i];
    space[i] = space[r];
    space[r] = tmp;

    // Pivot is now at i

    // Recursive calls
    sort (l, i - 1);
    sort (i + 1, r);
}
#endif /*STACKSPEICHER_H_*/
