#include <iostream>
#include "UI.h"
#include "Tests.h"

int main()
{		//User_Interface user_interface;
		Tests test;
		test.test_default_constructor();
		test.test_parameterized_constructor();
		test.test_copy_constructor();
		test.test_display_as_string();
		test.test_getters_and_setters();
		//user_interface.start_menu();
		return 0;
}
//ca sa vezi code coverage-ul comenteaza in main orice in afara de teste