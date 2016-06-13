/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  mul.h
 * Inhalt: Headerdatei Klasse Mul
 */

#ifndef MUL_H
#define MUL_H


/**
 * @brief Mul class. Inherits from @ref Expression
 *
 * This class implements the multiply operation
 */
class Mul : public Expression
{
private:
    Expression* leftOp;     //!< Pointer to left expression
    Expression* rightOp;    //!< Pointer to right expression
public:
    Mul(Expression* leftOperand, Expression* rightOperand);     //!< @brief Constructor @param leftOperand  Left @ref Expression to be used by this operation @param rightOperand  Right @ref Expression to be used by this operation
    virtual ~Mul();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // MUL_H
