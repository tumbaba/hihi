#include "Util.h"

void Util::LoadMusicData(string filename, vector<Music>& musiclist)
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
		musiclist.push_back(Music(genre, singer, song, lyrics));

	}

	file.close();
	}
	
}

