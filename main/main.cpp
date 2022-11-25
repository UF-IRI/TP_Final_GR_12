
#include "headers.h"
using namespace std;

int main() 
{
    ifstream fp, fp2, fp3, fp4;
    fp.open("Consultas.csv", ios::in);
    fp2.open("Contactos.csv", ios::in);
    fp3.open("Pacientes.csv", ios::in);
    fp4.open("Medicos.csv", ios::in);

    if (!(fp.is_open() && fp2.is_open() && fp3.is_open() && fp4.is_open()))
        return 0;

    if (!(is_empty(fp) && is_empty(fp2) && is_empty(fp3) && is_empty(fp4)))
        return -1;

    fp.close();
    fp2.close();
    fp3.close();
    fp4.close();
    
}
