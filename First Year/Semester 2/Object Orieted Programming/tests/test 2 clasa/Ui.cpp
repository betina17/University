#include "Ui.h"
void Ui::start_menu()
{
	cout << "\nTo add a new department, press 1";
	cout << "\nTo show all departments, press 2";
	cout << "\nTo show all efficient department, press 3";
	int option;
	while (1)
	{	
		cout << "\nyour option>";
		cin >> option;
		if (option == 1)
		{
			cout << "\nNr of doctors>";
			int nr_of_doctors;
			cin >> nr_of_doctors;
			cout << "Hospital name>";
			string hospital_name;
			cin >> hospital_name;
			cout << "\nType of department>";
			string type_of_department;
			cin >> type_of_department;
			if (strcmp(type_of_department.c_str(), "Surgery") == 0)
			{	
				cout << "\nnr of patients>";
				int nr_of_patients;
				cin >> nr_of_patients;
				Hospital_Departments* new_department;
				new_department = new Surgery(hospital_name, nr_of_doctors, nr_of_patients);
				services.add_department(new_department);
			}
			else if (strcmp(type_of_department.c_str(), "NeonatalUnit") == 0)
			{
				cout << "\naverage grade>";
				double average_grade;
				cin >> average_grade;
				Hospital_Departments* new_department;
				new_department = new Neonatal_Unit(hospital_name, nr_of_doctors, average_grade);
				services.add_department(new_department);
			}
			else
			{
				cout << "Invalid option";
				continue;
			}
		}
		else if (option == 2)
		{
			for (auto& department : services.get_all_departments())
				cout << department->toString();
		}
		else if (option == 3)
		{
			for (auto& department : services.get_all_departments())
				cout << department->is_efficient();
		}
		else
			break;
	}

}