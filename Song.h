#ifndef SONG_H_
#define SONG_H_
#include <iostream>
#include <string>
#include <iomanip>

class Song {

	friend std::ostream &operator<<(std::ostream &os, const Song &obj);
	private:
		std::string name_ {};
		std::string title_ {};
		int rating_ {};
	public:
		std::string GetName() {return name_;}
		std::string GetTitle() {return title_;}
		int GetRating() {return rating_;}
		
		bool operator<(const Song &rhs);
		bool operator==(const Song &rhs);		
};

#endif
