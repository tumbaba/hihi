#include "stdafx.h"
#include "MusicInfo.h"
#include "util.h"
using namespace std;

int main()
{
	vector<MusicInfo> myMusicnInfo;

	Util myutil;
	myutil.LoadMusicData("MusicBaseData.csv", myMusicnInfo);

	for (int i = 0; i < myMusicnInfo.size(); i++)
	{
		myMusicnInfo[i].Display();
		//cout << myMusicnInfo[i].DisplayO) << endl;
	}
	
	return 0;
}