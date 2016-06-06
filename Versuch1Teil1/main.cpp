#include <iostream>

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

int main()
{
    // Rekursive fibonacci formel:
    // f(n) = f(n-1)+f(n-2)  f(0) = 0  f(1) = 1 -> f(2) = 1

    for ( int i = 0; i <= 25; i++)
        std::cout << "f(" << i << ") = " << fibonacci_rec(i) << std::endl;
}
