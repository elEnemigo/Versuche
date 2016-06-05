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
	void push (const T& e);
	void pop (T& e);

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
StackSpeicher <size, T> :: StackSpeicher():index(-1)
{
}

/**
 * @brief Function to push an Element
 * @param e Element to save
 */
template <int size, class T>
void StackSpeicher <size, T>::push(const T& e)
{
	if (index < (size-1))
	{
		index += 1;
		space[index] = e;
	}
}

/**
 * @brief Function to retriev an Element from the Stack
 * @param e Position to save the Element
 */
template<int size, class T>
void StackSpeicher<size, T>::pop(T& e)
{
	if (index >= 0)
	{
		e = space[index];
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
    int i, j, k;
    T tmp;

    // A r value of -1 means we sort the entire stack
    if (r == -1)
        r = index;

    // Nothing left to sort
    if (r <= l)
        return ;

    // Partition
    k = r;
    i = l;
    j = r - 1;
    while (1)
    {
        while (space[i] <= space[k] && i < r)
            i++;
        while (space[j] >= space[k] && j >= l)
            j --;
        if (i >= j)
            break ;
        else
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


    // Recursive calls
    sort (l, i- 1);
    sort (i + 1, r);
}
#endif /*STACKSPEICHER_H_*/
