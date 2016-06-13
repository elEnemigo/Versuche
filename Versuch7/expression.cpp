/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  expression.cpp
 * Inhalt: Sourcedatei Abstrakte Klasse Expression
 */

#include "expression.h"
#include <iostream>

Expression::Expression()
{
	std::cout << "Created Expression" << std::endl;
}

Expression::~Expression()
{
	std::cout << "Deleted Expression" << std::endl;
}
