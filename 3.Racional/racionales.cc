#include <fstream>
#include <iostream>

#include "racionales.h"
#include "racional.h"

int main(int argc, char const *argv[]) {
  if (argc == 3) {
    std::string input_path = argv[1];
    std::string output_path = argv[2];
    Racional::ReadWrite(input_path, output_path);
  } else {
    ShowUsage();
  }

  return 0;
}

void ShowUsage() {
  std::cout << "Modo de uso: ./racionales fichero_entrada fichero_salida\n"
            << "Pruebe ./racionales --help para más información\n";
}
