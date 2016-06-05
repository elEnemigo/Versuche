/*
 * Praktikum Informatik 1 MMXVI
 * Versuch 6.2: STL
 *
 * Datei:  main.cpp
 * Inhalt: Hauptprogramm
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"



/*
/**
 * @brief Compare function for qsort()
 *
 * @param p1  Pointer to first element of comparison
 * @param p2  Pointer to second element of comparison
 */
/*
int compare (const void* p1, const void* p2)
{
    Student* s1, *s2;

    s1 = (Student*)p1;
    s2 = (Student*)p2;

    if (s1 < s2)
        return -1;
    else if (s1 == s2)
        return 0;
    else
        return 1;
}
*/

/**
 * @brief Entrypoint
 */
int main()
{
    // Locals
    std::vector<Student> studVec;
    std::string matrikel;
    int matNr;
    std::istringstream *convert;

    // Put students into vector
	Student stud1(22222, "Born"      ,"Jessica", "16.03.1986");
	Student stud2(24528, "Rodenstock","Maxim"  , "09.02.1985");
	Student stud3(95420, "Schneider" ,"Petra"  , "29.12.1989");
	Student stud4(44523, "Baumeister","Siggi"  , "13.01.1979");
	Student stud5(12635, "Baumeister","Dinah"  , "07.06.1982");
	Student stud6(81237, "Simoneit"  ,"Harro"  , "30.10.1973");
	Student stud7(54879, "Soers"     ,"Irmchen", "01.06.1983");
	studVec.push_back(stud1);
    studVec.push_back(stud2);
    studVec.push_back(stud3);
    studVec.push_back(stud4);
    studVec.push_back(stud5);
    studVec.push_back(stud6);
    studVec.push_back(stud7);

    // Sort vector
    //qsort(studVec.data(), 7, sizeof(Student), compare);
    std::sort(studVec.begin(), studVec.end());

    // Print data
    for (unsigned int i = 0; i < studVec.size(); i++)
        std::cout << studVec.at(i) << std::endl;

    // Search for student and delete
    std::cout << "\nBitte geben Sie die Matrikelnummer des zu loeschenden Studenten an: ";
    std::cin >> matrikel;
    convert = new std::istringstream(matrikel);
    *convert >> matNr;
    std::cout << "Student mit der Matrikelnummer " << matNr;
    for (unsigned int i = 0; i < studVec.size(); i++)
    {
        if ( studVec.at(i).getMatNr() == matNr)
        {
            studVec.erase(studVec.begin()+i);
            std::cout << " wurde erfolgreich aus der Liste entfernt\n\n";

            // Print data
            for (unsigned int i = 0; i < studVec.size(); i++)
                std::cout << studVec.at(i) << std::endl;

            return 0;
        }
    }
    std::cout << " konnte in der Liste nicht gefunden werden\n";

	return 0;
}
