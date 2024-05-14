#include "stdafx.h"
#include "MusicInfo.h"
#include "Util.h"

int main() {

	vector<MusicInfo> myMusicInfo;

	Util myutil;

	int num2 = 10;
	int& num = num2;
	//vector<MusicInfo>& musicinfos = myMusicInfo;

	myutil.LoadMusicData("MusicBaseData.csv", myMusicInfo);

	//벡터에 참조로 접근하는 방법
	//vector<Musicinfo>& musicinfos = myMusicInfo;

	MusicInfo* pmusicInfo = myMusicInfo.data();


	//for (int i = 1 ; i<66 ; i++){
	//(pmusicInfo + i)->Display();
	//}

	//예시2
	// 포인터로 접근해서 해당된 배열값 수정할 시
	//벡터에 포인트 변수로 접근방법
	/*vector<int> myInt(6);

	int* pInt = myInt.data();
	*(pInt + 0) = 100; *///myInt[0] =100;


	//const int i = 100;

	//const int* pInt = myInt.data();

	//int* ptr = const_cast<int*>(pInt);

	//*(ptr + 4) = 30;

	//for (int i = 0; i < myMusicInfo.size(); i++)
	//{
	//	cout << myMusicInfo[i].getTitle() << endl;
	//}



	return 0;
}