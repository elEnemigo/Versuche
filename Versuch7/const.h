/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  const.h
 * Inhalt: Headerdatei Klasse Const
 */

#ifndef CONST_H
#define CONST_H


class Const : public Expression
{
private:
    double value;
public:
    Const(double val);
    virtual ~Const();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // CONST_H
