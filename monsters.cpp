#include "monsters.h"
#include "rpg.h"

void Generate_monster(char* name, int& phys_att, int& phys_def, int& mag_att, int& mag_def, int& health, int& level) {
	int available_points = level;
	
	srand(time(NULL));
	
	// randomize monster name
	int name_ID = (std::rand() % 3);
	switch(name_ID) {
		case 0:
			strncpy(name, "Dragon", 6);
			break;
		case 1:
			strncpy(name, "Goblin", 6);
			break;
		case 2:
			strncpy(name, "Pigeon", 6);
			break;
	}
	
	// randomize stats
	srand(std::rand());
	// "% available_points" returns number <0, available_points - 1>
	// but that's intended so at least one point is left for health
	phys_att = available_points ? std::rand() % available_points : 0;
	available_points -= phys_att;

	srand(std::rand());
	// re-seed everytime to make it more random
	phys_def = available_points ? std::rand() % available_points : 0;
	available_points -= phys_def;
	
	srand(std::rand());
	mag_att = available_points ? std::rand() % available_points : 0;
	available_points -= mag_att;
	
	srand(std::rand());
	mag_def = available_points ? std::rand() % available_points : 0;
	available_points -= mag_def;
	
	// leftover points for health
	health = available_points * 2;
	
	std::cout<<"You have encountered: "<<std::endl<<std::endl;
	Print_stats(name, phys_att, phys_def, mag_att, mag_def, health);
	level += MONSTER_LVL_UP;
	std::cout<<"Press \"ENTER\" to continue"<<std::endl<<std::endl;
	std::cout<<"- - - - - - - - - -"<<std::endl<<std::endl;
	// first get() gets cache
	std::cin.get();
	// second get() gets "ENTER"
	std::cin.get();
}

void Attack(int attack, int defence, int& health) {
	srand(time(NULL));
	int damage = (attack + ((int)(attack/2) ? rand() % (int)(attack/2) : 0)) - (defence + ((int)(defence/2) ? rand() % (int)(defence/2) : 0));
	std::cout<<"dealt "<<(damage > 0 ? damage : 0)<<" damage points"<<std::endl<<std::endl;
	std::cout<<"- - - - - - - - - -"<<std::endl<<std::endl;
	health -=  damage > 0 ? damage : 0;
}

void Monster_death(char* name, int& phys_att, int& phys_def, int& mag_att, int& mag_def, int number_of_monsters) {
	std::cout<<"You defeated "<<name<<std::endl<<std::endl;
}


void Print_defeated_monsters(char** names, int* phys_att, int* phys_def, int* mag_att, int* mag_def, int number_of_monsters) {
	
}
