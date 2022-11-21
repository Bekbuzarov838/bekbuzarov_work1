#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "pipe.h"
#include "cs.h"
#include "utility.h"

using namespace std;

// checkers
bool checker_bool() // Проверка на булевое значение
{
    bool in;
    while (1) {
        if (cin >> in)
        {
            cin.ignore(1024, '\n'); // Отсекать всё, что дальше пробела
            return(in);
        }
        else
        {
            cout << "\n Incorrect input. Try again. Enter 0 or 1: ";
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
};

int checker() // Проверка на положительное число 
{
    int in;
    while (1) {
        if ((cin >> in) && (in >= 0))
        {
            cin.ignore(1024, '\n');
            return(in);
        }
        else
        {
            cout << "\n Incorrect input. Try again. Enter positive number: ";
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
}

int checker(int a, int b) // Проверка на число в интервале от a до b включительно
{
    int in;
    while (1) {
        if ((cin >> in) && (in >= a) && (in <= b))
        {
            cin.clear();
            cin.ignore(1024, '\n');
            return(in);
        }
        else
        {
            cout << "\n Incorrect input. Try again. Enter number from [" << a << "] till [" << b << "]: ";
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
}

void help()
{
    cout << "\n 1 Help \n 2 Show All Objects \n\n 3 Add Pipeline \n 4 Edit Repair Status of Pipeline \n 5 Delete pipeline \n\n"
        << " 6 Add Compressor Stations \n 7 Edit Number of Working Workshops \n 8 Delete compressor station \n\n"
        << " 9 Filter pipeline [repair status] \n 10 Filter pipeline [name] \n 11 Filter compressor station [percent of not working] \n 12 Filter compressor station [name] \n\n"
        << " 13 Save \n 14 Load \n 0 Exit \n";
}

// Функции вывода, добавления, редактирования и удаления объектов труб
void show_object_pipe(const unordered_map <int, pipeline>& mp)
{
    if (mp.size())
    {
        for (auto iter : mp)
            cout << iter;
    }
    else { std::cout << "\n Sorry, we found no one pipeline" << endl; }
}

void add_object_pipe(unordered_map <int, pipeline>& mp)
{
    int max = 0;
    for (auto iter : mp)
    {
        if (iter.first > max)
            max = iter.first;
    }
    cout << max;
    cin << mp[max + 1];
}

// Функции вывода, добавления, редактирования и удаления объектов КС
void show_object_cs(const unordered_map <int, cs>& mp)
{
    if (mp.size())
        for (auto iter : mp)
            cout << iter;
    else
        cout << "\n Sorry, we found no one compressor station" << endl;
}

void add_object_cs(unordered_map <int, cs>& mp)
{
    auto iter = mp.end();
    cin << mp[mp.size() != 0 ? iter--, iter->first : 1];
}

bool checker_exist_file(const string& name_file)
{
    ifstream exist(name_file + ".txt"); // Проверка существования файла
    bool file_exist;
    exist.is_open() ? file_exist = 1 : file_exist = 0;
    exist.close();
    return(file_exist);
}

void save_data(const unordered_map <int, pipeline>& mp_pipe, const unordered_map <int, cs>& mp_cs)
{
    cout << "\n Enter the name of file, using for saving data: ";
    string name_file;
    getline(cin, name_file);
    ofstream outing(name_file + ".txt",
        checker_exist_file(name_file) ? /*if true ->*/ cout << "The file with this name is exist. Rewrite file ? 1 Yes/ 0 No: ", checker_bool() : 0 ? ios::out : ios::app);

    if (outing.is_open())
    {
        if (mp_pipe.size())
            for (auto iter : mp_pipe)
                outing << iter;
        if (mp_cs.size())
            for (auto iter : mp_cs)
                outing << iter;
        outing.close();
    }
    cout << "\n Data "; (mp_pipe.size()) || (mp_cs.size()) ? cout << "have" : cout << "haven't"; cout << " been saved";
}

void load_data(unordered_map <int, pipeline>& mp_pipe, unordered_map <int, cs>& mp_cs)
{
    string name_file;
    while (1) {
        cout << "\n Enter the name of file, using for loading data: ";
        getline(cin, name_file);
        if (checker_exist_file(name_file))
        {
            cout << "\n This file has been find ";
            break;
        }
        else
        {
            cout << " We cannot find this file. Try again ? Yes 1/ No 0: ";
            if (checker_bool() == false)
                break;
        }
    }

    ifstream ining(name_file + ".txt");
    if (ining.is_open())
    {
        int type;
        int id = 0;
        while (ining >> type) // Считывание данных из файла до конца файла
        {
            ining >> id;
            ining.ignore();
            if (type == 1)
                ining >> mp_pipe[id];
            if (type == 2)
                ining >> mp_cs[id];
        }
        ining.close();
        cout << "\n Data "; (mp_pipe.size()) || (mp_cs.size()) ? cout << "have" : cout << "haven't"; cout << " been download";
    }
}

void offer_interacte(unordered_map <int, pipeline>& mp, vector<int>& found_objects) {
    cout << "\n Would you like edit this pipelines ? 1 Yes/ 0 No: ";
    if (checker_bool() == false)
        return;
    cout << "\n Choice what you want to edit, enter 0 for All or through a space ID of object: ";
    string string_id, delimeter_id = " ", temp;
    getline(cin, string_id);
    size_t position = 0;
    if (string_id != "0") {
        found_objects.clear();
        while (position < string_id.size()) {
            temp = temp.assign(string_id, position, string_id.find(delimeter_id, position) - position);
            found_objects.push_back(stoi(temp));
            position += temp.size() + delimeter_id.size();
        }
    }

    cout << "\n Edit or Delete ? 1/2: ";
    switch (checker(1, 2)) {
    case 1: {
        cout << "\n Set new repair status: "; bool new_status = checker_bool();
        for (int i : found_objects)
            mp[i].set_repair(new_status);
        break;
    }
    case 2: {
        for (int i : found_objects)
            mp.erase(i);
        break;
    }
    default: {
        break;
    }
    }

}

