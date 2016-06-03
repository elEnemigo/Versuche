//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 04: Einführung in die Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#ifndef Vektor_H
#define Vektor_H

class Vektor
{
   public: //Konstruktor/Destruktor
      Vektor(double x, double y, double z);
      ~Vektor();

   private: //member
      double x;
      double y;
      double z;

   public:
      void ausgabe();
};

#endif
