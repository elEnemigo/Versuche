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

/**
 * @brief Class
 */
class Vektor
{
   public:
       //Konstruktor/Destruktor
      Vektor(double x, double y, double z);
      ~Vektor();

   private: //member
      double x;         ///< X value of vector
      double y;         ///< Y value of vector
      double z;         ///< Z value of vector

   public:
      inline double getX() const    ///< @brief Retrieves x-value  @return X-Value
      {
          return x;
      }
      inline double getY() const    ///< @brief Retrieves y-value  @return Y-Value
      {
          return y;
      }
      inline double getZ() const    ///< @brief Retrieves z-value  @return Z-Value
      {
          return z;
      }
      inline double length() const  ///< @brief Retrieves length of vector  @return length of this vector
      {
          return sqrt(x*x+y*y+z*z);
      }
      inline void subtract(const Vektor *subtrahend)    ///< @brief Subtracts subtrahend from this vector  @param subtrahend Subtrahend
      {
          this->x -= subtrahend->x;
          this->y -= subtrahend->y;
          this->z -= subtrahend->z;
      }

      inline static Vektor* add(const Vektor *augend, const Vektor *addend)     ///< @brief Returns the result of an addition of two vectors  @param augend Augend vector  @param addend Addend vector
      {
          return new Vektor(augend->x + addend->x, augend->y + addend->y, augend->z + addend->z);
      }
      inline static bool isOrthogonal(const Vektor* vec1, const Vektor *vec2)   ///< @brief Checks whether two vectors are orthogonal to one another.  @param vec1 First vector  @param vec2 Second vector  @return Returns true if vec1 is orthogonal to vec2. Otherwise false.
      {
          return (vec1->x*vec2->x + vec1->y*vec2->y + vec1->z*vec2->z) <= 0.01 && (vec1->x*vec2->x + vec1->y*vec2->y + vec1->z*vec2->z) >= -0.01;
      }

      void ausgabe() const;

      void rotateZ(const double rad);

      // Operators
      Vektor& operator+(const Vektor& rhs)      ///< @brief Operator "+". Adds to vectors together.  @return Returns new vector
      {
          return *add(this, &rhs);
      }
      Vektor& operator-(const Vektor& rhs)      ///< @brief Operator "-". Subtracts two vectors from one another.  @return Returns new vector
      {
          return *new Vektor(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
      }
      Vektor& operator=(const Vektor& rhs)      ///< @brief Operator "=". Copies rhs into this vector.  @return Returns this vector
      {
          x = rhs.x; y = rhs.y; z = rhs.z;
          return *this;
      }
};

#endif
