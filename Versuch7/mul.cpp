/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  mul.cpp
 * Inhalt: Sourcedatei Klasse Mul
 */

#include "expression.h"


Mul::Mul(Expression* leftOperand, Expression* rightOperand)
: leftOp(leftOperand), rightOp(rightOperand)
{

}

Mul::~Mul()
{
    delete leftOp;
    delete rightOp;
}

double Mul::evaluate() const
{
    return leftOp->evaluate() * rightOp->evaluate();
}

std::string Mul::print() const
{
    return leftOp->print() + " * " + rightOp->print();
}
