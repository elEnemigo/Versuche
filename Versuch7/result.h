/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  result.h
 * Inhalt: Headerdatei Klasse Result
 */

#ifndef RESULT_H
#define RESULT_H


/**
 * @brief Result class. Inherits from @ref Expression
 *
 * This class handles an expression.
 */
class Result : public Expression
{
private:
    Expression* expr;   //!< Pointer to expression
public:
    Result(Expression* expression);     //!< @brief Constructor @param expression  @ref Expression this instance is going to refer to
    virtual ~Result();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // RESULT_H
