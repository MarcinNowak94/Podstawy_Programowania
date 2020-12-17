#include "includes.h"
#include "Modules.h"



//TODO: Generalize and change rand() for something good
int random_num(int begin = 0, int end = 99) {
	
	return(std::rand() % end);
};

/*REQUIREMENTS:
zdefiniowaæ n=10 						//Iloœæ elementów tablicy
wczytaæ wartoœci (wygenerowaæ losowo)
dane int/float 							//TODO:funkcja szablonowa lub konkretyzacja
obliczyæ wartoœæ sumaryczn¹
obliczyæ œredni¹
zadaæ wartoœæ poszukiwan¹ - wczytaæ przez u¿ytkownika 
przeszukuj¹c tablicê wypisywaæ indexy pod którymi ta wartoœæ siê znalaz³a
jeœli nie ma elementu - wypisaæ komunikat 'Nie znaleziono'

//Wariant 2:
//Szukanie w przedziale od <A, B> wypisywane nie tylko indeksy ale i wartoœci
//zabezpieczyæ siê przed b³êdnym podaniem A i B (a<=b)

//[sugestia]Menu ? - mo¿na wykorzystaæ swój wczeœniejszy kod //Round of applause for simple_menu_cmd ladies & gentelmen <3

Wyszukaæ wartoœæ maksymaln¹ i minimaln¹ - znalezienie ekstremów
- jeœli tablica ma 1 element ?
- jeœli tablica ma 1000 identycznych elementów 

*/

int find_in_array(const int array[], int last_elem = 0, int range_start=0, int range_end=0) {
	bool found = false;
	for (auto element = 0; element < last_elem; element++) {
		if (!(array[element] >= range_start && array[element] <= range_end)) continue;
		found = true;
		std::cout << "Element found at index " << element << " value: " << array[element] << '\n';
	};
	if (!found) { std::cout << "Elements not found\n"; };
	return EXIT_SUCCESS; 
}

int find_in_array_min(const int array[], int last_elem = 0) {
	int min = INT_MAX;
	for (auto element = 0; element < last_elem; element++) {
		if (!(array[element] <= min)) continue;
		min = array[element];
	};
	std::cout << "Minimum element value: " << min << '\n';
	return EXIT_SUCCESS;
};

int find_in_array_max(const int array[], int last_elem = 0) {
	int max = INT_MIN;
	for (auto element = 0; element < last_elem; element++) {
		if (!(array[element] <= max)) continue;
		max = array[element];
	};
	std::cout << "Maximum element value: " << max<< '\n';
	return EXIT_SUCCESS;
};

int Module_02() {
	const unsigned int elements = 10;	//TODO: Once array has been generalized this has to be computed
	int values[elements] = {};			//TODO: generalize 
	const int minval = 0, 
		      maxval = 200;
	std::srand(std::time(nullptr));

	for (size_t element = 0; element < elements; element++) {
		values[element] = random_num(minval, maxval);
		std::cout << values[element] << ' ';
	}
	
	int sum_of_values = 0;
	for (size_t element = 0; element < elements; element++) {
		sum_of_values += values[element];
	}

	int mean = sum_of_values / elements;
	std::cout << "\nSum of all values = " << sum_of_values << '\n'
		      << "Mean = " << mean << '\n';

	int sought = 0, 
		sought_range_start=0, 
		sought_range_end=0;
	bool found = 0;
	std::cout << "Input value You are searching for [min: "<< minval << " max: "<< maxval <<"]: ";
	std::cin >> sought;
	find_in_array(values, elements, sought, sought);

	std::cout << "Input value range You are searching for [min: " << minval << " max: " << maxval << "]: \n";
	while (true) {
		std::cout << "Range start:\t";
		std::cin >> sought_range_start;
		std::cout << "Range end:\t";
		std::cin >> sought_range_end;
		if (sought_range_start <= sought_range_end) break;
	};
	find_in_array(values, elements, sought_range_start, sought_range_end);

	find_in_array_min(values, elements);
	find_in_array_max(values, elements);


	return EXIT_SUCCESS;
};


