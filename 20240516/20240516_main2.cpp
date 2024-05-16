#include "stdafx.h"
#include "MusicInfo.h"
#include "Util.h"


void SizePrint(vector<MusicInfo> &music)
{
	int nsize = music.size();

	cout << "myMusicInfo.size() =" << nsize << endl;
}

int main()
{

	//vector<MusicInfo> music;
	//Util util;

	//util.LoadMusicData("MusicBaseData", music);
	//map<string, MusicInfo> musicmap;

	vector<MusicInfo> myMusicInfo;
	Util util;
	util.LoadMusicData("MusicBaseData.csv", myMusicInfo);


	//int nsize = myMusicInfo.size();

	//cout << "myMusicInfo.size() =" << nsize << endl;   // 초기사이즈


	SizePrint(myMusicInfo);
	myMusicInfo.clear();

	//nsize = myMusicInfo.size();void SizePrint(vector<MusicInfo> &music)

	/*int nsize = music.size();

	cout << "myMusicInfo.size() =" << nsize << endl;
}*/

//cout << "myMusicInfo.size() =" << nsize << endl;   // 초기사이즈

	SizePrint(myMusicInfo);
	MusicInfo musicinfo;
	myMusicInfo.push_back(musicinfo);

	SizePrint(myMusicInfo);



	for (int i = 0; i < 10; i++)
	{
		myMusicInfo.push_back(musicinfo);
	}
	SizePrint(myMusicInfo);
	//MusicInfo mm[100];
	

	

	//for (int i = 0; 0 < 100; i++)
	//{

	//	myMusicInfo.push_back(mm[i]);
	//}
	//SizePrint(myMusicInfo);

	return 0;
}














