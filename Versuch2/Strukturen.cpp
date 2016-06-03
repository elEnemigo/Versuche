/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 2.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

struct Person
{
    std::string sNachname;
    std::string sVorname;
    int iGeburtsjahr;
    int iAlter;
};

int Strukturen()
{
    Person nBenutzer, nKopieEinzeln, nKopieGesamt;
    Person *p;

    std::cout << "Ihr Nachname: ";
    std::cin >> nBenutzer.sNachname;
    std::cout << "Ihr Vorname: ";
    std::cin >> nBenutzer.sVorname;
    std::cout << "Ihr Geburtsjahr: ";
    std::cin >> nBenutzer.iGeburtsjahr;
    std::cout << "Ihr Alter: ";
    std::cin >> nBenutzer.iAlter;

    p = &nBenutzer;
    std::cout << "Sie sind " << p->sVorname << " " << p->sNachname << ", geboren " << p->iGeburtsjahr << " (" << p->iAlter << " Jahre alt)" << std::endl;

    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;

    nKopieGesamt = nBenutzer;

    p = &nKopieEinzeln;
    std::cout << "Sie sind " << p->sVorname << " " << p->sNachname << ", geboren " << p->iGeburtsjahr << " (" << p->iAlter << " Jahre alt)" << std::endl;

    p = &nKopieGesamt;
    std::cout << "Sie sind " << p->sVorname << " " << p->sNachname << ", geboren " << p->iGeburtsjahr << " (" << p->iAlter << " Jahre alt)" << std::endl;

	return 0;

}
