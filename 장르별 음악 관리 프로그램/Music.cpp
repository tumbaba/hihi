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
	cout << "���� : " << singer << ",  ����: " << song << endl;
}

void Music::Printsinger()
{
	cout << "���� : " << song << endl;
}

void Music::Printsong()
{
	cout << "�帣 : " << genre << ",  ���� : " << singer << endl;
	cout << "����" << endl << lyrics << endl;
}

void Music::PrintLyrics()
{
	cout << "�帣 : " << genre << ",  ���� : " << singer << ",  ���� : " << song << endl;
}

void Music::Printtotal()
{
	cout << "�帣 : " << genre << ",  ���� : " << singer << ",  ���� : " << song << endl;
}
