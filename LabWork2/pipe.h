#pragma once
#include <string>


using namespace std;

class pipeline {
public:
    void set_repair(bool new_status);
    friend ostream& operator<<(ostream& os, const pair<int, pipeline>& p);
    friend istream& operator<<(istream& os, pipeline& p);
    friend ofstream& operator<<(ofstream& ofs, const pair<int, pipeline>& p);
    friend ifstream& operator>>(ifstream& ifs, pipeline& p);

    string get_name_pipe() const;
    bool get_repair() const;

private:
    string name_pipe; // �������� �����
    int lenght = 0; // ����� � ������
    double diameter = 0; // ������� ����� � ��
    bool repair = 0; // 0 �������������, 1 ��������� � �������
};