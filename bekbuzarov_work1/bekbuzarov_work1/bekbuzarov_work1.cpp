#include <iostream>
#include <limits>
#include <string>
#include <fstream>
using namespace std;

// Пользовательские данные
struct pipeline
{
    int dlina = 0;
    double diameter = 0;
    bool repair = 0; // 0 Функционирует, 1 Находится в ремонте
};

struct compr_station
{
    string name_cs;
    int colvo_cehov = 0;
    int colvo_rabot_cehov = 0;
    double efficiency = 0;
};

// Функции проверки ввода 
bool proverka_bool()
{
    bool in;
    do {
        if (cin >> in)
        {
            cin.ignore(1024, '\n');
            return(in);
        }
        else
        {
            cout << "\n Incorrect input. Try again. Enter 0 or 1: ";
            cin.clear();
            cin.ignore(1024, '\n');
        }
    } while (1);
};

int proverka_polozhit()
{
    int in;
    do {
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
    } while (1);
}

int pr_ab_interval(int a, int b) // Проверка на число в интервале от a до b включительно
{
    int in;
    do {
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
    } while (1);
}

// Функции вывода информации
void show_truba(const pipeline& some_pipe)
{
    if (some_pipe.diameter)
    {
        cout << "\n The pipeline has next specification" << endl;
        cout << " The length of pipeline: " << some_pipe.dlina << endl;
        cout << " The pipeline's diameter: " << some_pipe.diameter << endl;
        cout << " Repair status: " << some_pipe.repair << endl;
    }
    else
    {
        std::cout << "\n Sorry, We found no pipeline" << endl;
    }
}

void show_cs(const compr_station& some_cs)
{
    if (some_cs.colvo_cehov)
    {
        cout << "\n Compressor Station has next specification" << endl;
        cout << " The compressor station's name: " << some_cs.name_cs << endl;
        cout << " Compressor station consist of [" << some_cs.colvo_cehov << "] workshops" << endl;
        cout << " And [" << some_cs.colvo_rabot_cehov << "] workshops are WORKING " << endl;
        cout << " Compressor station's efficiency: [ " << some_cs.efficiency << " %]" << endl;

    }
    else
    {
        cout << "\n Sorry, We found no compressor station" << endl;
    }
}

// Функции добавления информации
void add_pipe(pipeline& some_pipe) // Добавления трубы
{
    if (some_pipe.diameter)
    {
        cout << "\n We have already writing pipeline. The new pipeline will have rewrited old pipeline" << endl;
        cout << " Continue Yes 1 / No 0 ? ";
        if (proverka_bool())
        {
            cout << "\n Rewriting... " << endl;;

        }
        else
        {
            cout << "\n Canceled " << endl;;
            return;
        }
    }

    cout << "\n Enter the length of pipeline in meters: ";
    some_pipe.dlina = proverka_polozhit();

    cout << " Enter pipeline's the diameter in millimeters: ";
    some_pipe.diameter = proverka_polozhit();

    cout << " Enter pipeline's status (0 working, 1 in the repair): ";
    some_pipe.repair = proverka_bool();
}

void add_cs(compr_station& some_cs) // Добавление КС
{
    if (some_cs.colvo_cehov)
    {
        cout << "\n We have already writing compressor station. The new compressor station will have rewrited old compressor station " << endl;
        cout << " Continue Yes 1 / No 0 ? ";
        if (proverka_bool())
        {
            cout << "\n Rewriting... " << endl;;
        }
        else
        {
            cout << "\n Canceled " << endl;
            return;
        }
    }


    cout << "\n Enter the compressor station's name: ";
    cin.ignore();
    getline(cin, some_cs.name_cs);

    do {
        cout << " Enter the number of the ALL workshops: ";
        some_cs.colvo_cehov = proverka_polozhit();

        cout << " Enter the number of WORKING workshops: ";
        some_cs.colvo_rabot_cehov = proverka_polozhit();
        if (some_cs.colvo_rabot_cehov > some_cs.colvo_cehov)
        {
            cout << "\n WORKING workshops can't be more than ALL workshops. Try again \n" << endl;
        }
        else
        {
            break;
        }
    } while (1);

    cout << " Enter the efficiency of the compressor station: ";
    some_cs.efficiency = pr_ab_interval(0, 100);
}

// Фукнции редактирования информации
void edit_pipe(pipeline& some_pipe) // Редактирование трубы
{
    if (some_pipe.diameter == 0)
    {
        cout << "\n The pipeline's information hasn't found " << endl;
        return;
    }

    cout << "\n Old repair status: " << some_pipe.repair << endl;;
    cout << " Enter the new repair status: ";
    some_pipe.repair = proverka_bool();

    cout << "\n Accepted" << endl;
}

