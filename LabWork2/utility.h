#pragma once
#include <unordered_map>
#include "pipe.h"
#include "cs.h"

int checker();
int checker(int a, int b);
bool checker_bool();

void help();
void add_object_pipe(unordered_map <int, pipeline>& mp);
void show_object_pipe(const unordered_map <int, pipeline>& mp);
void add_object_cs(unordered_map <int, cs>& mp);
void show_object_cs(const unordered_map <int, cs>& mp);

void save_data(const unordered_map <int, pipeline>& mp_pipe, const unordered_map <int, cs>& mp_cs);
void load_data(unordered_map <int, pipeline>& mp_pipe, unordered_map <int, cs>& mp_cs);

void offer_interacte(unordered_map <int, pipeline>& mp, vector<int>& found_objects);

