#include "complejos.h"

#include <iostream>

#include "complejo.h"

int main() {
  Complejo complejo1{4, 5}, complejo2{7, -8};
  Complejo resultado;
  resultado = Complejo::Add(complejo1, complejo2);
  resultado.Print();
  resultado = Complejo::Sub(complejo1, complejo2);
  resultado.Print();
  return 0;
}
