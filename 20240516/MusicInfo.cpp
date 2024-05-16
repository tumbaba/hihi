#include "MusicInfo.h"

//MusicInfo::MusicInfo() :title("unknown"), genre("x"), singer("unknown"), playing("no data")
//{
//}

//MusicInfo::MusicInfo(string title, string genre, string singer):title(title), genre(genre), singer(singer)
//{
//	playing = "now playing " + singer + "-" + title;
//}





string MusicInfo::getTitle()
{
	return title;
}

string MusicInfo::getSinger()
{
	return singer;
}

string MusicInfo::getGenre()
{
	return genre;
}

string MusicInfo::getReleaseData()
{
	return releaseDate;
	
}

string MusicInfo::getPlaying()
{
	return playing;
}

//void MusicInfo::Play()
//{
//	cout << playing << endl;
//}
//
void MusicInfo::Display()
{

	cout << title << "\t\t" << genre << "\t\t" << singer << endl;
}

