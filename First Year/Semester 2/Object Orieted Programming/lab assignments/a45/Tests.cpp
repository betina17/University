#include "Tests.h"
#include <assert.h>
void Test::test()
{
	DynamicArray <TrenchCoat> dynamic_array(100);
	TrenchCoat trench1 = TrenchCoat("S", "red", 100, 1, "https://www.google.ro/search?q=red+trench+coat&source=lnms&tbm=isch&sa=X&ved=0ahUKEwjX2ZqJ7J3ZAhXJLFAKHQ4aD9EQ_AUICigB&biw=1366&bih=662#imgrc=4Z4Z1Z1Z1Z1Z1Z");
	dynamic_array.add_element(trench1);
	assert(dynamic_array.get_size() == 1);
	dynamic_array.update_price(200, 0);
	assert(dynamic_array.get_element(0).get_price() == 200);
	dynamic_array.update_quantity(2, 0);
	assert(dynamic_array.get_element(0).get_quantity() == 2);
	dynamic_array.update_photograph("https://ro.maxmara.com/p-9021053706002-atrench-ecru", 0);
	assert(dynamic_array.get_element(0).get_photograph() == "https://ro.maxmara.com/p-9021053706002-atrench-ecru");
	dynamic_array.delete_element(0);
	assert(dynamic_array.get_size() == 0);

	
}