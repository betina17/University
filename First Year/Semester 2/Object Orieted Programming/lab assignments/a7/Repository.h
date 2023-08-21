#include <vector>
#include "Domain.h"
#include <fstream>
#include "Validator.h"

class Repository
{
public:
	virtual void write_to_file(std::vector<TrenchCoat>& data_base) = 0;
	virtual void read_from_file(std::vector<TrenchCoat>& data_base) = 0;
};

class CSV_Repository : public Repository
{
public:
	void write_to_file(std::vector<TrenchCoat>& shopping_basket) override;
	void read_from_file(std::vector<TrenchCoat>& shopping_basket) override {};
};
//CSV_Repository is an instance of Repository, if i write public:Repository, this is what it means, Repository e clasa mama
//relationship between CSV_Repository and Repository is inheritance

class HTML_Repository : public Repository
{
	void write_to_file(std::vector<TrenchCoat>& shopping_basket) override;
	void read_from_file(std::vector<TrenchCoat>& shopping_basket) override {};
};

class Text_File_Repository : public Repository
{
	void write_to_file(std::vector<TrenchCoat>& data_base) override;
	void read_from_file(std::vector<TrenchCoat>& data_base) override;
};