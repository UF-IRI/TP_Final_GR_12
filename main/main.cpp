#include "iri.cpp"
#include "headers.h"
using namespace std;

int main() 
{
    ifstream fp, fp2, fp3, fp4;
    fstream fp5, fp6;

    string Pac = (BASE_PATH + "../data_files/input/Pacientes.csv"); 
    string Contact = (BASE_PATH + "../data_files/input/Contactos.csv");
    string Consult = (BASE_PATH + "../data_files/input/Consultas.csv");
    string Medic = (BASE_PATH + "../data_files/input/Medicos.csv");

    fp.open(Pac, ios::in);
    fp2.open(Contact, ios::in);
    fp3.open(Consult, ios::in);
    fp4.open(Medic, ios::in);
  
    if (!(fp.is_open()))
        return -10;
    int tamact1 = 0;
    Paciente* aux1 = new Paciente[tamact1];
    bool leerpac = Leer_Pacientes(aux1, fp, &tamact1);
    if (leerpac == false)
        return 0;

    if (!(fp2.is_open()))
        return -11;
    int tamact2 = 0;
    Contacto* aux2 = new Contacto[tamact2];
    bool leercontc = Leer_Contactos(aux2, fp2, &tamact2);
    if (leercontc == false)
        return -1;

    if (!(fp3.is_open()))
        return -12;
    int tamact3 = 0;
    Ultima_consulta* aux3 = new Ultima_consulta[tamact3];
    bool leerultcons = Leer_Consultas(aux3, fp3, &tamact3);
    if (leerultcons == false)
        return -2;

    if (!(fp4.is_open()))
        return -13;
    int tamact4 = 0;
    medicos* aux4 = new medicos[tamact4];
    bool leermed = Leer_Medicos(aux4, fp4, &tamact4);
    if (leermed == false)
        return -3;

    fp5.open("Archivados.csv", ios::out);
    fp6.open("Posibles_Recuperables.csv", ios::out);

    if (!(fp5.is_open() && fp6.is_open()))
        return 25;

    char coma = ',';
    fp5 << "DNI" << coma << "Nombre" << coma << "Apellido" << coma << "Sexo" << coma << "Natalicio" << coma << "Estado" << coma << "Obra social" << endl;
    fp6 << "DNI" << coma << "Nombre" << coma << "Apellido" << coma << "Telefono" << coma << "Celular" << coma << "Matricula" << coma << "NombreMed" << coma << "ApellidoMed" << coma << "TelefonoMed" << "Especialidad" << coma << "Activo" << endl;

    bool divgrupo = division_grupos(aux1, &tamact1, aux3, &tamact3, aux2, &tamact2, aux4, &tamact4, fp5, fp6);

    fp6.close();

    fp6.open("Posibles_Recuperables.csv", ios::in);

    if (!(fp6.is_open()))
        return 20;

    int tamact5 = 0;
    Pos_recp* aux5 = new Pos_recp[tamact5];
    bool leer_sec = secretaria_de_pacientes(aux5, fp6, &tamact5);
    
    tm *nueva_consulta=new tm;
    string *nueva_obra_social=new string;

   for (int i = 0; i < tamact5; i++)
   {
        contactar_pac(aux5[i],fp5,aux1,&tamact1,*nueva_consulta,*nueva_obra_social);

        cout << " La obra social actual del paciente " << aux5[i].DNI <<" es: " << nueva_obra_social << endl;
        cout << "La nueva fecha de consulta del paciente" << aux5[i].DNI << " es el: " << nueva_consulta << endl;
   }
    
    fp.close();
    fp2.close();
    fp3.close();
    fp4.close();
    fp5.close();
    fp6.close();

    delete[]aux1;
    delete[]aux2;
    delete[]aux3;
    delete[]aux4;
    delete[]aux5;
    
      return 10;
    
}
