/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  sub.h
 * Inhalt: Headerdatei Klasse Sub
 */

#ifndef SUB_H
#define SUB_H


/**
 * @brief Sub class. Inherits from @ref Expression
 *
 * This class implements the subtract operation
 */
class Sub : public Expression
{
private:
    Expression* leftOp;     //!< Pointer to left expression
    Expression* rightOp;    //!< Pointer to right expression
public:
    Sub(Expression* leftOperand, Expression* rightOperand);     //!< @brief Constructor @param leftOperand  Left @ref Expression to be used by this operation @param rightOperand  Right @ref Expression to be used by this operation
    virtual ~Sub();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // SUB_H
