#include "Test3.h"

Test3::Test3(QWidget *parent)
    : QMainWindow(parent)
{   
   
    service.get_repo().read_from_file();
    ui.setupUi(this);
    populate_list();
}

Test3::~Test3()
{}

void Test3::populate_list()
{
    vector<Food> sorted_shopping_list = service.sort_ascending_by_category_and_name();
    this->ui.ShoppingListWidget->clear();
    for (Food& food : sorted_shopping_list)
    {
		QString item_in_list = QString::fromStdString(food.get_category() + " " + food.get_name() + " " + to_string(food.get_quantity()));
		this->ui.ShoppingListWidget->addItem(item_in_list);
	}
}

