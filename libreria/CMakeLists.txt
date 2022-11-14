## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_library(libreria funciones.cpp headers.h)
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_include_directories(libreria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
