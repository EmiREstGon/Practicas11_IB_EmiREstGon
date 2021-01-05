#include "fechas.h"
#include "fecha.h"

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {

  if (argc != 4){
    std::cerr << "Mala inserción de argumentos\n";
    ShowUsage();
    return -1;
  }

  Fecha fecha(argv[1]);
  int days_after = stoi(std::string(argv[2]));
  std::string file_path = argv[3];

  std::fstream file(file_path, std::ios_base::out);
  if (!file.is_open()) {
    std::cerr << "No se ha podido crear el fichero " << file_path << std::endl;
    return -1; 
  }

  for (int i = 1; i <= days_after; i++) {
    fecha.AddDays(i).Print(file);
  }

  return 0;
}

void ShowUsage() {
  std::cout << "Modo de uso: ./fechas dd/mm/aa N fichero_salida.txt" << std::endl
            << "Pruebe ./fechas --help para más información" << std::endl;
}
