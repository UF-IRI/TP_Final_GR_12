#include "headers.h"
using namespace std;
//paso punteros de los structs para poder guardarlos xq no se guardan si son estaticos, los archivos ya los tenes
//completar funciones leer, con un while leyendo archivo cargar datos a los punteros de struct con mem dinamica
//hacer el resize en las funciones "leer" para tener la cantidad de registros


bool Leer_Pacientes(Paciente*& aux, ifstream& pac, int* tam1)
{
	if (aux == nullptr||tam1==nullptr)
		return false;

	Paciente auxpac;
	char coma = ' , ';
	string header;
	getline(pac, header);

	while (pac)
	{
		pac>> auxpac.DNI >> coma;
		getline(pac, auxpac.Nombre, coma);
		getline(pac, auxpac.Apellido, coma);
		pac>> auxpac.Sexo >> coma;
		pac>> auxpac.nacimiento.tm_mday >> coma;
		pac>> auxpac.nacimiento.tm_mon >> coma;
		pac>> auxpac.nacimiento.tm_year >> coma;
		getline(pac, auxpac.estado, coma);
		getline(pac, auxpac.id_os, coma);

		resize_paciente(auxpac, aux, tam1);

	}


	return true;
}

bool Leer_Contactos(Contacto*& aux, ifstream& contact, int* tam2)
{
	if (aux == nullptr||tam2==nullptr)
		return false;
	char coma = ' , ';
	string header;
	Contacto auxcont;

	getline(contact, header);


	while (contact)
	{
		contact >> auxcont.DNI >> coma;
		getline(contact, auxcont.telefono, coma);
		getline(contact, auxcont.celular, coma);
		getline(contact, auxcont.direccion, coma);
		getline(contact, auxcont.mail, coma);
	
		resize_contactos(auxcont, aux, tam2);
	}


	return true;
}

bool Leer_Consultas(Ultima_consulta*& aux, ifstream& consul, int* tam3)
{
	if (aux == nullptr||tam3==nullptr)
		return false;

	char coma = ' , ';
	string header;
	Ultima_consulta auxconsul;
	getline(consul, header);

	while (consul)
	{
		consul >> auxconsul.dni >> coma;
		consul >> auxconsul.fechasolicitud.tm_mday >> coma;
		consul >> auxconsul.fechasolicitud.tm_mon >> coma;
		consul >> auxconsul.fechasolicitud.tm_year >> coma;
		consul >> auxconsul.fechaturno.tm_mday >> coma;
		consul >> auxconsul.fechaturno.tm_mon >> coma;
		consul >> auxconsul.fechaturno.tm_year >> coma;
		consul >> auxconsul.presento >> coma;
		getline(consul, auxconsul.matriculamedica, coma);
	
		resize_consultas(auxconsul, aux, tam3);
	}

	return true;
}

bool Leer_Medicos(medicos*& aux, ifstream& med, int* tam4)
{
	if (aux == nullptr || tam4 == nullptr)
		return false;

	char coma = ' , ';
	string header;
	medicos auxmed;
	getline(med, header);
	
	while (med)
	{
		med >> auxmed.matricula >> coma;
		getline(med, auxmed.nombre, coma);
		getline(med, auxmed.apellido, coma);
		getline(med, auxmed.telefono, coma);
		getline(med, auxmed.especialidad, coma);
		med >> auxmed.activo >> coma;

		resize_medicos(auxmed, aux, tam4);
	}


	return true;
}
//arrancan los resize 
void resize_paciente(Paciente auxpac,Paciente*& aux,int *tamactual)
{
	
	*tamactual = *tamactual + 1;
	int i = 0;
	Paciente* pac = new Paciente[*tamactual];

	while (i < *tamactual - 1 && *tamactual - 1 != 0) 
	{
		pac[i] = aux[i];
		i++;
	}	
	pac[*tamactual - 1] = auxpac;
	delete[]aux;
	aux = pac;

	return;
}

void resize_contactos(Contacto auxcont,Contacto *&aux2, int* tamactual2) 
{
	*tamactual2 = *tamactual2 + 1;
	int i = 0;
	Contacto* cont = new Contacto[*tamactual2];

	while (i < *tamactual2 - 1 && *tamactual2 - 1 != 0) 
	{
		cont[i] = aux2[i];
		i++;
	}
	cont[*tamactual2 - 1] = auxcont;
	delete[]aux2;
	aux2 = cont;

	return;
}

void resize_consultas(Ultima_consulta auccons,Ultima_consulta*& aux3, int* tamactual3) 
{
	*tamactual3 = *tamactual3 + 1;
	int i = 0;
	Ultima_consulta* consul = new Ultima_consulta[*tamactual3];

	while (i < *tamactual3 - 1 && *tamactual3 - 1 != 0) 
	{
		consul[i] = aux3[i];
		i++;
	}
	consul[*tamactual3 - 1] = auccons;
	delete[]aux3;
	aux3 = consul;
	
	return;
}

