/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  add.cpp
 * Inhalt: Sourcedatei Klasse Add
 */

#include "expression.h"


Add::Add(Expression* leftOperand, Expression* rightOperand)
: leftOp(leftOperand), rightOp(rightOperand)
{

}

Add::~Add()
{
    delete leftOp;
    delete rightOp;
}

double Add::evaluate() const
{
    return leftOp->evaluate() + rightOp->evaluate();
}

std::string Add::print() const
{
    return leftOp->print() + " + " + rightOp->print();
}
