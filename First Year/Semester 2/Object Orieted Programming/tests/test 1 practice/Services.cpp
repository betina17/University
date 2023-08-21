#include "Services.h"
#include <string>
Services::Services()
{
	repository = Repository(100);
}

void Services::add_service(Car new_car)
{
	this->repository.add_repo(new_car); //you don't have to specify the type when you call this function, so no 'Car car'
}
void Services::remove_service()
{

}
void Services::sort_by_manufacturer_and_model()
{

}