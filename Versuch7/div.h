/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  div.h
 * Inhalt: Headerdatei Klasse Div
 */

#ifndef DIV_H
#define DIV_H


/**
 * @brief Div class. Inherits from @ref Expression
 *
 * This class implements the divide operation
 */
class Div : public Expression
{
private:
    Expression* leftOp;     //!< Pointer to left expression
    Expression* rightOp;    //!< Pointer to right expression
public:
    Div(Expression* leftOperand, Expression* rightOperand);      //!< @brief Constructor @param leftOperand  Left @ref Expression to be used by this operation @param rightOperand  Right @ref Expression to be used by this operation
    virtual ~Div();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // DIV_H
