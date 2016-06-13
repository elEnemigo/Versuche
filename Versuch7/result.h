/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  result.h
 * Inhalt: Headerdatei Klasse Result
 */

#ifndef RESULT_H
#define RESULT_H


class Result : public Expression
{
private:
    Expression* expr;
public:
    Result(Expression* expression);
    virtual ~Result();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // RESULT_H
