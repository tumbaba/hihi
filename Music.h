#pragma once
#include "stdafx.h"
#include "UI.h"

class Music
{private:
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
	Music( string g, string si, string so, string l,int a,int b, int c)
		: genre(g), singer(si),song(so), lyrics(l), searchgenre(0), searchsinger(0), searchsong(0) {}
	~Music() {}
	void init(string g, string si,string so, string l);
	void SearchGenre();
	void SearchGenre_Sing_Song() {}  // 순수함수
	void SearchSinger();
	void SearchSong();
	void PrintGenre();
	void Printsong();
	void PrintLyrics();


	string getgenre() { return genre; }
	string getsinger() { return singer; }
	string getlyrics() { return lyrics; }

	void setgenre(string sgenre) { genre =sgenre; }
	void setsinger(string ssinger) { genre = ssinger; }
	void setlyrics(string slyrics) { genre = slyrics; }
};

