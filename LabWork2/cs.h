#pragma once
#include <string>

using namespace std;

class cs {
public:
	void set_workshops_on(int new_working); // Редактирование КС
	friend ostream& operator<<(ostream& os, const pair<int, cs>& c);
	friend istream& operator<<(istream& is, cs& p);
	friend ofstream& operator<<(ofstream& ofs, const pair<int, cs>& p);
	friend ifstream& operator>>(ifstream& ifs, cs& p);

	string get_name_cs() const;
	double get_load() const;


private:
	string name_cs; // Название коммпрессионой станции
	int workshops_all = 0; // Количество цехов
	int workshops_on = 0; // Количество цехов в работе
	double efficiency = 0; // Эффективность работы в процентах
};
