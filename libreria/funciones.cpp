#include "headers.h"
using namespace std;
//paso punteros de los structs para poder guardarlos xq no se guardan si son estaticos, los archivos ya los tenes
//completar funciones leer, con un while leyendo archivo cargar datos a los punteros de struct con mem dinamica
//hacer el resize en las funciones "leer" para tener la cantidad de registros

void archivados(Ultima_consulta*& aux, Paciente*& aux2, int* tamactual, int* tamactual2) 
{
	ofstream fp;
	int i = 0, j = 0, k = 0;

	fp.open("Archivados.csv", ios::out); 
	if (!(fp.is_open()))
		return;
	fp << "DNI,Nombre,Apellido,Sexo,Estado,ObraSocial" << endl;

	while (fp) 
	{//no se si esta bien poner esto cuando se crea un archivo
		
		double diffecha = distanciafechas(aux);

		if (diffecha>=3652.5 && aux.presento == false) 
		{	//funcion mas de 10 anios
			fp << aux2[j].DNI << ",";
			for (i = j; i < *tamactual2; i++) 
			{
				for (k = 0; k < *tamactual; k++) 
				{
					if (aux2[i].DNI == aux[k].dni) 
					{
						fp << aux2[k].DNI << aux2[k].Nombre << "," << aux2[k].Apellido << "," << aux2[k].Sexo << "," << aux2[k].estado << "," << aux2[k].id_os << endl;
					}
					else 
					{
						continue;
					}
				}
			}
		}j++;
	}
	fp.close();
	return;
}

//funciones leer
bool Leer_Pacientes(Paciente*& aux, ifstream& paco)
{
	char coma = ' , ';
	string header;
	getline(paco, header);
	int i = 0;

	while (paco)
	{
		paco >> aux[i].DNI >> coma;
		getline(paco, aux[i].Nombre, coma);
		getline(paco, aux[i].Apellido, coma);
		paco >> aux[i].Sexo >> coma;
		paco >> aux[i].nacimiento.tm_mday >> coma;
		paco >> aux[i].nacimiento.tm_mon >> coma;
		paco >> aux[i].nacimiento.tm_year >> coma;
		getline(paco, aux[i].estado, coma);
		getline(paco, aux[i].id_os, coma);
		i++;
	}

	return true;
}

bool Leer_Contactos(Contacto*& aux, ifstream& contact)
{
	char coma = ' , ';
	string header;
	getline(contact, header);
	int i = 0;

	while (contact)
	{
		contact >> aux[i].DNI >> coma;
		getline(contact, aux[i].telefono, coma);
		getline(contact, aux[i].celular, coma);
		getline(contact, aux[i].direccion, coma);
		getline(contact, aux[i].mail, coma);
		i++;
	}

	return true;
}

bool Leer_Consultas(Ultima_consulta*& aux, ifstream& consul)
{
	char coma = ' , ';
	string header;
	getline(consul, header);
	int i = 0;

	while (consul)
	{
		consul >> aux[i].dni >> coma;
		consul >> aux[i].fechasolicitud.tm_mday >> coma;
		consul >> aux[i].fechasolicitud.tm_mon >> coma;
		consul >> aux[i].fechasolicitud.tm_year >> coma;
		consul >> aux[i].fechaturno.tm_mday >> coma;
		consul >> aux[i].fechaturno.tm_mon >> coma;
		consul >> aux[i].fechaturno.tm_year >> coma;
		consul >> aux[i].presento >> coma;
		getline(consul, aux[i].matriculamedica, coma);
		i++;
	}

	return true;
}

bool Leer_Medicos(medicos*& aux, ifstream& med)
{
	char coma = ' , ';
	string header;
	getline(med, header);
	int i = 0;

	while (med)
	{
		med >> aux[i].matricula >> coma;
		getline(med, aux[i].nombre, coma);
		getline(med, aux[i].apellido, coma);
		getline(med, aux[i].telefono, coma);
		getline(med, aux[i].especialidad, coma);
		med >> aux[i].activo >> coma;
		i++;
	}

	return true;
}
//arrancan los resize 
void resize_paciente(Paciente*& aux,int *tamactual)
{
	*tamactual = *tamactual + 1;
	int i = 0;
	Paciente* pac = new Paciente[*tamactual];

	while (i < *tamactual - 1 && *tamactual - 1 != 0) 
	{
		pac[i] = aux[i];
		i++;
	}	
	aux = pac;
	delete[]pac;

	return;
}

