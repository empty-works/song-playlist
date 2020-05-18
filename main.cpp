#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <list>
#include "Song.h"

Song PlayFirstSong(std::list<Song> &song_list);
Song PlayNextSong(std::list<Song> &song_list, const Song &current_song);
Song PlayPreviousSong(std::list<Song> &song_list, const Song &current_song);
Song AddSong(std::list<Song> &song_list, const Song &current_song);
void ListSongs(const std::list<Song> &song_list);

int main() {
	
	std::vector<Song> songs {
		Song {"Imagination", "Foster The People", 5}, 
		Song {"Love Moon", "Josiah Bell", 5}, 
		Song {"Dream Eyes", "Mokhov", 5}, 
		Song {"Double Up", "Nipsey Hussle", 5}, 
		Song {"On Chill", "Wale", 5}
	};

	std::list<Song> song_list;
      	std::copy(songs.begin(), songs.end(), std::back_inserter(song_list));	
	char selection;

	Song current_song {PlayFirstSong(song_list)};
	do {
		std::cout << std::setw(3) << std::left << "F" << std::setw(3) << std::left << "-" << "Play First Song" << std::endl;
		std::cout << std::setw(3) << std::left << "N" << std::setw(3) << std::left << "-" << "Play Next Song" << std:: endl;
		std::cout << std::setw(3) << std::left << "P" << std::setw(3) << std::left << "-" << "Play Previous Song" << std::endl;
		std::cout << std::setw(3) << std::left << "A" << std::setw(3) << std::left << "-" << "Add and play a new song at current location" << std::endl;	
		std::cout << std::setw(3) << std::left << "L" << std::setw(3) << std::left << "-" << "List the current playlist" << std::endl;
		std::cout << "============================================================" << std::endl;
		std::cout << "Enter a selection (Q to quit)" << std::endl;	

		std::cin >> selection;
		selection = std::toupper(selection);
		std::cin.clear();
		std::cin.ignore(100, '\n');

		switch(selection) {
			case 'F': 
				{
					current_song = PlayFirstSong(song_list);
					break;
				}
			case 'N':
				{
					current_song = PlayNextSong(song_list, current_song);
					break;
				}
			case 'P':
				{
					current_song = PlayPreviousSong(song_list, current_song);
					break;
				}
			case 'A':
				{
					current_song = AddSong(song_list, current_song);
					break;
				}
			case 'L':
				{
					ListSongs(song_list);
					break;
				}
			default: std::cout << "Error: illegal selection." << std::endl << std::endl;	
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
	std::cout << "Playing:" << std::endl;	
	auto it = std::find(song_list.begin(), song_list.end(), Song{current_song.GetName(), current_song.GetArtist(), current_song.GetRating()});
	if(++it == song_list.end())
		it = song_list.begin();	
	std::cout << *it << std::endl;
	std::cout << std::endl;
	return *it;
}

Song PlayPreviousSong(std::list<Song> &song_list, const Song &current_song) {
	std::cout << "Playing previous song" << std::endl;
	std::cout << "Playing:" << std::endl;
	auto it = std::find(song_list.begin(), song_list.end(), Song{current_song.GetName(), current_song.GetArtist(), current_song.GetRating()});
	if(it == song_list.begin()) {
		it = song_list.end();
	}
	--it;
	std::cout << *it << std::endl;
	std::cout << std::endl;
	return *it;
}

Song AddSong(std::list<Song> &song_list, const Song &current_song) {
	std::string song_title {};
	std::cout << "Song title: ";
	std::getline(std::cin, song_title);
	std::string song_artist {};
	std::cout << "Song artist: ";
	std::getline(std::cin, song_artist);
	int rating {};
	std::cout << "Song rating: ";
	std::cin >> rating;
	Song new_song {song_title, song_artist, rating};
	song_list.push_front(new_song);
	std::cout << "Playing: " << std::endl;
	std::cout << new_song << std::endl;
	std::cout << std::endl;
	return new_song;		
}
