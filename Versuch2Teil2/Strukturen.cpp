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

int main()
{
    // Lokale variablen
    Person nBenutzer, nKopieEinzeln, nKopieGesamt;
    Person *p;

    // Eingabe
    std::cout << "Ihr Nachname: ";
    std::cin >> nBenutzer.sNachname;
    std::cout << "Ihr Vorname: ";
    std::cin >> nBenutzer.sVorname;
    std::cout << "Ihr Geburtsjahr: ";
    std::cin >> nBenutzer.iGeburtsjahr;
    std::cout << "Ihr Alter: ";
    std::cin >> nBenutzer.iAlter;

    // Ausgabe
    p = &nBenutzer;
    std::cout << "Sie sind " << p->sVorname << " " << p->sNachname << ", geboren " << p->iGeburtsjahr << " (" << p->iAlter << " Jahre alt)" << std::endl;

    // Einzelkopie
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;

    // Gesamtkopie
    nKopieGesamt = nBenutzer;

    // Ausgabe
    p = &nKopieEinzeln;
    std::cout << "Einzelkopie: Sie sind " << p->sVorname << " " << p->sNachname << ", geboren " << p->iGeburtsjahr << " (" << p->iAlter << " Jahre alt)" << std::endl;
    p = &nKopieGesamt;
    std::cout << "Gesamtkopie: Sie sind " << p->sVorname << " " << p->sNachname << ", geboren " << p->iGeburtsjahr << " (" << p->iAlter << " Jahre alt)" << std::endl;

	return 0;

}
