#include "Exceptions.h"
#include <string>

TrenchCoat_Exception::TrenchCoat_Exception(const std::string& error_message)
{
	this->error_message = error_message;
}

const char* TrenchCoat_Exception::what()
{
	return this->error_message.c_str();
}
