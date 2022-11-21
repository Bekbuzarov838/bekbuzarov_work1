#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "pipe.h"
#include "utility.h"

using namespace std;

// overloading

// out
ostream& operator<<(ostream& os, const pair<int, pipeline>& p)
{
    return os << "\n Pipeline [" << p.first << "]" << endl << " The name of pipeline: " << p.second.name_pipe << endl << " The length of pipeline: " << p.second.lenght << endl
        << " The pipeline's diameter: " << p.second.diameter << endl << " Repair status: " << p.second.repair << endl;
}

// in
istream& operator<<(istream& is, pipeline& p)
{
    cout << "\n Enter the pipeline's name: ";
    getline(cin, p.name_pipe);
    cout << " Enter the length of pipeline in meters: ";
    p.lenght = checker();
    cout << " Enter pipeline's the diameter in millimeters: ";
    p.diameter = checker();
    cout << " Enter pipeline's status (0 working, 1 in the repair): ";
    p.repair = checker_bool();
    cout << "\n The pipeline number has been successfully added" << endl;
    return is;
}

// out file
ofstream& operator<<(ofstream& ofs, const pair<int, pipeline>& p)
{
    ofs << 1 << endl << p.first << endl << p.second.name_pipe << endl << p.second.lenght << endl << p.second.diameter << endl << p.second.repair << endl << endl;
    return ofs;
};

//  in file
ifstream& operator>>(ifstream& ifs, pipeline& p)
{
    getline(ifs, p.name_pipe);
    ifs >> p.lenght;
    ifs >> p.diameter;
    ifs >> p.repair;
    return ifs;
};

// getters
string pipeline::get_name_pipe() const { return(name_pipe); }
bool pipeline::get_repair() const { return(repair); }

// setters
void pipeline::set_repair(bool new_status)
{
    repair = new_status;
}
