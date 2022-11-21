#include <iostream>
#include "pipe.h"
#include "cs.h"
#include "utility.h"
#include "temp.h"

int main()
{
    int cmmnd = 1; // Переменная, хранящая команду пользователя 
    unordered_map <int, pipeline> mp_pipe;
    unordered_map <int, cs> mp_cs;

    do { // Цикл для считывания комманд пользователя
        switch (cmmnd) { // Выбор опций в главном меню
        case 0: {
            return(0);
        }
        case 1:
            help();
            break;

        case 2: { // Показать все объекты
            show_object_pipe(mp_pipe);
            show_object_cs(mp_cs);
            break;
        }
        case 3: { // Добавить трубу
            add_object_pipe(mp_pipe);
            break;
        }
        case 4: { // Редактировать  трубу
            interact(mp_pipe, edit_pipe);
            break;
        }
        case 5: { // Удалить трубу
            interact(mp_pipe, delete_pipe);
            break;
        }
        case 6: { // Добавить кс
            add_object_cs(mp_cs);
            break;
        }
        case 7: { // Редактировать КС
            interact(mp_cs, edit_cs);
            break;
        }
        case 8: { // Удалить КС
            interact(mp_cs, delete_cs);
            break;
        }
        case 9: { // Фильтрация и редактирование труб по ремонту
            filtering_pipe_repair(mp_pipe);
            break;
        }
        case 10: { // Фильтрация труб по названию
            filtering_pipe_name(mp_pipe);
            break;
        }
        case 11: { // Фильтрация КС по проценту задействованных цехов
            filtering_cs_workshops_on(mp_cs);
            break;
        }
        case 12: { // Фильтрация КС по названию
            filtering_cs_name(mp_cs);
            break;
        }
        case 13: { // Сохранение данных в файл
            save_data(mp_pipe, mp_cs);
            break;
        }
        case 14: { // Чтение данных из файла
            load_data(mp_pipe, mp_cs);
            break;
        }
        default: {
            break;
        }
        }
        cout << "\n Main Menu >> ";
        cmmnd = checker(0, 14);
    } while (1);
    cout << " Good luck!\n\n\n";
}