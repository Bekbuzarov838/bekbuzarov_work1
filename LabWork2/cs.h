#pragma once
#include <string>

using namespace std;

class cs {
public:
	void set_workshops_on(int new_working); // �������������� ��
	friend ostream& operator<<(ostream& os, const pair<int, cs>& c);
	friend istream& operator<<(istream& is, cs& p);
	friend ofstream& operator<<(ofstream& ofs, const pair<int, cs>& p);
	friend ifstream& operator>>(ifstream& ifs, cs& p);

	string get_name_cs() const;
	double get_load() const;


private:
	string name_cs; // �������� �������������� �������
	int workshops_all = 0; // ���������� �����
	int workshops_on = 0; // ���������� ����� � ������
	double efficiency = 0; // ������������� ������ � ���������
};
