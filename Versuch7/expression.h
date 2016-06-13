/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  expression.h
 * Inhalt: Headerdatei Abstrakte Klasse Expression
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <sstream>	//To convert double to string

class Expression
{
public:
	Expression();
	virtual ~Expression();
	virtual double evaluate() const = 0; // calculates and returns the value of expression
	virtual std::string print() const = 0; // returns the mathematical expression as string
};


#include "const.h"
#include "result.h"
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

#endif
