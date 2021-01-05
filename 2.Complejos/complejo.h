#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>

class Complejo {
 public:
  float real;
  float imaginary;

  Complejo();
  Complejo(float real, float imaginary);

  /**
   * @brief Suma dos números complejos
   * @param complejo_a Un número complejo
   * @param complejo_b Otro número complejo
   * @return Complejo Resultado de sumar dos números complejos
   */
  static Complejo Add(const Complejo& complejo_a, const Complejo& complejo_b);

  /**
   * @brief Resta dos números complejos
   * @param complejo_a Un número complejo
   * @param complejo_b Otro número complejo
   * @return Complejo Resultado de restar dos números complejos
   */
  static Complejo Sub(const Complejo& complejo_a, const Complejo& complejo_b);

  /**
   * @brief Imprime por pantalla el complejo
   */
  void Print();

  Complejo operator=(const Complejo& complejo);
};

#endif
