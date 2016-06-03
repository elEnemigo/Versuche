//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 2.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <iomanip>

int Variablen()
{
	int iErste=0;
	int iZweite=0;

	std::cout << "Number one: ";
	std::cin >> iErste;
	std::cout << "Number two: ";
	std::cin >> iZweite;


	/* Aufgabe 1 */
	int iSumme = iErste + iZweite;
	int iQuotient = iErste / iZweite;

	std::cout << "\nAufgabe 1" << std::endl;
	std::cout << "Addition= " << iSumme << std::endl;
	std::cout << "Division= " << iQuotient << std::endl;


	/* Aufgabe 2 */
	double dSumme = iErste + iZweite;
	double dQuotient = iErste / iZweite;

	std::cout << "\nAufgabe 2" << std::endl;
	std::cout << "Addition= " << dSumme << std::endl;
	std::cout << "Division= " << dQuotient << std::endl;


	/* Aufgabe 3 */
	double dSummeCast = (double)iErste + (double)iZweite;
	double dQuotientCast = (double)iErste / (double)iZweite;

	std::cout << "\nAufgabe 3" << std::endl;
	std::cout << "Addition = " << dSummeCast << std::endl;
	std::cout << "Division = " << dQuotientCast << std::endl;
    /* Ohne typecasting zum double werden die Berechnungen im Integer Datentyp
       ausgeführt, was bei Gewissen Berechnungen zu Präzisionsverlust führt. */


	/* Aufgabe 4 */
	std::string sVorname;
	std::string sNachname;

	std::cout << "\nAufgabe 4" << std::endl;
    std::cout << "First name: ";
	std::cin >> sVorname;
    std::cout << "Last name: ";
	std::cin >> sNachname;

	std::string sVornameName = sVorname + " " + sNachname;
	std::string sNameVorname = sNachname + ", " + sVorname;

	std::cout << "First name, second name: " << sVornameName << std::endl;
	std::cout << "Last name, first name: " << sNameVorname << std::endl;


	/* Aufgabe 5 */
    std::cout << "\nAufgabe 5" << std::endl;
    {
        /*a*/
        int iFeld[2] = {1, 2};
        /* iFeld[0] und iFeld[1] */

        /*b*/
        int spielfeld[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        /* spielfeld[0][0], spielfeld[0][1], spielfeld[0][2], spielfeld[1][0], ...etc */

        /*c*/
        std::cout << "c)" << std::endl;
        std::cout << "iFeld: ";
        for(int i = 0; i <= 1; i++)
        {
            std::cout << iFeld[i] << " ";
        }
        std::cout << "\nspielfeld:" << std::endl;
        for(int j = 0; j <= 2; j++)
        {
            for(int k = 0; k <= 2; k++)
            {
                std::cout << spielfeld[j][k] << " ";
            }
            std::cout << std::endl;
        }

        /*d*/
        const int iZweite = 1;
        std::cout << "d)" << std::endl;
        std::cout << "iZweite = " << iZweite << std::endl;
    }
    std::cout << "iZweite(ausserhalb des Blockes) = " << iZweite << std::endl;


	/* Aufgabe 6 */
	int iName1 = (int)sVorname.at(0);
	int iName2 = (int)sVorname.at(1);

    std::cout << "\nAufgabe 6" << std::endl;
	std::cout << "iName1 = " << iName1 << std::endl;
	std::cout << "iName2 = " << iName2 << std::endl;


	/* Aufgabe 7 */
	int pos1 = 0;
	int pos2 = 0;

	if(iName1 > 96 && iName1 < 123)
	{
		pos1 = iName1 - 96;
	}
	else if(iName1 > 64 && iName1 < 91)
	{
		pos1 = iName1 - 64;
	}

	if(iName2 > 96 && iName2 < 123)
	{
			pos2 = iName2 - 96;
	}
	else if(iName2 > 64 && iName2 < 91)
	{
			pos2 = iName2 - 64;
	}

    std::cout << "\nAufgabe 7" << std::endl;
	std::cout << "The first letter's position is: " << pos1 << std::endl;
	std::cout << "The second letter's position is: " << pos2 << std::endl;


	return 0;
}
