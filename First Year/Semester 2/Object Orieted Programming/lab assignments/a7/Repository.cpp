#include "Repository.h"
void Text_File_Repository::write_to_file(std::vector<TrenchCoat>& data_base)
{
	std::ofstream file("textfile.txt");
	for (auto trench_coat : data_base)
	{
		file << trench_coat.get_size() << "," << trench_coat.get_colour() << "," << trench_coat.get_price() << "," << trench_coat.get_quantity() << "," << trench_coat.get_photograph() << "\n";
	}
	file.close();
}

void Text_File_Repository::read_from_file(std::vector<TrenchCoat>& data_base)
{	
	TrenchCoat trench_coat;
	std::ifstream file("textfile.txt");
	while (file >> trench_coat)
	{	
		TrenchCoat_Validator::validate_trench_coat(trench_coat);
		data_base.push_back(trench_coat);
	}
	file.close();
}

void CSV_Repository::write_to_file(std::vector<TrenchCoat>& shopping_basket)
{
	std::ofstream file("csvfile.csv");
	for (auto trench_coat : shopping_basket)
	{
		file << trench_coat.get_size() << "," << trench_coat.get_colour() << "," << trench_coat.get_price() << "," << trench_coat.get_quantity() << "," << trench_coat.get_photograph() << "\n";
	}
	file.close();
}

void HTML_Repository::write_to_file(std::vector<TrenchCoat>& shopping_basket)
{
	std::ofstream fout("htmlfile.html");
	fout << "<!DOCTYPE html>\n";
	fout << "<html>\n";
	fout << "<head>\n";
	fout << "<title>Trench Coats</title>\n";
	fout << "</head>\n";
	fout << "<body>\n";
	fout << "<table border=\"1\">\n";
	fout << "<tr>\n";
	fout << "<td>Size</td>\n";
	fout << "<td>Colour</td>\n";
	fout << "<td>Price</td>\n";
	fout << "<td>Quantity</td>\n";
	fout << "<td>Photograph</td>\n";
	fout << "</tr>\n";
	for (auto trench_coat : shopping_basket)
	{
		fout << "<tr>\n";
		fout << "<td>" << trench_coat.get_size() << "</td>\n";
		fout << "<td>" << trench_coat.get_colour() << "</td>\n";
		fout << "<td>" << trench_coat.get_price() << "</td>\n";
		fout << "<td>" << trench_coat.get_quantity() << "</td>\n";
		fout << "<td><a href=\"" << trench_coat.get_photograph() << "\">Link</a></td>\n";
		fout << "</tr>\n";
	}
}
