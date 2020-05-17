#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <list>
#include "Song.h"

Song PlayFirstSong(std::list<Song> &song_list);
Song PlayNextSong(std::list<Song> &song_list, const Song &current_song);
void PlayPreviousSong();
void AddSong();
void ListSongs(const std::list<Song> &song_list);

int main() {
	
	std::vector<Song> songs {
		Song {"Imagination", "Foster The People", 5}, 
		Song {"Love Moon", "Josiah Bell", 5}, 
		Song {"Dream Eyes", "Mokhov", 5}, 
		Song {"Double Up", "Nipsey Hussle", 5}, 
		Song {"On Chill", "Wale", 5}
	};

	Song current_song {};
	std::list<Song> song_list;
      	std::copy(songs.begin(), songs.end(), std::back_inserter(song_list));	
	std::list<Song>::iterator it = song_list.begin();
	char selection;

	PlayFirstSong(song_list);
	do {
		std::cout << std::setw(3) << std::left << "F" << std::setw(3) << std::left << "-" << "Play First Song" << std::endl;
		std::cout << std::setw(3) << std::left << "N" << std::setw(3) << std::left << "-" << "Play Next Song" << std:: endl;
		std::cout << std::setw(3) << std::left << "P" << std::setw(3) << std::left << "-" << "Play Previous Song" << std::endl;
		std::cout << std::setw(3) << std::left << "A" << std::setw(3) << std::left << "-" << "Add and play a new song at current location" << std::endl;	
		std::cout << std::setw(3) << std::left << "L" << std::setw(3) << std::left << "-" << "List the current playlist" << std::endl;
		std::cout << "============================================================" << std::endl;
		std::cout << "Enter a selection (Q to quit)" << std::endl;	

		std::cin >> selection;
		std::cin.clear();
		std::cin.ignore(100, '\n');

		switch(selection) {
			case 'f':
			case 'F': 
				{
					PlayFirstSong(song_list);
					break;
				}
			case 'l':
			case 'L':
				{
					ListSongs(song_list);
					break;
				}	
		}

	}while(selection != 'q' && selection != 'Q');

	return 0;
}

Song PlayFirstSong(std::list<Song> &song_list) {
	std::cout << std::endl;
	std::cout << "Playing first song" << std::endl;
	std::cout << "Playing:" << std::endl;
	auto it = song_list.begin();
	std::cout << *it << std::endl << std::endl;
	return *it;
}

void ListSongs(const std::list<Song> &song_list) {
	std::cout << std::endl;
	std::cout << "Listing all songs" << std::endl;
	auto it = song_list.begin();
	while(it != song_list.end()) {
		std::cout << *it << std::endl;
		it++;
	}	
	std::cout << std::endl;
}

Song PlayNextSong(std::list<Song> &song_list, const Song &current_song) {
	
	std::cout << "Playing next song" << std::endl;	
}
