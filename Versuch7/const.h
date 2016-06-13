/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 07: Taschenrechner
 *
 * Datei:  const.h
 * Inhalt: Headerdatei Klasse Const
 */

#ifndef CONST_H
#define CONST_H

/**
 * @brief Const class. Inherits from @ref Expression
 *
 * This class stores only a double
 */
class Const : public Expression
{
private:
    double value;   //!< Stores constant value
public:
    Const(double val);      //!< @brief Constructor @param val  Value to be stored in this instance
    virtual ~Const();
    virtual double evaluate() const;
    virtual std::string print() const;
};


#endif // CONST_H