void resize_medicos(medicos auxmed,medicos*& aux4, int* tamactual4) 
{
	*tamactual4 = *tamactual4 + 1;
	int i = 0;
	medicos* med = new medicos[*tamactual4];

	while (i < *tamactual4 - 1 && *tamactual4 - 1 != 0) 
	{
		med[i] = aux4[i];
		i++;
	}
	med[*tamactual4 - 1] = auxmed;
	delete[]aux4;
	aux4 = med;

	return;
}

//Ahora creamos funcion para dividir en grupos segun lo buscado, y crear los archivos.
bool division_grupos(Paciente*& aux, int* tam1, Ultima_consulta*& aux2, int* tam2,Contacto*& aux3,int*tam3,medicos*&aux4, int *tam4, fstream &fp,fstream &fp2 )
{

	if (aux == nullptr || tam1 == nullptr || aux2 == nullptr || tam2 == nullptr)
		return false;

	int i = 0,j=0,pospac,posmed,poscont;


	for (i = 0; i < *tam1; i++)
	{
		if (aux[i].estado == "fallecido")
			cargararchivados(aux[i], fp);
		else  {
			for (j = 0; j < *tam2; j++) {

				if (aux2[j].presento == 0 && distanciafechas(aux2, j, aux, tam1))//TAM 1
				{
					pospac = buscarpac(aux, tam1, aux2[j].dni);
					cargararchivados(aux[pospac], fp);
				}
				else//hacer buscar con dni medico y conatcto

					poscont = buscarcont(aux3, tam3, aux[i].DNI);
					posmed = buscarmed(aux4,tam4,aux2,tam2,aux,i,tam1);
       		
					cargarrecup(aux[i],aux4[posmed],aux3[poscont],fp2);
			}
		}
	
		}
	return true;
	}

int buscarpac(Paciente*& aux, int* tam1, unsigned int dni) 
{
	int i = 0;
	for (i = 0; i < *tam1; i++) {
		if (dni == aux[i].DNI)
			return i;
	}
}

int buscarcont(Contacto*& aux, int* tam3, unsigned int dni)
{
	int i = 0;
	for (i = 0; i < *tam3; i++) {
		if (dni == aux[i].DNI)
			return i;
	}
}

int buscarmed(medicos*& aux4, int* tamactual4, Ultima_consulta*& aux2, int* tam2, Paciente*& aux, int pos, int* tam)
{
	int i = 0;
	tm ulti_consul;
	for (i = 0; i < *tam2; i++) {
		if (aux[pos].DNI == aux2[i].dni)
		{
			ulti_consul = ultcons(aux2, i, aux, tam);




		}

	}
}
	void cargararchivados(Paciente aux, fstream & fp)
	{
		fp << aux.DNI << "," << aux.Nombre << "," << aux.Apellido << "," << aux.Sexo << "," << aux.nacimiento.tm_mday << "," << aux.nacimiento.tm_mon << "," << aux.nacimiento.tm_year << "," << aux.estado << "," << aux.id_os;
		return;
	}

	void cargarrecup(Paciente aux, medicos aux2, Contacto aux3, fstream & fp) {
		fp << aux.Nombre << "," << aux.Apellido << "," << aux3.telefono << "," << aux3.celular << "," << aux2.matricula << "," << aux2.nombre << "," << aux2.apellido << "," << aux2.telefono << "," << aux2.especialidad << "," << aux2.activo;
		return;

	}



	bool distanciafechas(Ultima_consulta * &aux2, int pospaciente, Paciente * &aux, int* tam2)//cuando la llamemos en el main hay que meterla dentro de un for
	{
		bool masdediez;
		tm inicio = ultcons(aux2, pospaciente, aux, tam2); //es la fecha de la última consulta que tuvo programada el paciente
		time_t timer;
		time(&timer);   //usamos el timer para tener la fecha y hora actual 
		//el mktime nos devuelve la cantidad de segundos a partir de la Época Unix (1 de Enero del 1970 00:00:00) hasta la fecha actual. 
		time_t y = mktime(&inicio);      //además, el mktime lo usamos para no tener que sumarle 1 al mes usando la estructura tm y tampoco hace falta sumarle 1900 al año.
		double diferencia = 0;
		if (y != (time_t)(-1))
		{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
			diferencia = difftime(timer, y) / (86400); //60*60*24    //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por día.
		}
		if (diferencia / 365.25 > 10)
			return true;
		else
			return false;

	}

	tm ultcons(Ultima_consulta*& aux2, int pospaciente, Paciente*& aux, int* tam2)
	{
		tm consulta;
		time_t timer;
		time(&timer);
		time_t consultita;
		tm ultconsul;
		double min = 0;
		double diff = 0;
		int i = 0;

		for (i = 0; i < *tam2; i++)
		{
			if (aux[i].DNI == aux2[pospaciente].dni)       //cuando hizo mas de una consulta
			{                                                // compare cual de todas las consultas es mas cercana a la facha de hoy 
				consulta = aux2[pospaciente].fechaturno;
				consultita = mktime(&consulta);
				if (consultita != (time_t)(-1))
				{
					diff = difftime(timer, consultita) / (86400);
				}

				if (min < diff || i == 0)
				{
					min = diff;
					ultconsul = consulta;

				}

			}

		}

		return ultconsul;
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


