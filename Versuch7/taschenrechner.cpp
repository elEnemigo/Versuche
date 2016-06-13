/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  taschenrechner.cpp
 * Inhalt: Hauptprogramm
 */

#include "expression.h"
#include <iostream>

void testConst()
{
	Const c(4);
	std::cout << c.print() << " = " << c.evaluate() << std::endl;
}

void testResult()
{
	Result res ( new Const(4) );
	std::cout << res.print() << " = " << res.evaluate() << std::endl;
}

void testAddConst()
{
	Result res (	new Add (
					new Const(7),
					new Const(8)
				)
			);
	std::cout << res.print() << " = " << res.evaluate() << std::endl;
}

void testMultConst()
{
// TODO: test for multiplication
    Result res (	new Mul (
					new Const(7),
					new Const(8)
				)
			);
	std::cout << res.print() << " = " << res.evaluate() << std::endl;
}

void finalTest()
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
}

int main(void)
{
	// implementieren Sie zuerst die Klassen Const und Result und Testen Sie das Ergebnis.
	testConst();
	testResult();

	// Ergänzen Sie ihr Programm nach und nach um weitere Rechenoperationen
	testMultConst();
	testAddConst();
	std::cout << "Final Test: " << std::endl;
	finalTest();

	return 0;
}

/*
    Aufgabe 4
    Objekte die in einem Block erzeugt wurden, werden nicht geloescht
    Im destruktor alle pointer loeschen
*/
