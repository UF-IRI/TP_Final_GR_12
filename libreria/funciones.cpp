#include "headers.h"
using namespace std;

//LECTURA DE ARCHIVOS

bool Leer_Pacientes(Paciente*& aux, ifstream& pac, int* tam1)
{
	if (aux == nullptr||tam1==nullptr)
		return false;

	Paciente auxpac;
	char coma = ',';
	string header;
	getline(pac, header);

	while (pac)
	{
		pac>> auxpac.DNI >> coma >> auxpac.Nombre >> coma >>  auxpac.Apellido >> coma >> auxpac.Sexo >> coma >> auxpac.nacimiento.tm_mday >> coma >> auxpac.nacimiento.tm_mon >> coma >> auxpac.nacimiento.tm_year >> coma >> auxpac.estado >> coma >> auxpac.id_os;
		resize_paciente(auxpac, aux, tam1);

	}


	return true;
}

bool Leer_Contactos(Contacto*& aux, ifstream& contact, int* tam2)
{
	if (aux == nullptr||tam2==nullptr)
		return false;
	char coma = ',';
	string header;
	Contacto auxcont;
	getline(contact, header);

	while (contact)
	{
		contact >> auxcont.DNI >> coma >> auxcont.telefono >> coma >> auxcont.celular >> coma;
		getline(contact, auxcont.direccion, ',');
		contact >> auxcont.mail;
		resize_contactos(auxcont, aux, tam2);
	}
	return true;
}

bool Leer_Consultas(Ultima_consulta*& aux, ifstream& consul, int* tam3)
{
	if (aux == nullptr||tam3==nullptr)
		return false;

	char coma = ',';
	string header;
	Ultima_consulta auxconsul;
	getline(consul, header);

	while (consul)
	{
		consul >> auxconsul.dni >> coma >> auxconsul.fechasolicitud.tm_mday >> coma >> auxconsul.fechasolicitud.tm_mon >> coma >> auxconsul.fechasolicitud.tm_year >> coma >> auxconsul.fechaturno.tm_mday >> coma >> auxconsul.fechaturno.tm_mon >> coma >> auxconsul.fechaturno.tm_year >> coma >> auxconsul.presento >> coma >> auxconsul.matriculamedica;
		resize_consultas(auxconsul, aux, tam3);
	}

	return true;
}

bool Leer_Medicos(medicos*& aux, ifstream& med, int* tam4)
{
	if (aux == nullptr || tam4 == nullptr)
		return false;

	char coma = ',';
	string header;
	medicos auxmed;
	getline(med, header);
	
	while (med)
	{
		med >> auxmed.matricula >> coma >> auxmed.nombre >> coma >> auxmed.apellido >> coma >> auxmed.telefono >> coma >> auxmed.especialidad >> coma >> auxmed.activo;
		resize_medicos(auxmed, aux, tam4);
	}

	return true;
}

//RESIZE

void resize_paciente(Paciente auxpac,Paciente*& aux,int *tamactual)
{
	*tamactual = *tamactual + 1;
	int i = 0;
	Paciente* pac = new Paciente[*tamactual];

	while (i < *tamactual - 1 ) 
	{
		pac[i] = aux[i];
		i++;
	}	
	pac[i] = auxpac;
	delete[]aux;
	aux = pac;

	return;
}

void resize_contactos(Contacto auxcont,Contacto *&aux2, int* tamactual2) 
{
	*tamactual2 = *tamactual2 + 1;
	int i = 0;
	Contacto* cont = new Contacto[*tamactual2];

	while (i < *tamactual2 - 1) 
	{
		cont[i] = aux2[i];
		i++;
	}
	cont[i] = auxcont;
	delete[]aux2;
	aux2 = cont;

	return;
}

void resize_consultas(Ultima_consulta auccons,Ultima_consulta*& aux3, int* tamactual3) 
{
	*tamactual3 = *tamactual3 + 1;
	int i = 0;
	Ultima_consulta* consul = new Ultima_consulta[*tamactual3];

	while (i < *tamactual3 - 1) 
	{
		consul[i] = aux3[i];
		i++;
	}
	consul[i] = auccons;
	delete[]aux3;
	aux3 = consul;
	
	return;
}

void resize_medicos(medicos auxmed,medicos*& aux4, int* tamactual4) 
{
	*tamactual4 = *tamactual4 + 1;
	int i = 0;
	medicos* med = new medicos[*tamactual4];

	while (i < *tamactual4 - 1) 
	{
		med[i] = aux4[i];
		i++;
	}
	med[i] = auxmed;
	delete[]aux4;
	aux4 = med;

	return;
}

