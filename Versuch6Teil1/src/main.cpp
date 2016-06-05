/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.1: Templates und Überladen von Operatoren
 *
 * Datei:  main.cpp
 * Inhalt: Hauptprogramm
 */

#include <iostream>
#include <string>
#include "Student.h"
#include "StackSpeicher.h"

/**
 * @brief Entrypoint
 */
int main()
{

	Student stud1(222222, "Lustig", "Peter", "11.04.1995");
	Student stud2(222222, "Lustig", "Peter", "11.04.1995");
	std::cout << stud1 << std::endl;
	if (stud1 == stud2)
	{
		std::cout << "Stud1 und Stud2 sind gleich" << std::endl;
	}
	else
	{
		std::cout << "Stud1 und Stud2 sind nicht gleich" << std::endl;
	}
    std::cout << std::endl;

	StackSpeicher<7, Student> stackSpeicher;
    Student *student = new Student(34567, "Simoneit", "Harro", "21.11.1991");
    stackSpeicher.push(*student);
	student = new Student(12345, "Baumeister", "Siggi", "11.04.1995");
    stackSpeicher.push(*student);
    student = new Student(23451, "Rodenstock", "Walter", "01.06.1975");
    stackSpeicher.push(*student);
    student = new Student(32357, "Zuckerberg", "Marc", "01.06.1975");
    stackSpeicher.push(*student);
    student = new Student(73356, "Stossel", "John", "01.06.1975");
    stackSpeicher.push(*student);
    student = new Student(41128, "Yiannapulous", "Milo", "01.06.1975");
    stackSpeicher.push(*student);
    student = new Student(77853, "du Pont de Nemours", "Eleuthere Irenee", "01.06.1975");
    stackSpeicher.push(*student);
    stackSpeicher.sort();

    std::cout << stackSpeicher;

	return 0;
}
