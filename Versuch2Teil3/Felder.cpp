#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
    Erste Zeile: Alphabet
    Zweite Zeile: For encryption
    Dritte Zeile: For decryption
 */
char lookup[3][26];

// Prototypes
void Init();
char Encrypt(char);             // Einzelnen char verschluesseln
string EncryptString(string);   // String verschluesseln
char Decrypt(char);             // Einzelnen char entschluesseln
string DecryptString(string);   // String entschluesseln


int main()
{
    // Aufgabe 2
    Init();
    for(int i = 0; i < 26; i++)
    {
        cout << lookup[0][i] << " | " << lookup[1][i] << " | " << lookup[2][i] << endl;
    }

    // Aufgabe 3
    char in;
    cout << "Enter a letter: ";
    cin >> in;
    cout << "Encrypted: " << Encrypt(in) << endl;

    // Aufgabe 4
    string sIn;
    cout << "Enter a word of five letters: ";
    cin >> sIn;
    cout << "Encrypted: " << EncryptString(sIn) << endl;

    // Aufgabe 6
    cout << "Enter an encrypted word of five letters: ";
    cin >> sIn;
    cout << "Decrypted: " << DecryptString(sIn) << endl;

    return 0;
}

void Init()
{
    //int tmp[26]; // Zeigt an ob ein Buchstabe bereits benutzt wurde | 0 = unbenutzt
    //int i;

    //srand(time(NULL));

    // A-Z in erste Zeile eintragen
    //for(i = 0; i <= 25; i++)
    //{
    //    lookup[0][i] = 65 + i;
    //    tmp[i] = 0;
    //}

    // Zufaellig Buchstaben in die zweite Zeile eintragen
    //for(i = 0; i <= 25; i++)
    //{
    //    int num = rand() % 26;
    //    if(tmp[num] == 0)
    //    {
    //        lookup[1][i] = 65 + num;
    //        lookup[2][num] = 65 + i;
    //        tmp[num] = 1;
    //    }
    //    else
    //        i--;
    //}

    // Lookup Tabelle generieren
    lookup[0][0] = 'A';
    lookup[0][1] = 'B';
    lookup[0][2] = 'C';
    lookup[0][3] = 'D';
    lookup[0][4] = 'E';
    lookup[0][5] = 'F';
    lookup[0][6] = 'G';
    lookup[0][7] = 'H';
    lookup[0][8] = 'I';
    lookup[0][9] = 'J';
    lookup[0][10] = 'K';
    lookup[0][11] = 'L';
    lookup[0][12] = 'M';
    lookup[0][13] = 'N';
    lookup[0][14] = 'O';
    lookup[0][15] = 'P';
    lookup[0][16] = 'Q';
    lookup[0][17] = 'R';
    lookup[0][18] = 'S';
    lookup[0][19] = 'T';
    lookup[0][20] = 'U';
    lookup[0][21] = 'V';
    lookup[0][22] = 'W';
    lookup[0][23] = 'X';
    lookup[0][24] = 'Y';
    lookup[0][25] = 'Z';

    lookup[1][0] = 'M';
    lookup[1][1] = 'O';
    lookup[1][2] = 'R';
    lookup[1][3] = 'E';
    lookup[1][4] = 'J';
    lookup[1][5] = 'D';
    lookup[1][6] = 'X';
    lookup[1][7] = 'C';
    lookup[1][8] = 'I';
    lookup[1][9] = 'T';
    lookup[1][10] = 'U';
    lookup[1][11] = 'P';
    lookup[1][12] = 'K';
    lookup[1][13] = 'G';
    lookup[1][14] = 'S';
    lookup[1][15] = 'Y';
    lookup[1][16] = 'B';
    lookup[1][17] = 'A';
    lookup[1][18] = 'Z';
    lookup[1][19] = 'H';
    lookup[1][20] = 'L';
    lookup[1][21] = 'W';
    lookup[1][22] = 'N';
    lookup[1][23] = 'F';
    lookup[1][24] = 'Q';
    lookup[1][25] = 'V';

    lookup[2][0] = 'R';
    lookup[2][1] = 'Q';
    lookup[2][2] = 'H';
    lookup[2][3] = 'F';
    lookup[2][4] = 'D';
    lookup[2][5] = 'X';
    lookup[2][6] = 'N';
    lookup[2][7] = 'T';
    lookup[2][8] = 'I';
    lookup[2][9] = 'E';
    lookup[2][10] = 'M';
    lookup[2][11] = 'U';
    lookup[2][12] = 'A';
    lookup[2][13] = 'W';
    lookup[2][14] = 'B';
    lookup[2][15] = 'L';
    lookup[2][16] = 'Y';
    lookup[2][17] = 'C';
    lookup[2][18] = 'O';
    lookup[2][19] = 'J';
    lookup[2][20] = 'K';
    lookup[2][21] = 'Z';
    lookup[2][22] = 'V';
    lookup[2][23] = 'G';
    lookup[2][24] = 'P';
    lookup[2][25] = 'S';
}

// Aufgabe 3
char Encrypt(char in)
{
    in = toupper(in);
    return lookup[1][(int)in - 65];
}

string EncryptString(string in)
{
    string out = "";

    //for (int i = 0; i < in.length(); i++)
    //    out += Encrypt(in.at(i));

    if (in.length() < 5)
        return "Error: String has less than five letters!";

    out += Encrypt(in.at(0));
    out += Encrypt(in.at(1));
    out += Encrypt(in.at(2));
    out += Encrypt(in.at(3));
    out += Encrypt(in.at(4));

    return out;
}

// Aufgabe 5
char Decrypt(char in)
{
    return lookup[2][(int)toupper(in) - 65];
}

string DecryptString(string in)
{
    string out = "";

    //for (int i = 0; i < in.length(); i++)
    //    out += Decrypt(in.at(i));

    if (in.length() < 5)
        return "Error: String has less than five letters!";

    out += Decrypt(in.at(0));
    out += Decrypt(in.at(1));
    out += Decrypt(in.at(2));
    out += Decrypt(in.at(3));
    out += Decrypt(in.at(4));

    return out;
}
