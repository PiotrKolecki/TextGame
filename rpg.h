#include <iostream>
#pragma once

// defines how many starting points the Hero has
#define AVAILABLE_POINTS 20

// prints all info about character
void Print_stats(char* name, int phys_att, int phys_def, int mag_att, int mag_def, int health);

// startup stats picking
// "char* name" is needed to be able to print stats
void Choose_stats(char* name, int& phys_att, int& phys_def, int& mag_att, int& mag_def, int& health);

// after defeating monster you can pick one stat to upgrade, so all need to be passed
// "char* name" is needed to be able to print stats after picking one
void Add_stat(char* name, int& phys_att, int& phys_def, int& mag_att, int& mag_def, int& health);

// in case character died
void Death();
