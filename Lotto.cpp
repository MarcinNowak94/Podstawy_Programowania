#include "includes.h"
#include "Modules.h"

//Specification:
//Lotto 1-49 
//start with 0 everywhere
//tablica inwersyjna
//optymisation warning - algorithm must pick least numbers to pick

template<class T = int>
T random(T Min = 1, T Max = 100) {
	std::random_device rd;	//random number
	std::mt19937 Random(rd()); //using random number as seed for generator
	std::uniform_int_distribution<T> Range(Min, Max); //defining range of random numbers
	return Range(Random);
	//date of creation: 03.09.2017
	//Created by: Marcin Nowak
	//https://github.com/MarcinNowak94/DailyCoding/blob/master/DailyCoding/DailyCoding/Helper_functions.h
};


const int range = 49, offset = 1;
int numbers_to_draw=6, tests = 3;
bool to_pick = true;

int initialize(bool ballot[], const bool& mode) {
	for (int number = offset; number <= range; number++) {
		ballot[number] = mode;
	};
	return EXIT_SUCCESS;
};
int initialize_and_inform(bool ballot[], const bool& mode) {
	if (initialize(ballot, mode)) {
		std::cout << "All numbers initialized to " << mode << ".\n"; };
		return EXIT_SUCCESS;
	};

int pick_numbers(bool ballot[], const int& to_draw, const bool & mode) {
	int drawn = 0;
	for (auto draw = 0; draw < to_draw; draw++) {
		drawn = random(offset, range);
		if (!(ballot[drawn]==mode)) {
			ballot[drawn] = mode;
			continue;
		};
		draw--;
	};
	return EXIT_SUCCESS;
};

int show_drawn(const bool ballot[], const bool & mode) {
	for (auto i = offset; i <= range; i++) {
		if (ballot[i] == mode) { std::cout << i << ", ";
		};
	};
	std::cout << "\n";
	return EXIT_SUCCESS;
}


int Lotto() {
	bool drawn_numbers[range + offset]{};					//start with 0 everywhere, RAII all the way
	//simulate user
	do {
		bool reverse_mode = false;
		//simulating possibility of erroneus input
		int numbers_to_draw = random(-10, range * 2);
		if (!(numbers_to_draw >= offset && numbers_to_draw < range)) {
			std::cout << "Error! " << numbers_to_draw 
					  << " is out of <" << offset << " " << range << ") range!\a\n";
			continue;
		};
		std::cout << "Drawing " << numbers_to_draw << " numbers.\n";
		if (!(numbers_to_draw < (range / 2))) {
			reverse_mode = true;
			numbers_to_draw = range-numbers_to_draw;
		};

		initialize_and_inform(drawn_numbers, reverse_mode?to_pick:!to_pick);

		pick_numbers(drawn_numbers, numbers_to_draw, reverse_mode ? !to_pick : to_pick);
		show_drawn(drawn_numbers, to_pick);
		std::cout << "-----------------------------------------------------------\n";
		tests--;
	} while (tests);
	
	std::cout << "Press any key to continue ...\n\a";
	_getch();
	return EXIT_SUCCESS; 
};