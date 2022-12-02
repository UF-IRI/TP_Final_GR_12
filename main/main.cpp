#include "iri.cpp"
#include "headers.h"
using namespace std;

int main() 
{
    ifstream fp, fp2, fp3, fp4;
    fp.open("Consultas.csv", ios::in);
    fp2.open("Contactos.csv", ios::in);
    fp3.open("Pacientes.csv", ios::in);
    fp4.open("Medicos.csv", ios::in);

    if (!(fp.is_open() || fp2.is_open() || fp3.is_open() || fp4.is_open()))
        return 0;

    if (!(is_empty(fp) || is_empty(fp2) || is_empty(fp3) || is_empty(fp4)))
        return -1;

    int tamact1 = 0;
    Paciente* aux1 = new Paciente[tamact1];
    bool leerpac = Leer_Pacientes(aux1, fp, &tamact1);
 
    int tamact2 = 0;
    Contacto* aux2 = new Contacto[tamact2];
    bool leercontc = Leer_Contactos(aux2, fp2, &tamact2);

    int tamact3 = 0;
    Ultima_consulta* aux3 = new Ultima_consulta[tamact3];
    bool leerultcons = Leer_Consultas(aux3, fp3, &tamact3);


    int tamact4 = 0;
    medicos* aux4 = new medicos[tamact4];
    bool leermed = Leer_Medicos(aux4, fp4, &tamact4);


    fp.close();
    fp2.close();
    fp3.close();
    fp4.close();
    
}
