#include "gmock/gmock.h"
#include "headers.h"

using namespace testing;

//testeo de que se abran bien los archivos
TEST(Archivos, LeerPac)
{
	int tam1 = 0;
	Paciente* aux = nullptr;
	aux = new Paciente[tam1];
	ifstream pac;
	pac.open("Pacientes.csv", ios::in);
	Leer_Pacientes(aux, pac, &tam1);
	pac.close();

	//10242587 , Heidemaria , Sawyer , F , 19/2/1988 , internado , Medicus
	EXPECT_EQ(aux[1].DNI, 10242582);
	EXPECT_EQ(aux[1].Nombre, "Cersty");
	EXPECT_EQ(aux[1].Apellido, "Thurston");
	EXPECT_EQ(aux[1].Sexo, 'F');
	EXPECT_EQ(aux[1].nacimiento.tm_mday, 9);
	EXPECT_EQ(aux[1].nacimiento.tm_mon, 6);
	EXPECT_EQ(aux[1].nacimiento.tm_year, 1970);
	EXPECT_EQ(aux[1].estado, "internado");
	EXPECT_EQ(aux[1].id_os, "Medicus");

	delete[]aux;
}

TEST(CasosBase, ResizePaciente)
{
	int tam = 0;
	Contacto* ejemplo = new Contacto[tam];
	Contacto auxcont;

	auxcont.DNI = 45545166;
	auxcont.telefono = "+54(011)40694412";
	auxcont.celular = "+54(022)40961244";
	auxcont.direccion = "Buckingham";
	auxcont.mail = "nicolas.rapp@gmail.com";

	resize_contactos(auxcont, ejemplo, &tam);

	EXPECT_THAT(tam, 1);
	EXPECT_EQ(ejemplo[0].DNI, 45545166);
	EXPECT_EQ(ejemplo[0].telefono, "+54(011)40694412");
	EXPECT_EQ(ejemplo[0].celular, "+54(022)40961244");
	EXPECT_EQ(ejemplo[0].direccion, "Buckingham");
	EXPECT_EQ(ejemplo[0].mail, "nicolas.rapp@gmail.com");

	delete[] ejemplo;
}
TEST(tiempo, distfecha)
{
	tm auxiliar;
	
	
	auxiliar.tm_mday =10;
	auxiliar.tm_mon = 12;
	auxiliar.tm_year =2024;

	bool cons= mayorahoy(auxiliar);

	EXPECT_TRUE(auxiliar);
}