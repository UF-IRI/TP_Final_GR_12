#include "iri.cpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <string>
#include <funciones.cpp>
using namespace std;

int main() 
{
    int* puntero;
    int p = 0;
    puntero = &p;

    int* puntero2;
    int p2 = 0;
    puntero2 = &p2;

    archivados("Consultas.csv","Pacientes.csv",puntero,puntero2);

    
}
