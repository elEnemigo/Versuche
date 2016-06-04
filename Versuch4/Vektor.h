//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 04: Einführung in die Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#ifndef Vektor_H
#define Vektor_H

#include <cmath>

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
      inline double getX() const { return x; };
      inline double getY() const { return y; };
      inline double getZ() const { return z; };
      inline double length() const { return sqrt(x*x+y*y+z*z); };
      inline void subtract(const Vektor *subtrahend) { this->x -= subtrahend->x; this->y -= subtrahend->y; this->z -= subtrahend->z; };

      inline static Vektor* add(const Vektor *augend, const Vektor *addend) { return new Vektor(augend->x + addend->x, augend->y + addend->y, augend->z + addend->z); };
      inline static bool isOrthogonal(const Vektor* vec1, const Vektor *vec2) { return (vec1->x*vec2->x + vec1->y*vec2->y + vec1->z*vec2->z) <= 0.01 && (vec1->x*vec2->x + vec1->y*vec2->y + vec1->z*vec2->z) >= -0.01; };

      void ausgabe() const;

      void rotateZ(const double rad);

      Vektor& operator+(const Vektor& rhs) { return *add(this, &rhs); }
      Vektor& operator-(const Vektor& rhs) { return *new Vektor(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z); }
      Vektor& operator=(const Vektor& rhs) { x = rhs.x; y = rhs.y; z = rhs.z; return *this; }
};

#endif
