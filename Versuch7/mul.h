/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  mul.h
 * Inhalt: Headerdatei Klasse Mul
 */

#ifndef MUL_H
#define MUL_H


class Mul : public Expression
{
private:
    Expression* leftOp;
    Expression* rightOp;
public:
    Mul(Expression* leftOperand, Expression* rightOperand);
    virtual ~Mul();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // MUL_H