//DIVISION POR GRUPOS

bool division_grupos(Paciente*& aux, int* tam1, Ultima_consulta*& aux2, int* tam2,Contacto*& aux3,int*tam3,medicos*&aux4, int *tam4, fstream &fp,fstream &fp2 )
{
	if (aux == nullptr || tam1 == nullptr || aux2 == nullptr || tam2 == nullptr||aux3==nullptr||tam3==nullptr||aux4==nullptr||tam4==nullptr)
		return false;

	int i = 0, j = 0, pospac = 0;
	int n = 0;

	Pos_recp recp;

	for (i = 0; i < *tam1; i++)
	{
		if (aux[i].estado == "fallecido" || aux[i].estado == "internado")
			cargararchivados(aux[i], fp);
		else
		{
			for (j = 0; j < *tam2; j++)
			{
				bool diffecha = distanciafechas(aux2, j, aux, tam1);
				
				if (aux2[j].presento == true && diffecha == true)
				{
					pospac = buscarpac(aux, tam1, aux2[j].dni);
					aux[pospac].estado = "ARCHIVADO";
					cargararchivados(aux[pospac], fp);
				}
				else
				{
					recp.DNI = aux[i].DNI;
					recp.nombre = aux[i].Nombre;
					recp.apellido = aux[i].Apellido;
					for (int h = 0; h < *tam4; h++)       // para copiar los datos del doctor
					{
						string idmedico = buscarmed(aux4, tam4, aux2, tam2, aux[i], aux, tam1);
						if (aux4[h].matricula == idmedico)
						{
							recp.matr_medico = aux4[h].matricula;
							recp.nombre_med = aux4[h].nombre;
							recp.apellido_med = aux4[h].apellido;
							recp.telefono_med = aux4[h].telefono;
							recp.esp_med = aux4[h].especialidad;
							recp.activo = aux4[h].activo;
						}
					}
					int k;
					for (k = 0; k < *tam3; k++)	// para copiar el telefono
					{
						if (recp.DNI == aux3[k].DNI)
						{
							recp.telefono = aux3[k].telefono;
							break;
						}
				    }
				    cargar_posibles_recup(recp,fp2);
				}
			}
		}
	
	}
	return true;
}

int buscarpac(Paciente*& aux, int* tam1, unsigned int dni) 
{
	int i = 0;
	for (i = 0; i < *tam1; i++) 
	{
		if (dni == aux[i].DNI)
			return i;
	}
}

string buscarmed(medicos*& aux4, int* tamactual4, Ultima_consulta*& aux2, int* tam2, Paciente aux,Paciente*& aux3,int *tam)
{
	int i = 0, j = 0;
	tm ulti_consul;
	string matraux;

	for (i = 0; i < *tam2; i++)
	{
		if (aux.DNI == aux2[i].dni)
		{
			ulti_consul = ultcons(aux2, i, aux3, tam);

			if (ulti_consul.tm_wday == aux2[i].fechaturno.tm_wday && ulti_consul.tm_mon == aux2[i].fechaturno.tm_mon && ulti_consul.tm_year == aux2[i].fechaturno.tm_year)

				matraux = aux2[i].matriculamedica;

		}

	}
	return matraux;
}

void cargararchivados(Paciente aux, fstream & fp)
{
	fp << aux.DNI << ',' << aux.Nombre << ',' << aux.Apellido << ',' << aux.Sexo << ',' << aux.nacimiento.tm_mday << ',' << aux.nacimiento.tm_mon << ',' << aux.nacimiento.tm_year << ',' << aux.estado << ',' << aux.id_os<<endl;
	return;
}

void cargar_posibles_recup(Pos_recp aux, fstream& fp)
{
	fp << aux.DNI<< ',' << aux.nombre << ',' << aux.apellido << ',' << aux.telefono << ',' << aux.celular << ',' << aux.matr_medico << ',' << aux.nombre_med << ',' << aux.apellido_med << ',' << aux.telefono_med << ',' << aux.esp_med << ',' << aux.activo << endl;
	return;

}

//SECRETARIA

