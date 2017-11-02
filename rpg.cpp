#include "rpg.h"

void Print_stats(char* name, int phys_att, int phys_def, int mag_att, int mag_def, int health) {
	std::cout<<name<<std::endl;
	std::cout<<"Health:	"<<health<<std::endl;
	std::cout<<"		Atk		Def"<<std::endl;
	std::cout<<"Physical:	"<<phys_att<<"	|	"<<phys_def<<std::endl;
	std::cout<<"Magical:	"<<mag_att<<"	|	"<<mag_def<<std::endl;
	std::cout<<std::endl<<std::endl;
}

void Choose_stats(char* name, int& phys_att, int& phys_def, int& mag_att, int& mag_def, int& health) {
	int available_points = AVAILABLE_POINTS - 1;
	int input_value = 0;
	
	std::cout<<"You have "<<available_points<<" points to spend"<<std::endl;
	std::cout<<"You have 4 skills to spend points on"<<std::endl;
	std::cout<<"1. physical attack"<<std::endl;
	std::cout<<"2. physical defence"<<std::endl;
	std::cout<<"3. magical attack"<<std::endl;
	std::cout<<"4. magical defence"<<std::endl;
	std::cout<<"leftover points * 2 is your health (at least 2)"<<std::endl<<std::endl;
	
	// phys_att
	std::cout<<"You have "<<available_points<<" points left to spend"<<std::endl;
	std::cout<<"Enter your physical attack value:		";
	std::cin>>input_value;
	while((input_value > available_points) || (input_value < 0)) {
		std::cout<<"Something's wrong. Insert different value"<<std::endl;
		std::cout<<"You have "<<available_points<<" points left to spend"<<std::endl;
		std::cin>>input_value;
	}
	available_points -= input_value;
	phys_att += input_value;
	
	// phys_def
	std::cout<<"You have "<<available_points<<" points left to spend"<<std::endl;
	std::cout<<"Enter your physical defence value:		";
	std::cin>>input_value;
	while((input_value > available_points) || (input_value < 0)) {
		std::cout<<"Somethings wrong. Insert different value"<<std::endl;
		std::cout<<"You have "<<available_points<<" points left to spend"<<std::endl;
		std::cin>>input_value;
	}
	available_points -= input_value;
	phys_def += input_value;
	
	// mag_att
	std::cout<<"You have "<<available_points<<" points left to spend"<<std::endl;
	std::cout<<"Enter your magical attack value:		";
	std::cin>>input_value;
	while((input_value > available_points) || (input_value < 0)) {
		std::cout<<"Somethings wrong. Insert different value"<<std::endl;
		std::cout<<"You have "<<available_points<<" points left to spend"<<std::endl;
		std::cin>>input_value;
	}
	available_points -= input_value;
	mag_att += input_value;
	
	// mag_def
	std::cout<<"You have "<<available_points<<" points left to spend"<<std::endl;
	std::cout<<"Enter your magical defence value:		";
	std::cin>>input_value;
	while((input_value > available_points) || (input_value < 0)) {
		std::cout<<"Somethings wrong. Insert different value"<<std::endl;
		std::cout<<"You have "<<available_points<<" points left to spend"<<std::endl;
		std::cin>>input_value;
	}
	available_points -= input_value;
	mag_def += input_value;
	
	health = 2 * (available_points + 1);
	
	std::cout<<"You have selected your stats."<<std::endl<<std::endl;
	std::cout<<" - - - - -"<<std::endl<<std::endl;
	Print_stats(name, phys_att, phys_def, mag_att, mag_def, health);
}

void Add_stat(char* name, int& phys_att, int& phys_def, int& mag_att, int& mag_def, int& health) {
	int choice = 0;
	
	Print_stats(name, phys_att, phys_def, mag_att, mag_def, health);
	std::cout<<"choose stat to upgrade"<<std::endl;
	std::cout<<"1. physical attack + 1"<<std::endl;
	std::cout<<"2. physical defence + 1"<<std::endl;
	std::cout<<"3. magical attack + 1"<<std::endl;
	std::cout<<"4. magical defence + 1"<<std::endl;
	std::cout<<"5. health + 2"<<std::endl;
	
	std::cin>>choice;
	
	while(choice < 1 || choice > 5) {
		std::cout<<"Something went wrong. Pick again"<<std::endl;
		std::cin>>choice;
	}
	
	std::cout<<std::endl;
	
	switch(choice) {
		case 1:
			std::cout<<"you chose physical attack"<<std::endl;
			phys_att++;
			break;
		case 2:
			std::cout<<"you chose physical defence"<<std::endl;
			phys_def++;
			break;
		case 3:
			std::cout<<"you chose magical attack"<<std::endl;
			mag_att++;
			break;
		case 4:
			std::cout<<"you chose magical defence"<<std::endl;
			mag_def++;
			break;
		case 5:
			std::cout<<"you chose health"<<std::endl;
			health+=2;
			break;
	}
	std::cout<<std::endl;
	Print_stats(name, phys_att, phys_def, mag_att, mag_def, health);
}

void Death() {
	std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<"YOU DIED"<<std::endl<<"GAME OVER"<<std::endl<<std::endl<<std::endl<<std::endl;
	std::cout<<"Press \"ENTER\" to continue"<<std::endl<<std::endl;
	std::cout<<"- - - - - - - - - -"<<std::endl<<std::endl;
	// first get() gets cache
	std::cin.get();
	// second get() gets "ENTER"
	std::cin.get();
}
