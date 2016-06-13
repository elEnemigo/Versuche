/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  sub.cpp
 * Inhalt: Sourcedatei Klasse Sub
 */

#include "expression.h"


Sub::Sub(Expression* leftOperand, Expression* rightOperand)
: leftOp(leftOperand), rightOp(rightOperand)
{

}

Sub::~Sub()
{
    delete leftOp;
    delete rightOp;
}

double Sub::evaluate() const
{
    return leftOp->evaluate() - rightOp->evaluate();
}

std::string Sub::print() const
{
    return "(" + leftOp->print() + " - " + rightOp->print() + ")";
}