bool secretaria_de_pacientes(Pos_recp*& aux5, fstream& recups, int* tam5)
{
	if (aux5 == nullptr || tam5 == nullptr)
		return false;

	Pos_recp  auxposrecp;
	char coma = ',';
	string header;
	getline(recups, header);

	while (recups)
	{
		recups >> auxposrecp.DNI >> coma;
		getline(recups, auxposrecp.nombre, ',');
		getline(recups, auxposrecp.apellido, ',');
		getline(recups, auxposrecp.telefono, ',');
		getline(recups, auxposrecp.celular, ',');
		getline(recups, auxposrecp.matr_medico, ',');
		getline(recups, auxposrecp.nombre_med, ',');
		getline(recups, auxposrecp.apellido_med, ',');
		getline(recups, auxposrecp.telefono_med, ',');
		getline(recups, auxposrecp.esp_med, ',');
		recups >> auxposrecp.activo >> coma;
	
		resize_pos_recp(auxposrecp, aux5, tam5);
	}

	return true;
}

void resize_pos_recp(Pos_recp auxrecup, Pos_recp*& aux5, int* tam5)
{
	*tam5 = *tam5 + 1;
	int i = 0;
	Pos_recp* recp = new Pos_recp[*tam5];

	while (i < *tam5 - 1)
	{
		recp[i] = aux5[i];
		i++;
	}
	recp[i] = auxrecup;
	delete[]aux5;
	aux5 = recp;

	return;
}

void contactar_pac(Pos_recp pac, fstream& arch, Paciente*& aux, int* tam1, tm& nueva_consulta, string& nueva_obra_social)
{

	int llamada = consrandom(1,0);//si devuelve cero no atendio, si devuelve 1 atendio
	int pospac2 = 0,pospac3=0;
	int cant_insisitencias = 0;
	if (llamada == 0)
	{
		int numero_extra = consrandom(1, 0);//cero si no tiene numero extra,1 si tiene 

		if (numero_extra == 0)//si no tiene numero extra, programo nueva fecha de insistencia
		{
			tm fecha_de_insistencia = nuevacons();//nueva fecha de insistencia
			cant_insisitencias++;
			if (cant_insisitencias == 3)
			{
				pospac2 = buscarpac2(aux, tam1, pac.DNI);
				aux[pospac2].estado = "archivado";
				cargararchivados(aux[pospac2], arch);
			}

		}
		else//vendria siendo numero extra =1
		{
			//lo llamo
			int llamada2 = consrandom(1, 0);//1 si atiende,0 si no atiende
			
			if (llamada2 == 0)
			{
				tm fecha_de_insistencia = nuevacons();//no atendio ni el contacto de emergencia,prograni nueva fecha para insistir.
				cant_insisitencias++;
				if (cant_insisitencias == 3)
				{
					pospac2 = buscarpac2(aux, tam1, pac.DNI);
					aux[pospac2].estado = "Archivado";
					cargararchivados(aux[pospac2], arch);
				}

			}
			else////////////////////////////////////
			{  //atendio por el numero_extra
				int estado_vital = consrandom(1, 0);  // pregunto si se murio

				if (estado_vital == 0)//si esta muerto
				{
					pospac2 = buscarpac2(aux, tam1, pac.DNI);
					aux[pospac2].estado = "fallecido";
					cargararchivados(aux[pospac2], arch);
				}
				else
				{
					int volver = consrandom(1, 0);// 1 si desde volver,0 si no desea volver

					if (volver == 0)
					{
						pospac2 = buscarpac2(aux, tam1, pac.DNI);
						aux[pospac2].estado = "Archivado";
						cargararchivados(aux[pospac2], arch);
					}
					else //desea volver
					{
						 nueva_consulta = nuevacons();

						int obrasocial = consrandom(1, 0);//1 si cambio de obra social,0 si no cambio
						if (obrasocial == 1)
						{
							pospac3 = buscarpac2(aux, tam1, pac.DNI);
							nueva_obra_social = random_obra_social(aux[pospac3].id_os, aux, tam1);
						}
						else
							nueva_obra_social = aux[pospac3].id_os;
						
					}
				}
			}
		}
		
	}
	//atendio a la primera
	else
	{
		int estado_vital = consrandom(1, 0);  // pregunto si se murio

		if (estado_vital == 0)//si esta muerto
		{
			pospac2 = buscarpac2(aux, tam1, pac.DNI);
			aux[pospac2].estado = "fallecido";
			cargararchivados(aux[pospac2], arch);
		}
		else
		{
			int volver = consrandom(1, 0);// 1 si desde volver,0 si no desea volver

			if (volver == 0)
			{
				pospac2 = buscarpac2(aux, tam1, pac.DNI);
				aux[pospac2].estado = "Archivado";
				cargararchivados(aux[pospac2], arch);
			}
			else //desea volver
			{
				nueva_consulta= nuevacons();

				int obrasocial = consrandom(1, 0);//1 si cambio de obra social,0 si no cambio
				if (obrasocial == 1)
				{
					pospac3 = buscarpac2(aux, tam1, pac.DNI);
				 nueva_obra_social = random_obra_social(aux[pospac3].id_os,aux,tam1);//paso obra social para que no sea igual a la vieja
				}
				else
					nueva_obra_social = aux[pospac3].id_os;
			}
		}
	}
	return;
}

