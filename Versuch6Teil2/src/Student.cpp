/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.2: STL
 *
 * Datei:  Student.cpp
 * Inhalt: Studentenklasse mit Merkmalen eines Studenten
 */

#include "Student.h"

/**
 * @brief Standard constructor of student
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
 * @param date The date of birth of the Student.
 */
Student::Student(const int matriculationnumber, const std::string name, const std::string firstname, const std::string date):
	matNr(matriculationnumber), name(name), firstname(firstname), dateofbirth(date)
{
}

// Insert your implementation here
/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return If two Students are the same true. Else false.
 */
bool Student::operator == (const Student& stud) const
{
	if (matNr == stud.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Operator for comparing two Students.
 * @param stud Student to compare with.
 * @return Returns true if lhs parameter has a HIGHER matNr then the rhs. Otherwise false.
 */
bool Student::operator > (const Student& stud) const
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
bool Student::operator < (const Student& stud) const
{
	if (matNr < stud.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Printing function.
 *
 * Prints all available information about the student
 *
 * @param out  Stream to output to.
 * @return Returns stream.
 */
std::ostream& Student::ausgabe(std::ostream& out) const
{
    return out << firstname << " " << name << ", MatNr. " << matNr
                << " geb. am " << dateofbirth;
}

/**
 * @brief Streaming operator.
 * @param out  Stream to output to.
 * @param student  Instance of class.
 * @return Returns stream.
 */
std::ostream& operator << (std::ostream& out, const Student& stud)
{
    return stud.ausgabe(out) << "\0";
}

/**
 * @brief Retrieving matriculation number.
 * @return Returns matriculation number.
 */
int Student::getMatNr() const
{
    return matNr;
}
