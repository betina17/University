#pragma once
#include "Repository.h"
#include <string>
class Services
{
private:
	DriversRepository drivers_repo;
	ReportsRepository reports_repo;
public:
	Services();
	~Services() {};
	DriversRepository& get_drivers_repo() { return drivers_repo; };
	ReportsRepository& get_reports_repo() { return reports_repo; };
	bool region_of_interest(Driver& driver, Report& report);

};