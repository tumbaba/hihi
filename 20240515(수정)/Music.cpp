
#include "Music.h"

#include "stdafx.h"



void Music::init(string g, string si, string so, string l)   
{
	genre = g;
	singer = si;  
	song = so;
	lyrics = l;
}








void Music::PrintGenre()
{
	cout << "가수 : " << singer << ",  제목: " << song << endl;
}

void Music::Printsinger()
{
	cout << "제목 : " << song << endl;
}

void Music::Printsong()
{
	cout << "장르 : " << genre << ",  가수 : " << singer << endl;
	cout << "가사" << endl << lyrics << endl;
}

void Music::PrintLyrics()
{
	cout << "장르 : " << genre << ",  가수 : " << singer << ",  제목 : " << song << endl;
}

void Music::Printtotal()
{
	cout << "장르 : " << genre << ",  가수 : " << singer << ",  제목 : " << song << endl;
}

string  Music::getgenre()
{
	 return  genre; 
}

string  Music::getsinger()
{
	return singer;
}

string  Music::getsong()
{
	return song;
}

string  Music::getlyrics()
{
	return lyrics;
}
