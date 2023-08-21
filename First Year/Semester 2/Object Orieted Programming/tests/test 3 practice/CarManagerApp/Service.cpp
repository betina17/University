#include "Service.h"

void Service::sort_cars_by_manufacturer()
{
	std::sort(CarRepo.get_cars().begin(), CarRepo.get_cars().end(), [](Car& a, Car& b) {return a.get_manufacturer() < b.get_manufacturer(); });

}

CarRepository& Service::get_car_repo()
{
    return CarRepo;
}

/*[](const Car& a, const Car& b) {
        return a.getManufacturer() < b.getManufacturer();
    } so this is the lamda function? 
ChatGPT
Yes, that's correct!

A lambda function (or lambda expression) is a feature in C++ which allows you to define an anonymous (nameless) function right in the place where you use it. 
They are mainly used in scenarios where you need a short function that is used only once (as an argument to algorithms).

Here's a breakdown of the lambda function:
[]: These are the capture brackets. They can be used to "capture" variables from the surrounding scope so they can be used in the lambda function. In this case,
we don't need to capture anything, so they're empty.

(const Car& a, const Car& b): These are the parameters to the lambda function, just like parameters to a normal function. In this case, the lambda takes two
parameters, both of type const Car&.

{ return a.getManufacturer() < b.getManufacturer(); }: This is the body of the lambda function. It's just like the body of a normal function. In this case,
it's returning the result of the comparison between the manufacturers of the two cars.

The whole lambda expression forms a function object that can be called with two Car objects and returns true if the first car's manufacturer is lexicographically
less than the second car's manufacturer. This is used by std::sort to order the elements in the range.

so the sort only happens if the lambda function returns true? why?
ChatGPT
Yes, that's correct. The std::sort function uses the comparison function (in this case, your lambda function) to determine the order of the elements.

Here's how it works:

When std::sort is sorting the elements, it needs to decide which element should come before the other. To do this, it calls your comparison function with 
two elements. If the comparison function returns true, std::sort places the first element before the second in the final order. If it returns false, it places
the second element before the first.
*/