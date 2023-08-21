#include "Services.h"
#include <algorithm>
bool Services::region_of_interest(Driver& driver, Report& report)
{
		int x = driver.get_current_location().first;
		int y = driver.get_current_location().second;
		int x_report = report.get_exact_location().first;
		int y_report = report.get_exact_location().second;
		double distance = sqrt(pow(x - x_report, 2) + pow(y - y_report, 2));
		if (distance <= 10)
			return 1;
		return 0;
}
Services::Services()
{	
	//cand porneste aplicatia si construiesc servicu in main, se citesc astea. o data. la inceputu aplicatiei.
	//nu pt fiecare window. ca e un singur repo care se vede in toate
	//plus ca functiile astea nu se apeleaza direct in main ca nu tin de gui
	drivers_repo.read_drivers_from_file(); 
	reports_repo.read_reports_from_file();
}