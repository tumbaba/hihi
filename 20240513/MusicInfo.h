#pragma once
#include "stdafx.h"

enum Element {
	TITLE,
	GENRE,
	SINGER,
};

class MusicInfo
{public:
	string title;
	string singer;
	string genre;
	string releaseDate;
	string playing;

public:
	
	MusicInfo() :title("unknown"), genre("x"), singer("unknown"), playing("no data") {}
	~MusicInfo() {};

	

	string getTitle();
	string getSinger();
	string getGenre();
	string getReleaseData();
	string getPlaying();

	//void Play();
	void Display();
};






