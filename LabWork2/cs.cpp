#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "cs.h"
#include "utility.h"

using namespace std;

ostream& operator<<(ostream& os, const pair<int, cs>& c)
{
    return os << "\n The compressor station's name: " << c.second.name_cs << endl
        << " Compressor station consist of [" << c.second.workshops_on << "/" << c.second.workshops_all << "] working workshops" << endl
        << " Compressor station's efficiency: [ " << c.second.efficiency << " %]" << endl;
}

istream& operator<<(istream& is, cs& p)
{
    cout << "\n Enter the compressor station's name: ";
    getline(cin, p.name_cs);
    while (1) {
        cout << " Enter the number of the ALL workshops: ";
        p.workshops_all = checker();
        cout << " Enter the number of WORKING workshops: ";
        p.workshops_on = checker();
        if (p.workshops_on > p.workshops_all)
            cout << "\n WORKING workshops can't be more than ALL workshops. Try again \n" << endl;
        else
            break;
    }
    cout << " Enter the efficiency of the compressor station: ";    p.efficiency = checker(0, 100);
    return is;
}

ofstream& operator<<(ofstream& ofs, const pair<int, cs>& p)
{
    ofs << p.second.name_cs << endl << p.second.workshops_on << endl << p.second.workshops_all
        << endl << p.second.efficiency << endl;
    return ofs;
};

ifstream& operator>>(ifstream& ifs, cs& p)
{
    getline(ifs, p.name_cs);
    ifs >> p.workshops_on;
    ifs >> p.workshops_all;
    ifs >> p.efficiency;
    return ifs;
}

string cs::get_name_cs() const
{
    return(name_cs);
}

double cs::get_load() const
{
    return (((double)workshops_on / workshops_all) * 100);
}


void cs::set_workshops_on(int new_working) // Редактирование КС
{
    workshops_on = new_working;
}