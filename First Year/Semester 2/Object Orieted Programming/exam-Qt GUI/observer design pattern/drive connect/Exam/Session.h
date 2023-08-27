#pragma once
#include "Subject.h"
#include <vector>
#include <fstream>
//e ca la os cand fiecare utilizator se conecteza la un server si incepe o sesiune. asa se conecteaza si fiecare observer.
//in aceasta sesiune poate sa adauge un report sau un mesaj. astea se adauga la baza de date, adica schimba baza de date, \
//adica schimba subiectul. deci dam inherit in clasa Session la Subject, si de fiecare data cand adaugam mesaj sau report,
//apelam functia notify din clasa Subject, care notifica fiecare observer.
class Session : public Subject
{
private:
	std::vector<std::string> messages;
	std::vector<Report> reports;
public:
	Session(std::vector<Report>& reports1) : reports(reports1) {};
	~Session() {
		save_to_file_reports_from_session();
	};
	void add_message(std::string& new_message)
	{
		messages.push_back(new_message);
		notify();
	}
	void add_new_report(Report& new_report)
	{
		reports.push_back(new_report);
		notify();
	}
	void save_to_file_reports_from_session()
	{
		std::ofstream fout("reports.txt");
		for (Report& report : reports)
		{
			fout << report.get_description() + "|" + report.get_reporter() + "|" +
				std::to_string(report.get_exact_location().first) + "," +
				std::to_string(report.get_exact_location().second) + "|" + std::to_string(report.get_validation_status())
				+"\n";
		}

	}
	std::vector<Report>& get_reports_from_session() { return this->reports; };
	std::vector<std::string>& get_messages_from_session() { return this->messages; };

};
//ideea e ca clasa de observer si de subject sunt mai mult clase generice ca sa vezi ca folosesti observer patternu
//puteam sa nici nu implementezz observer doar pt update, si nici subject, puteam sa le contopesc in session
//dar in acelasi timp e mai bine asa pt ca daca puteam de ex sa am 2 sesiuni, una in care observerii sa vada ceva
//si sa interactioneze cu o anumita baza de date, si alta in  care ei sa vada altceva,, si sa interactioneze cu 
//o alta baza de date. in session eu definesc baza de date, nu in subject. in subject fac legatura intre schimbarile
//care se intampla in timpul sesiunii la baza de date si observeri. clasa subject se ocupa de observeri, ii adauga
//si ii elimina, si le apeleaza functia de update de la fiecare, care e implementata in cpp-ul fiecarui observer
//(window), atunci cand clasa session schimba ceva la baza de date, si apelzeaza notify din subject.
//in session asta baza mea de date e vectoru de rapoarte si de mesaje. in alta sesiune poate vreau sa fie
//doar vectoru de rapoarte. am repo unde am chestiile standard din aplicatie, adica driverii si rapoartele
//care ambii se citesc din fisiere la start, si in sesiune iau de aici ce am nevoie, si eventual mai adaug si alte
//baze de date, cum e aici vectoru de mesaje, depinde ce imi cere sesiunea sa afisez