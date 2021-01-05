#include "racional.h"

//dividento / divisor

Racional::Racional(void) {
  numerator_ = 0;
  denominator_ = 1;
}

Racional::Racional(int numerator, int denominator) {
  assert(denominator != 0);  // denominador = 0
  numerator_ = numerator;
  denominator_ = denominator;
}

Racional::~Racional(void) {}

Racional Racional::Add(const Racional& rational) {
  int denominator = denominator_ * rational.GetDenominator();
  return Racional((numerator_ * (denominator / denominator_)) + (rational.GetNumerator() * (denominator / rational.GetDenominator())), denominator);
}

Racional Racional::Substrac(const Racional& rational) {
  int denominator = denominator_ * rational.GetDenominator();
  return Racional((numerator_ * (denominator / denominator_)) - (rational.GetNumerator() * (denominator / rational.GetDenominator())), denominator);
}

Racional Racional::Multiplication(const Racional& rational) {
  return Racional(numerator_ * rational.GetNumerator(), denominator_ * rational.GetDenominator());
}

Racional Racional::Division(const Racional& rational) {
  return Racional(numerator_ * rational.GetDenominator(), denominator_ * rational.GetNumerator());
}

int Racional::GetNumerator(void) const {
  return numerator_;
}

int Racional::GetDenominator(void) const {
  return denominator_;
}

void Racional::SetNumerator(int numerator) {
  numerator_ = numerator;
}

void Racional::SetDenominator(int denominator) {
  assert(denominator != 0);  // denominador = 0
  denominator_ = denominator;
}

std::ostream& Racional::Print(std::ostream& os) const {
  os << numerator_ << '/' << denominator_;
  return os;
}

void Racional::ReadWrite(const std::string& path_input, const std::string& path_output) {
  std::fstream input_file(path_input, std::ios_base::in);
  std::fstream output_file(path_output, std::ios_base::out);

  if (input_file.is_open() && output_file.is_open()) {
    while (!input_file.eof()) {
      int arriba1, abajo1, arriba2, abajo2;
      char basura;

      input_file >> arriba1 >> basura >> abajo1;
      input_file >> arriba2 >> basura >> abajo2;

      Racional a(arriba1, abajo1);
      Racional b(arriba2, abajo2);

      output_file << '\n';

      output_file << arriba1 << '/' << abajo1 << " \t+\t" << arriba2 << '/' << abajo2
         << " = " << a.Add(b) << '\n';

      output_file << arriba1 << '/' << abajo1 << " \t-\t" << arriba2 << '/' << abajo2
         << " = " << a.Substrac(b) << '\n';

      output_file << arriba1 << '/' << abajo1 << " \t*\t" << arriba2 << '/' << abajo2
         << " = " << a.Multiplication(b) << '\n';

      output_file << arriba1 << '/' << abajo1 << " \t/\t" << arriba2 << '/' << abajo2
         << " = " << a.Division(b) << '\n';
    }
  }

  input_file.close();
  output_file.close();
}

bool Racional::IsEqual(const Racional& rational) {
  return abs((double)(numerator_ / denominator_) - (double)(rational.GetNumerator() / rational.GetDenominator())) <= DBL_EPSILON;
}

bool Racional::IsLower(const Racional& rational) {
  return (numerator_ / denominator_) < (rational.GetNumerator() / rational.GetDenominator());
}

bool Racional::IsGrather(const Racional& rational) {
  return (numerator_ / denominator_) < (rational.GetNumerator() / rational.GetDenominator());
}

std::ostream& operator<<(std::ostream& os, const Racional& Racional) {
  return Racional.Print(os);
}

Racional Racional::operator=(const Racional& rational) {
  numerator_ = rational.GetNumerator();
  denominator_ = rational.GetDenominator();
  return *this;
}
