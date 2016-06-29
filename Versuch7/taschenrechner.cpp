/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  taschenrechner.cpp
 * Inhalt: Hauptprogramm
 */

#include "expression.h"
#include <iostream>

/**
 * @brief Tests the Const-Class
 * @return  True when test succeeded. Otherwise false.
 */
bool testConst()
{
	Const c(4);
	std::cout << c.print() << " = " << c.evaluate() << std::endl;

	if (c.evaluate() == 4)
		return true;
	else
		return false;
}

/**
 * @brief Tests the Result-Class
 * @return  True when test succeeded. Otherwise false.
 */
bool testResult()
{
	Result res ( new Const(4) );
	std::cout << res.print() << " = " << res.evaluate() << std::endl;

	if (res.evaluate() == 4)
		return true;
	else
		return false;
}

/**
 * @brief Tests the Add-Class
 * @return  True when test succeeded. Otherwise false.
 */
bool testAddConst()
{
	Result res (	new Add (
					new Const(7),
					new Const(8)
				)
			);
	std::cout << res.print() << " = " << res.evaluate() << std::endl;

	if (res.evaluate() == 7 + 8)
		return true;
	else
		return false;
}

/**
 * @brief Tests the Mul-Class
 * @return  True when test succeeded. Otherwise false.
 */
bool testMultConst()
{
// TODO: test for multiplication
    Result res (	new Mul (
					new Const(7),
					new Const(8)
				)
			);
	std::cout << res.print() << " = " << res.evaluate() << std::endl;

	if (res.evaluate() == 7 * 8)
		return true;
	else
		return false;
}

/**
 * @brief Tests everything
 * @return  True when test succeeded. Otherwise false.
 */
bool finalTest()
{
	Result res (	new Add (
                        new Add (
                            new Const(4),
                            new Mul (
                                new Const(9),
                                new Const(5)
                                )
                            ),
						new Div (
                                new Sub (
                                         new Const(38),
                                         new Const(7)
                                         ),
                                new Const(4)
                                )
                    )
                );
	std::cout << res.print() << " = " << res.evaluate() << std::endl;

	if (res.evaluate() == 4.0 + 9.0 * 5.0 + ((38.0 - 7.0) / 4.0))
		return true;
	else
		return false;
}

/**
 * @brief Entrypoint
 */
int main(void)
{
	// implementieren Sie zuerst die Klassen Const und Result und Testen Sie das Ergebnis.
	if (!testConst())
	{
		std::cout << "Const test failed!" << std::endl;
		return 0;
	}
	if (!testResult())
	{
		std::cout << "Result test failed!" << std::endl;
		return 0;
	}

	// Ergänzen Sie ihr Programm nach und nach um weitere Rechenoperationen
	if (!testMultConst())
	{
		std::cout << "Mul test failed!" << std::endl;
		return 0;
	}
	if (!testAddConst())
	{
		std::cout << "Add test failed!" << std::endl;
		return 0;
	}
	std::cout << "Final Test: " << std::endl;
	if (!finalTest())
	{
		std::cout << "Last test failed!" << std::endl;
		return 0;
	}

	return 0;
}

/*
    Aufgabe 4
    Objekte die in einem Block erzeugt wurden, werden nicht geloescht
    Im destruktor alle pointer loeschen
*/
