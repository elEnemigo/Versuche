/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  const.cpp
 * Inhalt: Sourcedatei Klasse Const
 */

#include "expression.h"


Const::Const(double val)
: value(val)
{

}

Const::~Const()
{

}

double Const::evaluate() const
{
    return value;
}

std::string Const::print() const
{
    std::ostringstream conv;
    conv << value;
    return conv.str();
}
