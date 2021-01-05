cmake_minimum_required(VERSION 3.1)                              # Versión de CMAKE

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)      # Para cambiar la ruta del target
set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)    # Te generara un archivo makefile

# Le asignamos un nombre al proyecto
project(cmake-test)

# Configuración de compilación
set(CMAKE_CXX_STANDARD 17)                                                                      # Versión que usaremos del lenguaje
set(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=address -pedantic-errors -Wall -Wextra -DDEBUG -ggdb")    # Flags de compilación para modo debug
set(CMAKE_CXX_FLAGS_RELEASE "-Wall")                                                            # Flags para versión fuera de producción

# Source code
include_directories("fecha/src" "racional/src" "complejos/src")

file(GLOB SrcFecha
  "fechas/src/*.cc"
)

file(GLOB SrcComlejo
  "complejos/src/*.cc"
)

file(GLOB SrcRacional
  "racional/src/*.cc"
)

# Ejecutables
add_executable(fechas ${SrcFecha})
add_executable(racionales ${SrcRacional})
add_executable(complejo ${SrcComlejo})
