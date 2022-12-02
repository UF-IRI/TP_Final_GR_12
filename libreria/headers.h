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
	bool presento;
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
//void cargar_archivos(string Pacientes, string Contactos, string Consultas, string Medicos, string ObraSocial);
//bool secretaria_pacientes(string Recuperables, int codigo, Paciente aux, string obrasocial);
void buscarpac(Paciente*& aux, Contacto*& aux2, int*tamactual,int*tamactual2);
void archivados(Ultima_consulta*& aux, Paciente*& aux2, int* tamactual, int* tamactual2);

double distanciafechas(Ultima_consulta*& aux2);
int consrandom(int maximo, int minimo);
tm nuevacons();
bool bisiestos(int anio);
