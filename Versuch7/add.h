/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  add.h
 * Inhalt: Headerdatei Klasse Add
 */

#ifndef ADD_H
#define ADD_H


class Add : public Expression
{
private:
    Expression* leftOp;
    Expression* rightOp;
public:
    Add(Expression* leftOperand, Expression* rightOperand);
    virtual ~Add();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // ADD_H
