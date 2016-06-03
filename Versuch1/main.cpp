#include <iostream>
#include <time.h>

// 1.8.1 1. -----------------------------
int fib_rec(int n)\
{
	if(n==0)
		 return 0;
	else if(n==1||n==2)
		return 1;
	else
		return fib_rec(n-1) + fib_rec(n-2);
}
// ---------------------------------------


// 1.8.2 ---------------------------------------------------
int fib(int n)
{
	int prevFib = 1;
	int currFib = 1;
	if(n == 0)
	{
		return 0;
	}
	if(n == 1 || n == 2)
	{
		return 1;
	}
	for (int i = 3; i <= n; i++)    // Original: for (int i = 0; i <= n; i++)
	{
		int newFib = prevFib + currFib ;
		prevFib = currFib ;         // Original: prevFib = newFib ;
		currFib = newFib ;          // Original: currFib = prevFib ;
	}
	return currFib ;
}
// --------------------------------------------------------


int main ()
{
    // 1.8.1 3. --------------------------------
    for(int i = 0; i <= 25; i++)
        std::cout << fib_rec(i) << std::endl;
    // -----------------------------------------


    // 1.8.2 ---------------------------------------------------
	std :: cout << " Fibonacci - Zahlen :" << std :: endl ;
	for (int i = 1; i <= 48 ; i ++)
	{
		std :: cout << "f(" << i << ") = " << fib (i) << std :: endl ;
	}
    // ---------------------------------------------------------


    // 1.8.2 4. ------------------------------------------------------------------
	clock_t t = clock();
	fib_rec(42);
	t = clock() - t;
	std::cout << "Runtime(recursive): " << (float)(t)/CLOCKS_PER_SEC << "s\n";

    t = clock();
	fib(42);
	t = clock() - t;
	std::cout << "Runtime(iterative): " << (float)(t)/CLOCKS_PER_SEC << "s\n";

	/*
        Runtime(recursive): 2.168s
        Runtime(iterative): 0s
        Funktionsaufrufe kosten Zeit.
        Rekursive Programme haben eine viel höhere Aufrufszahl
    */
    // --------------------------------------------------------------------------


    // 1.8.2 5. ------------------------------------------------------------------
	/*
        Es gibt einen Integer-Overflow der das Ergebnis verfälscht
        Ließe sich durch einen größeren Datentypen beheben (z.B. unsigned int, long)
        n = 46 ist die groesste berechenbare Zahl
    */
    // ---------------------------------------------------------------------------


	return 0;
}
