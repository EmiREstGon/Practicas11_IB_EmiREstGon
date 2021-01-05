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
#include "fecha.h"

Fecha::Fecha() {
  days_ = 0;
  month_ = 0;
  year_ = 0;
}

Fecha::Fecha(const std::string& fecha) {
  Parse(fecha);
}

Fecha::Fecha(int days, int month, int year) {
  days_ = days;
  month_ = month;
  year_ = year;
}

Fecha::~Fecha() {
}

void Fecha::Parse(const std::string& fecha) {
  if (fecha.size() != 10)
    std::cerr << "Mal formato de fecha\n";

  days_ = stoi(fecha.substr(0, 2));
  month_ = stoi(fecha.substr(3, 2));
  year_ = stoi(std::string(fecha.begin() + 6, fecha.begin() + fecha.size()));
  Check();
}

void Fecha::Check() {
  if (!(days_ > 0 && days_ <= DaysInMonth()))
    std::cerr << "Mala declaración de días" << std::endl;
  
  if (!(month_ > 0 && month_ <= 12))
    std::cerr << "Mala declaración de mes" << std::endl;
}

bool Fecha::IsLeapYear() {
  return Fecha::IsLeapYear(year_);
}

int Fecha::DaysInMonth() {
  return Fecha::DaysInMonth(month_, year_);
}

Fecha Fecha::AddDays(int days_to_add) {
  int days = days_ + days_to_add;
  int month = month_;
  int year = year_;

  while (days > Fecha::DaysInMonth(month, year)) {
    days -= Fecha::DaysInMonth(month, year);
    ++month;
    if (month > 12){
      ++year;
      month = 1;
    }
  }
  return Fecha(days, month, year);
}

std::ostream& Fecha::Print(std::ostream& os) {
  os << days_ << "/" << month_ << "/" << year_ << std::endl;
  return os;
}

bool Fecha::IsLeapYear(int year) {
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    return true;
  else
    return false;
}

int Fecha::DaysInMonth(int month, int year) {
  if (month == 2) {
    if (Fecha::IsLeapYear(year))
      return 29;
    else
      return 28;
  } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    return 31;
  else
    return 30;
}
