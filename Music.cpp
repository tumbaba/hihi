#include "Music.h"



void Music::init(string g, string si, string so, string l)
{
	genre = g;
	singer = si;
	song = so;
	lyrics = l;
}

void Music::SearchGenre()
{
	
	switch (searchgenre)
	{
	case ballad:
		SearchGenre_Sing_Song();
		break;
	case hiphop:
		SearchGenre_Sing_Song();
		break;
	case 트로트:
		SearchGenre_Sing_Song();
		break;
	case dance:
		SearchGenre_Sing_Song();
		break;

	default:
		break;
	}

}



void Music::SearchSinger()
{
	switch (searchsinger)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
	case 37:
	




	default:
		break;
	}

}

void Music::SearchSong()
{

	switch (searchsong)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:



	default:
		break;
	}

}

void Music::PrintGenre()
{
	cout << "가수 : " << singer << "  제목: " << song << endl;
}

void Music::PrintLyrics()
{
	cout << "장르 : " << genre << "  가수 : " << singer << "  제목 : " << song << endl;
}
