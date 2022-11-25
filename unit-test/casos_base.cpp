#include "gmock/gmock.h"
#include "headers.h"

namespace Casos_Base::tests {//testeo de que se abran bien los archivos
	TEST(Casos_Base, Test_Caso1) {
		ASSERT_TRUE(1,1);

	}
	TEST(Casos_Base, Test_Caso2) { //testeo carga de datos
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso3) { //testeo busqueda
		ASSERT_THAT(1, 1);
	}
}
