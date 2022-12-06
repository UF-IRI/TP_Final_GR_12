#include "iri.cpp"
#include "headers.h"
using namespace std;

int main() 
{
    ifstream fp, fp2, fp3, fp4;
    fstream fp5, fp6;
    fp.open("Pacientes.csv", ios::in);
    fp2.open("Contactos.csv", ios::in);
    fp3.open("Consultas.csv", ios::in);
    fp4.open("Medicos.csv", ios::in);
    fp5.open("Archivados.csv", ios::out);
    fp6.open("Posibles_Recuperables.csv", ios::out);

   
    if (!(fp.is_open() && fp2.is_open() && fp3.is_open() && fp4.is_open()&& fp5.is_open()&&fp6.is_open()))
        return 0;
    fp5 << "DNI,Nombre,Apellido,Sexo,Natalicio,Estado,Obra_social";
    fp6 << "Nombre,Apellido,Telefono,Celular,Matricula,NombreMed,ApellidoMed,TelefonoMed,Especialidad,Activo";


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

    bool divgrupo = division_grupos(aux1,&tamact1,aux3,&tamact3,aux2,&tamact2,aux4,&tamact4,fp5,fp6);

    fp6.close();

    fp6.open("Posibles_Recuperables.csv", ios::in);

    if (!(fp6.is_open()))
        return 0;

    int tamact5 = 0;
    Pos_recp* aux5 = new Pos_recp[tamact5];
    bool leermed = secretaria_de_pacientes(aux5, fp6, &tamact5);
    

    fp.close();
    fp2.close();
    fp3.close();
    fp4.close();
    fp5.close();
  
    return 0;
    
}
