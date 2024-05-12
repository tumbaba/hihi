#pragma once

#include "stdafx.h"
#include "UI.h"

class Music
{
private:
	string genre;
	string singer;
	string song;
	string lyrics;
public:
	int searchgenre;
	int searchsinger;
	int searchsong;
	

public:
	Music() {}
	Music(string g, string si, string so, string l, int a, int b, int c)
		: genre(g), singer(si), song(so), lyrics(l), searchgenre(0), searchsinger(0), searchsong(0) {}
	~Music() {}
	void init(string g, string si, string so, string l);
	void PrintGenre();
	void Printsinger();
	void Printsong();
	void PrintLyrics();
	void Printtotal();


	string getgenre() { return genre; }
	string getsinger() { return singer; }
	string getsong() { return song; }
	string getlyrics() { return lyrics; }

	void setgenre(string sgenre) { genre = sgenre; }
	void setsinger(string ssinger) { singer = ssinger; }
	void setsong(string ssong) { song = ssong; }
	void setlyrics(string slyrics) { lyrics = slyrics; }
};

