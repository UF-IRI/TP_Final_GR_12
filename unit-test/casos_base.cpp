#include "gmock/gmock.h"
#include "headers.h"

using namespace testing;

//testeo de que se abran bien los archivos
TEST(Archivos, LeerPac)
{
	bool siabre = false;
	bool pruebaleer = false;
	int n = 0;
	int* tam1 = &n;
	ifstream pac;
	Paciente* aux = new Paciente[*tam1];
	Paciente Pruebapaciente;
	Pruebapaciente.DNI = 10242587;
	Pruebapaciente.Nombre = "Heidemaria";
	Pruebapaciente.Apellido = "Sawyer";
	Pruebapaciente.Sexo = 'F';
	Pruebapaciente.nacimiento.tm_mday = 19;
	Pruebapaciente.nacimiento.tm_mon = 2;
	Pruebapaciente.nacimiento.tm_year = 1988;
	Pruebapaciente.estado = "internado";
	Pruebapaciente.id_os = "Medicus";
	//10242587 , Heidemaria , Sawyer , F , 19/2/1988 , internado , Medicus
	pac.open("Pacientes.csv", ios::in);
	if (!(pac.is_open()))
		siabre = false;
	else
	{
		siabre = true;
		pruebaleer = Leer_Pacientes(aux, pac, tam1);
	}
	pac.close();
	EXPECT_TRUE(pruebaleer == true);
	EXPECT_THAT(aux[8].DNI, Pruebapaciente.DNI);
	EXPECT_EQ(aux[8].Nombre, Pruebapaciente.Nombre);
	EXPECT_EQ(aux[8].Apellido, Pruebapaciente.Apellido);
	EXPECT_EQ(aux[8].Sexo, Pruebapaciente.Sexo);
	EXPECT_EQ(aux[8].nacimiento.tm_mday, Pruebapaciente.nacimiento.tm_mday);
	EXPECT_EQ(aux[8].nacimiento.tm_mon, Pruebapaciente.nacimiento.tm_mon);
	EXPECT_EQ(aux[8].nacimiento.tm_year, Pruebapaciente.nacimiento.tm_year);
	EXPECT_EQ(aux[8].estado, Pruebapaciente.estado);
	EXPECT_EQ(aux[8].id_os, Pruebapaciente.id_os);
}