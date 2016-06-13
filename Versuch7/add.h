/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  add.h
 * Inhalt: Headerdatei Klasse Add
 */

#ifndef ADD_H
#define ADD_H


/**
 * @brief Add class. Inherits from @ref Expression
 *
 * This class implements the add operation
 */
class Add : public Expression
{
private:
    Expression* leftOp;     //!< Pointer to left expression
    Expression* rightOp;    //!< Pointer to right expression
public:
    Add(Expression* leftOperand, Expression* rightOperand);     //!< @brief Constructor @param leftOperand  Left @ref Expression to be used by this operation @param rightOperand  Right @ref Expression to be used by this operation
    virtual ~Add();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // ADD_H
