#include <iostream>
#include <vector>
#include <iomanip>
#include "Song.h"

int main() {
	
	std::vector<Song> songs {
		Song {"Imagination", "Foster The People", 5}, 
		Song {"Love Moon", "Josiah Bell", 5}, 
		Song {"Dream Eyes", "Mokhov", 5}, 
		Song {"Double Up", "Nipsey Hussle", 5}, 
		Song {"On Chill", "Wale", 5}
	};
	
	char selection;
	do {
		std::cout << std::setw(3) << std::left << "F" << std::setw(3) << std::left << "-" << "Play First Song" << std::endl;
		std::cout << std::setw(3) << std::left << "N" << std::setw(3) << std::left << "-" << "Play Next Song" << std:: endl;
		std::cout << std::setw(3) << std::left << "P" << std::setw(3) << std::left << "-" << "Play Previous Song" << std::endl;
		std::cout << std::setw(3) << std::left << "A" << std::setw(3) << std::left << "-" << "Add and play a new song at current location" << std::endl;	
		std::cout << std::setw(3) << std::left << "L" << std::setw(3) << std::left << "-" << "List the current playlist" << std::endl;
		std::cout << "============================================================" << std::endl;
		std::cout << "Enter a selection (Q to quit)" << std::endl;	

		std::cin >> selection;
	}while(selection != 'q' && selection != 'Q');

	return 0;
}
