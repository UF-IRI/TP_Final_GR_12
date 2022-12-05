#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

struct Ultima_consulta
{
	unsigned int dni;
	tm fechasolicitud;  //usamos las estrucutras en tm ya que es el tipo d eestructura que usa la libreria ctime.
	tm fechaturno;
	int presento;
	string matriculamedica;
};

struct Contacto
{
	unsigned int DNI;
	string telefono;
	string celular;
	string direccion;
	string mail;
};

struct Paciente
{
	unsigned int DNI;
	string Nombre;
	string Apellido;
	char Sexo;
	tm nacimiento;
	string estado;
	string id_os;
};

struct medicos
{
	unsigned int matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	bool activo;
};

bool Leer_Pacientes(Paciente*& aux, ifstream& pac, int* tam1);
bool Leer_Contactos(Contacto*& aux, ifstream& contact, int* tam2);
bool Leer_Consultas(Ultima_consulta*& aux, ifstream& consul, int* tam3);
bool Leer_Medicos(medicos*& aux, ifstream& med, int* tam4);

void resize_paciente(Paciente auxpac, Paciente*& aux, int* tamactual);
void resize_contactos(Contacto auxcont, Contacto*& aux2, int* tamactual2);
void resize_consultas(Ultima_consulta auccons, Ultima_consulta*& aux3, int* tamactual3);
void resize_medicos(medicos auxmed, medicos*& aux4, int* tamactual4);

bool division_grupos(Paciente*& aux, int* tam1, Ultima_consulta*& aux2, int* tam2, Contacto*& aux3, int* tam3, medicos*& aux4, int* tam4,fstream &fp,fstream &fp2);
void cargararchivados(Paciente aux, fstream& fp);
void cargarrecup(Paciente aux, medicos aux2, Contacto aux3, fstream& fp);
int buscar(Paciente*& aux, int* tam, unsigned int dni);


//bool secretaria_pacientes(string Recuperables, int codigo, Paciente aux, string obrasocial);

void buscarpac(Paciente*& aux, Contacto*& aux2, int*tamactual,int*tamactual2);
bool distanciafechas(Ultima_consulta*& aux2, int pospaciente, Paciente*& aux, int* tam2);
tm ultcons(Ultima_consulta*& aux2, int pospaciente, Paciente*& aux, int* tam2);
int CantConsultas(Ultima_consulta*& aux2, int pospaciente, Paciente*& aux, int* tam2);
bool bisiestos(int anio);
int consrandom(int maximo, int minimo);
tm nuevacons();


