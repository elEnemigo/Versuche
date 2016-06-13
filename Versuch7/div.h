/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  div.h
 * Inhalt: Headerdatei Klasse Div
 */

#ifndef DIV_H
#define DIV_H


class Div : public Expression
{
private:
    Expression* leftOp;
    Expression* rightOp;
public:
    Div(Expression* leftOperand, Expression* rightOperand);
    virtual ~Div();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // DIV_H
