#pragma once
#include <string>
#include "Domain.h"
#include "Exceptions.h"
class TrenchCoat_Validator
{
public:
	static void validate_size(const std::string& size);
	static void validate_colour(const std::string& colour);
	static void validate_price(const std::string& price);
	static void validate_quantity(const std::string& quantity);
	static void validate_photograph(const std::string& photograph);
	static void validate_trench_coat(TrenchCoat& trench_coat);

};
/*In this case, validate_dog_breed is a function that belongs to the Dog class and not to any object of the Dog class. This also means that the static member 
function can't directly access non-static members (variables or functions) of the class because those belong to specific instances.

This is often used for functions that don't logically belong to any particular object of the class, or for utility functions that might be related to the class's
purpose but don't need to access or modify any of the class's instance data.

In the context of your validate_dog_breed function, it seems like it would be checking if the passed in breed is valid. It doesn't need to access any specific 
dog's information to do this, so it makes sense for it to be a static function.
*/

//functia asuma ca tu ii dai un lvalue, adica un parametru care va fi ulterior in interiorul functiei
/*There are a few reasons for using const in this context:

Immutability: By marking the parameter as const, you are telling the compiler and other developers that this function does not modify the input argument 
dog_breed. This can make the code more readable and easier to understand.

Safety: Using const can prevent accidental modification of the input argument within the function. If you were to try to modify dog_breed inside the function, 
the compiler would generate an error, helping you avoid unintended side effects.

Efficiency: In this example, const is also combined with passing the parameter by reference (const std::string&). This can improve performance by avoiding a copy
of the input string when the function is called. Since the function is not modifying the input, it is safe to pass a reference without worrying about unintended 
side effects.

Overall, using const in this context is a good practice to ensure that the function operates as intended, without modifying its input arguments, and to convey 
this intent to other developers reading the code.


No, it is not necessary to have a const parameter in your function if you want to call the function with a constant value or by using another function's return
value as a parameter. The main purpose of using const with a function parameter is to indicate that the function will not modify the value of that parameter.

If your function doesn't modify the input parameter, you can still call the function with a constant value or by using the return value of another function as a 
parameter, even if the parameter is not marked as const. However, marking the parameter as const provides better clarity and safety, as explained in the previous
answer.
*/
/*o functie statica a unei clase te lasa sa aplezi in alte clase acea functie fara sa creezi uhn obiect de tipul clasei respective. scrii doar
* //numele clasei::numele functiei()
*/