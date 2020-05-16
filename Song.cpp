#include "Song.h"

std::ostream &operator<<(std::ostream &os, const Song &obj) {
	os << std::setw(30) << std::left << obj.GetName() 
       		<< std::setw(30) << std::left << obj.GetArtist() 
		<< std::setw(5) << std::left << obj.GetRating();
	return os;	
}
