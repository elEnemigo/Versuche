/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  sub.h
 * Inhalt: Headerdatei Klasse Sub
 */

#ifndef SUB_H
#define SUB_H


class Sub : public Expression
{
private:
    Expression* leftOp;
    Expression* rightOp;
public:
    Sub(Expression* leftOperand, Expression* rightOperand);
    virtual ~Sub();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // SUB_H
