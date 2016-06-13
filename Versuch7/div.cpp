/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  div.cpp
 * Inhalt: Sourcedatei Klasse Div
 */

#include "expression.h"


Div::Div(Expression* leftOperand, Expression* rightOperand)
: leftOp(leftOperand), rightOp(rightOperand)
{

}

Div::~Div()
{
    delete leftOp;
    delete rightOp;
}

double Div::evaluate() const
{
    return leftOp->evaluate() / rightOp->evaluate();
}

std::string Div::print() const
{
    return "(" + leftOp->print() + " / " + rightOp->print() + ")";
}