void edit_cs(compr_station& some_cs) // Редактирование КС
{
    if (some_cs.colvo_cehov == 0)
    {
        std::cout << "\n The compressor station's information hasn't found " << endl;
        return;
    }

    cout << "\n Old number ALL workshops: " << some_cs.colvo_cehov << endl;
    cout << " Old number WORKING workshops: " << some_cs.colvo_rabot_cehov << endl;

    do {
        cout << " Enter the new number of the WORKING workshops: ";
        some_cs.colvo_rabot_cehov = proverka_polozhit();

        if (some_cs.colvo_rabot_cehov > some_cs.colvo_cehov)
        {
            cout << "\n The number of WORKING workshops can't be more than ALL workshop. Try again \n" << endl;
        }
        else
        {
            break;
        }
    } while (1);
    cout << "\n Accepted" << endl;
}

//ввод в файл
void save_data(pipeline& some_pipe, compr_station& some_cs)
{
    if (some_pipe.diameter || some_cs.colvo_cehov)
    {
        cout << "\n Rewrite file ? 1 Yes / 0 No: ";
        ofstream outing("DataFile.txt",
            proverka_bool() ? ios::out :
            ios::app);

        if (outing.is_open())
        {
            if (some_pipe.diameter)
            {
                outing << 1 << endl;
                outing << some_pipe.dlina << endl;
                outing << some_pipe.diameter << endl;
                outing << some_pipe.repair << endl;
                outing << endl;
            }

            if (some_cs.colvo_cehov)
            {
                outing << 2 << endl;
                outing << some_cs.name_cs << endl;
                outing << some_cs.colvo_cehov << endl;
                outing << some_cs.colvo_rabot_cehov << endl;
                outing << endl;
            }
            outing.close();
        }
        cout << "\n Data have been saved" << endl;
    }
    else
    {
        cout << "\n No data to save" << endl;
    }
}

//вывод из файла 
void load_data(pipeline& some_pipe, compr_station& some_cs)
{
    ifstream ining("DataFile.txt");
    int type;
    if (ining.is_open())
    {
        while (ining >> type) // Считывание данных из файла до конца файла
        {
            if (type == 1)
            {
                ining >> some_pipe.dlina;
                ining >> some_pipe.diameter;
                ining >> some_pipe.repair;
            }
            if (type == 2)
            {
                ining.ignore();
                getline(ining, some_cs.name_cs);
                ining >> some_cs.colvo_cehov;
                ining >> some_cs.colvo_rabot_cehov;
                ining >> some_cs.efficiency;
            }
            ining.clear();
            ining.ignore(1024, '\n');
        }
        if ((some_pipe.diameter) || (some_cs.colvo_cehov))
        {
            cout << "\n Data have been download" << endl;
        }
        else
        {
            cout << "\n Nothing to download" << endl;
        }
    }
    ining.close();
}
int main()
{
    int cmmnd = 1; // Переменная, хранящая команду пользователя 
    cout << "Welcome to Gas Transporation Systems\nIt's friendly working terminal\nPlease enter a command.\n\n";

    // Реализация комманд
    pipeline numb_pipeline; // Название структуры трубы
    compr_station numb_cs; // Название структуры КС

    do { // Цикл для считывания комманд пользователя
        switch (cmmnd) { // Выбор опций в главном меню
        case 0: {
            return(0);
        }
        case 1: {
            cout << "\n 1 Help \n\n 2 Show All Objects \n\n 3 Add Pipeline \n\n 4 Add Compressor Stations \n\n 5 Edit Repair Status of Pipeline \n\n 6 Edit Number of Working Worhshops \n\n";
            cout << " 7 Save \n\n 8 Load \n\n 0 Exit";
            break;
        }
        case 2: { // Показать все объекты
            show_truba(numb_pipeline);
            show_cs(numb_cs);
            break;
        }
        case 3: { // Добавить трубу
            add_pipe(numb_pipeline);
            break;
        }
        case 4: { // Добавить кс
            add_cs(numb_cs);
            break;
        }
        case 5: { // Редактировать  трубу
            edit_pipe(numb_pipeline);
            break;
        }

        case 6: { // Редактировать КС
            edit_cs(numb_cs);
            break;
        }
        case 7: { // Сохранение данных в файл
            save_data(numb_pipeline, numb_cs);
            break;
        }
        case 8: { // Чтение данных из файла
            load_data(numb_pipeline, numb_cs);
            break;
        }
        default: {
            break;
        }
        }

        cout << "\n Main Menu >> ";
        cmmnd = pr_ab_interval(0, 8);
    } while (1);
    cout << " Good luck!\n\n\n";
}