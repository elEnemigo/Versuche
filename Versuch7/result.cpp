/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  result.cpp
 * Inhalt: Sourcedatei Klasse Result
 */

#include "expression.h"


Result::Result(Expression* expression)
: expr(expression)
{

}

Result::~Result()
{
    delete expr;
}

double Result::evaluate() const
{
    return expr->evaluate();
}

std::string Result::print() const
{
    return expr->print();
}
