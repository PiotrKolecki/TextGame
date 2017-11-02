#include <iostream>
#include <cstdlib>
#include <string.h>
#pragma once

// defines how many starting points monsters has
#define MONSTER_LEVEL 15

// defines how many more points has every next monster
#define MONSTER_LVL_UP 5

// needs all monster stats
void Generate_monster(char* name, int& phys_att, int& phys_def, int& mag_att, int& mag_def, int& health, int& level);

// type is picked in main.cpp
void Attack(int attack, int defence, int& health);

// this one needs stats that will be recorded and a place to store them
void Monster_death(char* name, int& phys_att, int& phys_def, int& mag_att, int& mag_def, int** record_phys_att, int** record_phys_def, int** record_mag_att, int** record_mag_def, int* number_of_monsters);
	
// prints all defeated monsters
void Print_defeated_monsters(int* phys_att, int* phys_def, int* mag_att, int* mag_def, int number_of_monsters);
