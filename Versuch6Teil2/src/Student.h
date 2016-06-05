/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.2: STL
 *
 * Datei:  Student.h
 * Inhalt: Studentenklasse mit Merkmalen eines Studenten
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

//Student Class
/**
 * @brief This data type holds the attributes of a student
 */
class Student
{
  public:
	Student();
	Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string date);
	int getMatNr() const;
	std::ostream& ausgabe(std::ostream& out) const;
	bool operator == (const Student& stud) const;
	bool operator < (const Student& stud) const;
	bool operator > (const Student& stud) const;

  private:
	int matNr;
	std::string name;
	std::string firstname;
	std::string dateofbirth;
};

// Ausgabeoperator muss auﬂerhalb der Klasse definiert sein, weil er als linken Operand
// keine Instanz der Klasse besitzt, sondern meist "cout"
std::ostream& operator << (std::ostream& out, const Student& stud);


#endif // STUDENT_H

