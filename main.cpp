#include "rpg.h"				// printing, stats, death
#include "monsters.h"		// randomizing monster, fighting, defeating monsters

// - - - - -
// © 2017 Piotr.Kolecki.CG
// - - - - -

int main() {
	// Hero section
	char name[33] = {};		// 32 chars at most + '\0'
	int phys_att = 0;
	int phys_def = 0;
	int mag_att = 0;
	int mag_def = 0;
	int health = 0;
	
	// Monster section
	char monster_name[33] = {};		// 32 chars at most + '\0'
	int monster_phys_att = 0;
	int monster_phys_def = 0;
	int monster_mag_att = 0;
	int monster_mag_def = 0;
	int monster_health = 0;
	int monster_level = MONSTER_LEVEL;	// how many points monster has to spend
	
	// recorded monsters
	char* record_monsters_names[33] = {}
	int* record_monsters_phys_att = NULL;
	int* record_monsters_phys_def = NULL;
	int* record_monsters_mag_att = NULL;
	int* record_monsters_mag_def = NULL;
	
	// helpers
	int attack_type = 0;		// 0 -physical ; 1 - magical
	
	// story
	std::cout<<std::endl<<"You wake up on a dirty floor..."<<std::endl<<std::endl;
	std::cout<<"[voice]"<<std::endl<<"	- Who are you?"<<std::endl<<std::endl;
	std::cout<<"You look around but room is in absolute darkness"<<std::endl<<std::endl;
	std::cout<<"[voice]"<<std::endl<<"	- What's your name?"<<std::endl<<std::endl;
	std::cout<<"I'm ";
	std::cin>>name;	// here you name your Hero
	std::cout<<std::endl;
	std::cout<<"You hear voice, but can't locate it's origin"<<std::endl<<std::endl;
	std::cout<<"[voice]"<<std::endl<<"	- Tell me more abot yourself"<<std::endl<<std::endl<<std::endl;
	std::cout<<"Now it's time to choose your attributes"<<std::endl<<std::endl;
	
	// pick starting stats
	Choose_stats(name, phys_att, phys_def, mag_att, mag_def, health);
	
	std::cout<<"[voice]"<<std::endl<<"	- Try not to die here"<<std::endl<<std::endl;
	std::cout<<"	- But you will..."<<std::endl<<std::endl<<std::endl;
	std::cout<<"- - - - - - - - - -"<<std::endl<<std::endl;
	
	// fighting
	while(1) { // keep fighting. end condition inside
		srand(time(NULL));
		std::cout<<"- - - - - - - - - -"<<std::endl<<std::endl;
		std::cout<<"New fight starts"<<std::endl<<std::endl;
		Generate_monster(monster_name, monster_phys_att, monster_phys_def, monster_mag_att, monster_mag_def, monster_health, monster_level);
		
		while(monster_health > 0) { // until monster is alive
			attack_type = rand() % 2;
			
			std::cout<<monster_name<<" ";
			
			switch(attack_type) {
				case 0 :		// physical
					std::cout<<" attacks with physical attack!"<<std::endl;
					Attack(monster_phys_att, phys_def, health);
					break;
				case 1 :		// magical
					std::cout<<" attacks with magical attack!"<<std::endl;
					Attack(monster_mag_att, mag_def, health);
					break;
			}
			Print_stats(name, phys_att, phys_def, mag_att, mag_def, health);
			Print_stats(monster_name, monster_phys_att, monster_phys_def, monster_mag_att, monster_mag_def, monster_health);
			
			if (health <= 0) { // did monster kill hero - end condition
				Death();
				Print_defeated_monsters();
				return 0;
			}
			
			// Hero's turn
			std::cout<<"Choose how you want to attack"<<std::endl;
			std::cout<<"1. physical attack"<<std::endl;
			std::cout<<"2. magical attack"<<std::endl;
			std::cin>>attack_type;
			std::cout<<"You ";
			switch(attack_type) {
				case 1 :		// physical
					Attack(phys_att, monster_phys_def, monster_health);
					std::cout<<std::endl;
					break;
				case 2 :		// magical
					Attack(mag_att, monster_mag_def, monster_health);\
					std::cout<<std::endl;
					break;
				default :
					Attack(phys_att, monster_phys_def, monster_health);
			}
		}
		
		// Hero won
		Monster_death(monster_name, monster_phys_att, monster_phys_def, monster_mag_att, monster_mag_def, number_of_monsters);
		Add_stat(name, phys_att, phys_def, mag_att, mag_def, health);
	}
	
	return 0;
}
