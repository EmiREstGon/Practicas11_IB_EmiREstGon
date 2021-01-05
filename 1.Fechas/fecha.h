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
#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string>

class Fecha {
 public:
  Fecha();

  /**
   * @brief Construye un fecha en base a una cadena con formato dd/mm/aaaa
   * @param fecha cadena
   */
  Fecha(const std::string& fecha);
  Fecha(int days, int month, int year);
  ~Fecha();

  /**
   * @brief Comprueba si el año de la fecha es bisiesto
   * @return true si sí
   * @return false si no
   */
  bool IsLeapYear();
  int DaysInMonth();

  /**
   * @brief Suma N días a la fecha actual sin modificarla
   * @param days_to_add días a sumar a la fecha actual
   * @return Fecha Fecha con la suma de días
   */
  Fecha AddDays(int days_to_add);

  /**
   * @brief Imprime el contenido de la clase en un fichero o pantalla
   * @param os Stream
   * @return std::ostream& Stream
   */
  std::ostream& Print(std::ostream& os);

  /**
   * @brief Calcula si un año es bisiesto
   * @param month Año en el cual queremos saber si es bisiesto
   * @return bool true si sí : false
   */
  static bool IsLeapYear(int yeat);

  /**
   * @brief Calcula cuantos días tiene un mes
   * @param month Mes en el cual queremos saber cuantos días tiene
   * @param year Año para comprobar si es bisiesto
   * @return int Número de días
   */
  static int DaysInMonth(int month, int year);

 private:
  /**
  * @brief Parsea la fecha dada para codificarla a la estructura de la clase
  * @param fecha string con el formato: dd/mm/aaaa
  */
  void Parse(const std::string& fecha);

  /**
   * @brief Comprueba que los días y meses tienen coherencia entre ellos.
   * En caso de no serlo, salta un mensaje de error.
   */
  void Check();

 private:
  int days_;
  int month_;
  int year_;
};

#endif
