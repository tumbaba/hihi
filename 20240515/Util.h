
#pragma once
//#include "stdafx.h"
#include "Music.h"
class Util
{
public:
	void LoadMusicData(string filename, vector<Music>& musiclist)
	{
		ifstream file(filename);

		if (file.is_open())
		{


			string line;
			getline(file, line);
			while (getline(file, line))
			{
				istringstream ss(line);
				string genre, singer, song, lyrics;
				getline(ss, genre, ',');
				getline(ss, singer, ',');
				getline(ss, song, ',');
				getline(ss, lyrics, ',');

				Music  mu;
				mu.setgenre(genre);
				mu.setsinger(singer);
				mu.setsong(song);
				mu.setlyrics(lyrics);
				musiclist.push_back(mu);

			}
			
			file.close();
		}

	}
	//void LoadMusicData(string filename, map<Music>& musci)
	
};
