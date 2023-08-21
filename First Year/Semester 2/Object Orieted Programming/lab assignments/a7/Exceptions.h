#include <exception>
#pragma once
#include <vector>
#include <string>
class TrenchCoat_Exception : public std::exception
{
protected:
	std::string error_message;
public:
	TrenchCoat_Exception(const std::string& error_message);
	virtual const char* what();
};

//I have to write virtual because i want to override the what() function from the exception class, and override is just a keyword, daca nu am virtual scris in
//fata functiei what() in clasa mama, adica execptions, careia i-am dat include, inseamna ca trebuie sa pun eu virtual in fata ei in fiecare clasa in care vreau
//sa o folosesc, spre deosebire de Repository unde am pus virtual in fata la write_to_file si read_from_file si nu am mai pus in fata la celelalte clase, 
//adica la HTML, Text si CSV repo. cred ca asta e explicatia, ca imi dadea eroare daca nu puneam virtual

/*const char*: The function returns a pointer to a const char, which is typically a C-style string. The returned string is constant, meaning that you cannot 
modify the characters it points to.

const: The function is declared as const, which means that it does not modify any non-static data members of the class it belongs to. It can be called on a 
constant instance of the class. This keyword is used to express that this function is not supposed to change the state of the object it is called on.

noexcept: This keyword indicates that the function will not throw any exceptions. It is a promise to the caller that this function is exception-safe. If this 
function does throw an exception, the program will terminate.

override: This keyword is used when a member function is intended to override a virtual function declared in a base class. It tells the compiler to check if
there is a virtual function in a base class with the same signature, and if there isn't, it will generate a compile-time error. This helps catch errors in cases 
where the base class function's signature changes or when the derived class function has a typo or other mistake in the signature.

In summary, this line of code declares a what() function that returns a pointer to a constant character string, does not modify the object state, does not
throw exceptions, and is intended to override a virtual function from a base class. This what() function is commonly seen in exception classes derived from
std::exception.

so the waht() function already exists in the exception class, but we want to override it, so we use the override keyword
*/
