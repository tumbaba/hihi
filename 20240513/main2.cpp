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

	//���Ϳ� ������ �����ϴ� ���
	//vector<Musicinfo>& musicinfos = myMusicInfo;

	MusicInfo* pmusicInfo = myMusicInfo.data();


	//for (int i = 1 ; i<66 ; i++){
	//(pmusicInfo + i)->Display();
	//}

	//����2
	// �����ͷ� �����ؼ� �ش�� �迭�� ������ ��
	//���Ϳ� ����Ʈ ������ ���ٹ��
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