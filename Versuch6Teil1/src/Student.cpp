/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.1: Templates und Überladen von Operatoren
 *
 * Datei:  Student.cpp
 * Inhalt: Studentenklasse mit Merkmalen eines Studenten
 */

#include "Student.h"

/**
 * @brief Standard constructor of Student
 */
Student::Student()
{
	matNr = 0;
}

/**
 * @brief Constructor
 * @param matriculationnumber The matriculation number of the student.
 * @param name The name of the Student.
 * @param firstname The first name of the Student.
 */
Student::Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string birthday):
	matNr(matriculationnumber), name(name), firstname(firstname), date_of_birth(birthday)
{
}

/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return If two Students are the same true. Else false.
 */
bool Student::operator == (const Student& stud)
{
	if (matNr == stud.matNr)
		return true;
	else
		return false;
}

// Insert your implementation here
/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return Returns true if lhs parameter has a HIGHER matNr then the rhs, or if they are equal. Otherwise false.
 */
bool Student::operator >= (const Student& stud)
{
	if (matNr >= stud.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return Returns true if lhs parameter has a LOWER matNr then the rhs, or if they are equal. Otherwise false.
 */
bool Student::operator <= (const Student& stud)
{
	if (matNr <= stud.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return Returns true if lhs parameter has a HIGHER matNr then the rhs. Otherwise false.
 */
bool Student::operator > (const Student& stud)
{
	if (matNr > stud.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return Returns true if lhs parameter has a LOWER matNr then the rhs. Otherwise false.
 */
bool Student::operator < (const Student& stud)
{
	if (matNr < stud.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Streaming operator.
 * @param out  Stream to output to.
 * @param student  Instance of class.
 * @return Returns stream.
 */
std::ostream& operator << (std::ostream& out, const Student& student)
{
    return out << student.firstname << " " << student.name << ", MatNr. " << student.matNr
                << " geb. am " << student.date_of_birth;
}