void resize_contactos(Contacto *&aux2, int* tamactual2) 
{
	*tamactual2 = *tamactual2 + 1;
	int i = 0;
	Contacto* cont = new Contacto[*tamactual2];

	while (i < *tamactual2 - 1 && *tamactual2 - 1 != 0) 
	{
		cont[i] = aux2[i];
		i++;
	}
	aux2 = cont;
	delete[]cont;
	
	return;
}

void resize_consultas(Ultima_consulta*& aux3, int* tamactual3) 
{
	*tamactual3 = *tamactual3 + 1;
	int i = 0;
	Ultima_consulta* consul = new Ultima_consulta[*tamactual3];

	while (i < *tamactual3 - 1 && *tamactual3 - 1 != 0) 
	{
		consul[i] = aux3[i];
		i++;
	}
	aux3 = consul;
	delete[]consul;
	
	return;
}

void resize_medicos(medicos*& aux4, int* tamactual4) 
{
	*tamactual4 = *tamactual4 + 1;
	int i = 0;
	medicos* med = new medicos[*tamactual4];

	while (i < *tamactual4 - 1 && *tamactual4 - 1 != 0) 
	{
		med[i] = aux4[i];
		i++;
	}
	aux4 = med;
	delete[]med;
	
	return;
}

void retornables(Paciente*& aux, int* tamactual, Ultima_consulta*& aux3, int* tamactual3, medicos*& aux4, int* tamactual4) 
{//checkea si esta muerto o internado




}

double distanciafechas(Ultima_consulta *&aux2) //cuando la llamemos en el main hay que meterla dentro de un for
{
	int i = 0;
	tm inicio = aux2[i].fechaturno; //es la fecha de la última consulta que tuvo programada el paciente
	time_t timer;   
	time(&timer);   //usamos el timer para tener la fecha y hora actual 
	//el mktime nos devuelve la cantidad de segundos a partir de la Época Unix (1 de Enero del 1970 00:00:00) hasta la fecha actual. 
	time_t y = mktime(&inicio);      //además, el mktime lo usamos para no tener que sumarle 1 al mes usando la estructura tm y tampoco hace falta sumarle 1900 al año.
	double diferencia = 0;
	if (y != (time_t)(-1))
	{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
		diferencia = difftime(timer, y) / (86400); //60*60*24    //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por día.
	}
	return diferencia;
}

void buscarpac(Paciente*& aux, Contacto*& aux2, int*tamactual, int*tamactual2) //no salida por consola
{
	int i = 0,j=0;
	for (i; i < *tamactual; i++) 
	{
		for (j; j < *tamactual2; j++) 
		{
			if (aux[i].DNI == aux2[j].DNI && aux[i].estado!= "fallecido")  
			{
			
			}
			
		}

	}
	
}

int consrandom(int maximo, int minimo)
{
	srand(time(NULL));
	int valor = rand() % (maximo - minimo) + minimo;
	return valor;
}

tm nuevacons()  //funcion para programar una nueva consulta aleatoria
{
	int minrand, horarand, diarand, mesrand, aniorand;
	minrand = consrandom(59, 0);
	horarand = consrandom(20, 6); //las horas en la libreria van de 0 a 23
	mesrand = consrandom(11, 0);  //los meses en la libreria van de 0 a 11
	aniorand = consrandom(126, 123);  //sumamos 122 para que sea mayor a 2022 ya que parte del 1900, en un rango de 3 anios

	int anio = 0;
	bool anio_bisiesto = bisiestos(anio);

	if (anio_bisiesto == true && mesrand == 1)
		diarand = consrandom(29, 1); //los dias del mes van de 0 a 31.
	else
		diarand = consrandom(28, 1);

	if (mesrand == 0 || mesrand == 2 || mesrand == 4 || mesrand == 6 || mesrand == 7 || mesrand == 9 || mesrand == 11)
		diarand = consrandom(31, 1);
	else if (mesrand != 1)
		diarand = consrandom(30, 1);

	tm consulta = { 0, minrand, horarand, diarand, mesrand, aniorand };

	return consulta; //Nos pasa la fecha de la consulta reprogramada.
}

bool bisiestos(int anio)
{
	Ultima_consulta UltConsul;
	if ((UltConsul.fechaturno.tm_year % 4) == 0 && (UltConsul.fechaturno.tm_year % 100) != 0)
		return true;
	else
		return false;
}