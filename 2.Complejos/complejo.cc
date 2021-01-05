#include "complejo.h"

Complejo::Complejo() {
  real = 0;
  imaginary = 0;
}

Complejo::Complejo(float real, float imaginary) {
  this->real = real;
  this->imaginary = imaginary;
}

Complejo Complejo::Add(const Complejo& complejo_a, const Complejo& complejo_b) {
  return Complejo(complejo_a.real + complejo_b.real, complejo_a.imaginary + complejo_b.imaginary);
}

Complejo Complejo::Sub(const Complejo& complejo_a, const Complejo& complejo_b) {
  return Complejo(complejo_a.real - complejo_b.real, complejo_a.imaginary - complejo_b.imaginary);
}

void Complejo::Print() {
  std::cout << real << " " << imaginary << "i" << std::endl;
}

Complejo Complejo::operator=(const Complejo& complejo) {
  real = complejo.real;
  imaginary = complejo.imaginary;
  return *this;
}
