#include <iostream>
#include <time.h>

// Iterative fibonacci Funktion
int fib(int n)
{
	int prevFib = 1;
	int currFib = 1;
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	for (int i = 3; i <= n; i++)                // Original: for (int i = 0; i <= n; i++)
	{
		int newFib = prevFib + currFib ;
		prevFib = currFib;                      // Original: prevFib = newFib ;
		currFib = newFib;                       // Original: currFib = prevFib ;
	}
	return currFib ;
}

// Rekursive fibonacci Funktion
int fibonacci_rec(int n)
{
    if (n == 0)
		 return 0;
	else if (n == 1 || n == 2)
		return 1;
	else
		return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

int main ()
{
    // fibonacci reihe von n = 1 bis n = 12 ausgeben
	std :: cout << " Fibonacci - Zahlen :" << std :: endl ;
	for (int i = 1; i <= 12 ; i ++)
	{
		std :: cout << "f(" << i << ") = " << fib (i) << std :: endl ;
	}


	// Zeitmessung der rekursiven funktion für n=42
    clock_t t = clock();
	fibonacci_rec(42);
	t = clock() - t;
	std::cout << "Runtime(recursive): " << (float)(t)/CLOCKS_PER_SEC << "s\n";

	// Zeitmessung der iterativen funktion für n=42
    t = clock();
	fib(42);
	t = clock() - t;
	std::cout << "Runtime(iterative): " << (float)(t)/CLOCKS_PER_SEC << "s\n";

    /*
        Runtime(recursive): 1.086s
        Runtime(iterative): 0s
        Funktionsaufrufe kosten Zeit.
        Rekursive Programme haben eine viel höhere Aufrufszahl
    */


    // Zusatzaufgabe
    std :: cout << "Recursive: f(47) = " << fibonacci_rec(47) << std :: endl ;
    std :: cout << "Iterative: f(47) = " << fib(47) << std :: endl ;

    /*
        f(47) wäre eigentlich 2971215073
        Diese Zahl ist jedoch außerhalb des signed Integer Zahlenraums ( -2.147.483.648 bis 2.147.483.647 )
        Ein anderer Datentyp wie unsigned int oder long long.
        f(46) = 1836311903 ist die größte Berechenbare Fibonacci-Zahl
    */


	return 0;
}
