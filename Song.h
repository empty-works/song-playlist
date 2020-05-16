#ifndef SONG_H_
#define SONG_H_
#include <string>

class Song {
	private:
		std::string name_ {};
		std::string title_ {};
		int rating_ {};
	public:
		std::string GetName() {return name_;}
		std::string GetTitle() {return title_;}
		int GetRating() {return rating_;}		
};

#endif
