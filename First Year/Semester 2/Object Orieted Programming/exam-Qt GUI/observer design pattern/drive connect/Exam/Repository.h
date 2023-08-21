#include <vector>
#include"Domain.h"
class DriversRepository
{
private:
	std::vector<Driver> drivers;
public:
	DriversRepository() {};
	~DriversRepository() {};
	void read_drivers_from_file();
	std::vector<Driver>& get_drivers() { return drivers; };

};

class ReportsRepository
{
private:
	std::vector<Report> reports;
public:
	ReportsRepository() {};
	~ReportsRepository() {};
	void read_reports_from_file();
	std::vector<Report>& get_reports() { return reports; };
};