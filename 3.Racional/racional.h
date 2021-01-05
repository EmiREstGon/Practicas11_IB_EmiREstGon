/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Emi Est Gon
 * @date 5.jan.2021
 *
 */
#ifndef RACIONAL_H
#define RACIONAL_H

#include <cassert>
#include <cfloat>
#include <cmath>
#include <fstream>
#include <iostream>

class Racional {
 public:
  Racional(void);
  Racional(int numerator, int denominator);

  ~Racional(void);

  Racional operator=(const Racional& rational);
  friend std::ostream& operator<<(std::ostream& os, const Racional& racional);

  /**
   * @brief Suma dos números racionales. El propio de la clase y otro como argumento
   * @param rational Número racional utilizado para sumar
   * @return Racional Resultado de la suma
   */
  Racional Add(const Racional& rational);

  /**
   * @brief Resta dos números racionales. El propio de la clase y otro como argumento
   * @param rational Número racional utilizado para restar
   * @return Racional Resultado de la resta
   */
  Racional Substrac(const Racional& rational);

  /**
   * @brief Multiplicación de dos números racionales. El propio de la clase y otro como argumento
   * @param rational Número racional utilizado para multiplicar
   * @return Racional Resultado de la Multiplicación
   */
  Racional Multiplication(const Racional& rational);

  /**
   * @brief División de de dos números racionales. El propio de la clase y otro como argumento
   * @param rational Número racional utilizado para dividir
   * @return Racional Resultado de la División
   */
  Racional Division(const Racional& rational);

  int GetNumerator(void) const;
  int GetDenominator(void) const;

  void SetNumerator(int numerator);
  void SetDenominator(int denominator);

  /**
   * @brief Imprime por fichero o por stream
   * @param os stream
   * @return std::ostream& stream
   */
  std::ostream& Print(std::ostream& os) const;

  /**
   * @brief Lee de un fichero números complejos y hace todas las operaciones posibles
   * para luego dejarlos en otro
   * @param path_input ruta del fichero de entrada
   * @param path_output ruta del fichero de salida
   */
  static void ReadWrite(const std::string& path_input, const std::string& path_output);

  /**
   * @brief Comprueba si dos racionales son iguales
   * @param rational Racional a comparar
   */
  bool IsEqual(const Racional& rational);

  /**
   * @brief Comprueba si el racional de la clase es menor al dado
   * @param rational Racional a comparar
   */
  bool IsLower(const Racional& rational);

  /**
   * @brief Comprueba si el racional de la clase es mayor al dado
   * @param rational Racional a comparar
   */
  bool IsGrather(const Racional& rational);

 private:
  int numerator_;
  int denominator_;
};

#endif