int buscarpac2(Paciente*& aux, int* tam1, unsigned int dni)
{
	int i = 0;
	for (i = 0; i < *tam1; i++)
	{
		if (dni == aux[i].DNI)
			return i;
	}
}

//FUNCIONES AUXILIARES

bool distanciafechas(Ultima_consulta * &aux2, int pospaciente, Paciente * &aux, int* tam2)//cuando la llamemos en el main hay que meterla dentro de un for
{
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
	tm consulta = { 0, 0, 0, 0, 0, 0 };
	tm consulta2 = { 0, 0, 0};
	time_t timer;
	time(&timer);
	time_t consultita = 0;
	tm ultconsul = {0, 0, 0, 0, 0, 0};
	double min = 0;
	double diff = 0;
	int i = 0;

	do
	{
		if (aux[i].DNI == aux2[pospaciente].dni)       //cuando hizo mas de una consulta
		{                                                // compare cual de todas las consultas es mas cercana a la facha de hoy 
			consulta = aux2[pospaciente].fechaturno;
			consulta2 = consulta;
			consulta2.tm_year = (consulta.tm_year)-1900;
			consultita = mktime(&consulta2);
			if (consultita != (time_t)(-1))
			{
				diff = difftime(timer, consultita) / (86400);
			}

			if (min < diff || i == 0)
			{
				min = diff;
				ultconsul = consulta2;

			}

		}
		i++;
	} while (i < *tam2);

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
	tm nueva_consulta;
	do 
	{
		int minrand, horarand, diarand, mesrand, aniorand;
		minrand = consrandom(59, 0);
		horarand = consrandom(20, 6); //las horas en la libreria van de 0 a 23
		mesrand = consrandom(11, 0);  //los meses en la libreria van de 0 a 11
		aniorand = consrandom(126, 122);  // en un rango de 3 anios

		bool anio_bisiesto = bisiestos(aniorand + 1900);


		if (anio_bisiesto == true && mesrand == 1)
			diarand = consrandom(29, 1); //los dias del mes van de 0 a 31.
		else
			diarand = consrandom(28, 1);

		if (mesrand == 0 || mesrand == 2 || mesrand == 4 || mesrand == 6 || mesrand == 7 || mesrand == 9 || mesrand == 11)
			diarand = consrandom(31, 1);
		else if (mesrand != 1)
			diarand = consrandom(30, 1);


		 nueva_consulta = { 0, minrand, horarand, diarand, mesrand, aniorand };


	} while (mayorahoy(nueva_consulta) == false);

	return nueva_consulta; //Nos pasa la fecha de la consulta reprogramada.


}

bool bisiestos(int anio)
{
	if ((anio % 4) == 0 && (anio % 100) != 0|| anio % 400 != 0)
		return true;
	else
		return false;
}

bool mayorahoy(tm nueva_consulta)
{
	time_t hoy;
	time(&hoy);
	time_t y = mktime(&nueva_consulta);      //además, el mktime lo usamos para no tener que sumarle 1 al mes usando la estructura tm y tampoco hace falta sumarle 1900 al año.
	double diferencia = 0;
	if (y != (time_t)(-1))
	{//ambas fechas pasadas por el mktime deben ser distintas de -1 ya que si son iguales a -1 es porque no se pudo representar la fecha/hora en el calendario.
		diferencia = difftime(hoy, y) / (86400); //60*60*24    //calculamos y dividimos la diferencia del tiempo que se retorna en segundos por la cantidad de segundos por día.
	}
	if (diferencia < 0)
		return true;
	else
		return false;
}

string random_obra_social(string obra_social, Paciente*& aux, int* tam2)
{
	int n = consrandom(10, 0);
	int i;
	string nueva_obrasocial;
	for (i = 0; i < n; i++)
	{
		if (obra_social != aux[i].id_os)
			nueva_obrasocial = aux[i].id_os;
	}

	return nueva_obrasocial;//devuelve la ultima
}
