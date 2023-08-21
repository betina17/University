#include "CarRepository.h"

void CarRepository::read_from_file()
{
	
	std::ifstream file("cars.txt");
	std::string line;
	while (std::getline(file, line)) //getline(fisierul de unde citesti, unde iti baga linia)
	{
		std::stringstream line_stream(line);
		std::string manufacturer, model, colour;
		int year;
		std::getline(line_stream, manufacturer, '|'); //nu puteam sa am Ford | Idea, trb Ford|Idea pt ca getline ia ca delimitator un singur caracter, '|'
													 //pe cand ' | ' sunt 3 caractere
		std::getline(line_stream, model, '|');
		line_stream >> year;
		std::getline(line_stream, colour);  
		colour = colour.substr(1);
		Car car = Car(manufacturer, model, year, colour);
		cars.push_back(car);

	}
	file.close();
}
std::vector<Car>& CarRepository::get_cars()
{
	return cars;
}
/*Fstream vs Sstream:
* fstream: The fstream library is used for file handling in C++. It provides classes like ifstream for reading from files (input file stream), ofstream
for writing to files (output file stream), and fstream for both reading and writing (input/output file stream). So when you want to operate on files, you
use fstream.
sstream: The sstream library provides istringstream, ostringstream, and stringstream classes for operating on strings. It allows you to perform input/output
operations on strings in memory, treating them as if they were streams of data like files or console input/output. istringstream is used for reading from string
(input string stream), ostringstream for writing to string (output string stream), and stringstream for both (input/output string stream).
PE SCURT:
std::ifstream file("cars.txt");
std::stringstream line_stream(line);
asta e paralela. ifstream iti baga in file fisierul cars.txt. stream-ul tau e un fisier. stringstream iti baga in line_stream(ss) string-ul line, pe care 
tu l-ai declarat mai sus ca fiind string. deci aici, stream-ul tau e un string. ifstream iti ia stream-ul fisier, fstream iti ia stream-ul string.
pt ca ambele sunt streamuri, poti folosi getline si pe file, dar si pe line, la file delimitatorul e cel de la un string, ca asa ai declarat line-ul,adica 
deliitatorul e "\n", pe cand la line_stream delimitatorul il dai tu, el fiind '|' la noi. ai mai multe explicatii de la chatgpt jos.
*/
/*explicatii aceasta metoda:
La mine, ss este line_stream. 
* I apologize for the confusion, the std::stringstream and std::getline approach might be a bit tricky to understand at first, but it's a powerful tool in C++ for string manipulation and parsing. Let me try to clarify what the original code does.

The std::getline function is used to read a line of text from an input stream. In this case, it reads from a std::stringstream, which was initialized with a line of text from your file.

std::getline takes three parameters: the input stream, the string to store the read text, and a delimiter character. It reads characters from the input stream into the string, stopping when it encounters the delimiter (or the end of the stream).

Here's a step by step explanation of what the code does:


std::getline(ss, manufacturer, '|');
This reads characters from ss into the manufacturer string, stopping when it encounters a '|' character. So if ss contains the string "Fiat|Bravo|2007|red", after this line manufacturer will be "Fiat" and ss will be "Bravo|2007|red".


std::getline(ss, model, '|');
This does the same thing, but reads into the model string. So after this line, model will be "Bravo" and ss will be "2007|red".


ss >> year;
This uses the stream extraction operator to read an integer from the stream. It reads characters until it encounters a non-numeric character, in this case the '|' character. So after this line, year will be 2007 and ss will be "|red".


std::getline(ss, color, '|');
Finally, this reads the remaining characters in the stream into the color string. So after this line, color will be "red" and ss will be empty.
*/

//I could've done this with the approach from a7, not necessarily with the >>operator, but the idea of reading from the file the objects
/*
* std::istream& operator>>(std::istream& is, TrenchCoat& trench_coat)
{
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens;
	char* token = strtok(const_cast<char*>(line.c_str()), ",");
	while (token != NULL)
	{
		tokens.push_back(token);
		token = strtok(NULL, ",");
	}
	if (tokens.size() != 5)
		return is;
	trench_coat.size = tokens[0];
	trench_coat.colour = tokens[1];
	trench_coat.price = std::stoi(tokens[2]);
	trench_coat.quantity = std::stoi(tokens[3]);
	trench_coat.photograph = tokens[4];
	return is;
}	
*/
