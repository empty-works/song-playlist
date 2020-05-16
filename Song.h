#ifndef SONG_H_
#define SONG_H_
#include <iostream>
#include <string>
#include <iomanip>

class Song {

	friend std::ostream &operator<<(std::ostream &os, const Song &obj);
	private:
		std::string name_ {};
		std::string artist_ {};
		int rating_ {};
	public:
		Song() = default;
		Song(std::string name, std::string artist, int rating) 
			:name_ {name}, artist_ {artist}, rating_ {rating} {}
		std::string GetName() const {return name_;}
		std::string GetArtist() const {return artist_;}
		int GetRating() const {return rating_;}
		
		bool operator<(const Song &rhs);
		bool operator==(const Song &rhs);		
};

#endif
