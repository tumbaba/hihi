#include <algorithm>
#include "stdafx.h"
#include "UI.h"
#include "Music.h"
#include "Util.h"


int main()
{
	//초기화
	UI Ui;
	vector<Music> music;
	Util util;

	
	
	util.LoadMusicData("MusicData1.txt", music);

	map<int,Music> musicmap;


	for ( auto& mu : music)
	{
		musicmap.insert(make_pair(mu.getsong(),mu))
	}

	
	
	/*transform(music.begin(), music, end(), inserter(musicmap, musicmap.begin()),
		[](const Music& music1) {return make_pair(music1.song, music1); });*/
	
	

	/*Music*** music;


	music = new Music * *[4];

	for (int i = 0; i < 4; ++i) {
		music[i] = new Music * [12];

		for (int j = 0; j < 12; ++j) {
			music[i][j] = new Music[9];
		}
	}



	music[0][0][0].init("발라드", "아이유", "내손을 잡아", "1");
	music[0][0][1].init("발라드", "아이유", "봄 사랑 벚꽃 말고", "1");
	music[0][0][2].init("발라드", "아이유", "금요일에 만나요", "1");
	music[0][0][3].init("발라드", "아이유", "너의 의미", "1");
	music[0][1][0].init("발라드", "SG 워너비", "timeless", "1");
	music[0][1][1].init("발라드", "SG 워너비", "라라라", "1");
	music[0][1][2].init("발라드", "SG 워너비", "살다가", "1");
	music[0][1][3].init("발라드", "SG 워너비", "죄와벌", "1");
	music[0][2][0].init("발라드", "성시경", "희재", "1");
	music[0][2][1].init("발라드", "성시경", "거리에서", "1");
	music[0][2][2].init("발라드", "성시경", "내게 오는 길", "1");
	music[0][2][3].init("발라드", "성시경", "너의 모든순간", "1");
	music[0][3][0].init("발라드", "규현", "광화문에서", "1");
	music[0][4][0].init("발라드", "씨야", "사랑의 인사", "1");
	music[0][5][0].init("발라드", "하동균", "그녀를 사랑해줘요", "1");
	music[0][6][0].init("발라드", "정은지", "All For You", "1");
	music[0][7][0].init("발라드", "린", "사랑했잖아", "1");
	music[0][8][0].init("발라드", "윤하", "기다리다", "1");
	music[0][9][0].init("발라드", "이적", "걱정말아요 그대", "1");
	music[0][10][0].init("발라드", "김동률", "다시 사랑한다 말할까", "1");
	music[0][11][0].init("발라드", "오혁", "소녀", "1");


	music[1][0][0].init("트로트", "장윤정", "초혼", "1");
	music[1][0][1].init("트로트", "장윤정", "사랑아", "1");
	music[1][0][2].init("트로트", "장윤정", "꽃", "1");
	music[1][0][3].init("트로트", "장윤정", "짠자라", "1");
	music[1][0][4].init("트로트", "장윤정", "불나비", "1");
	music[1][0][5].init("트로트", "장윤정", "첫사랑", "1");
	music[1][0][6].init("트로트", "장윤정", "어부바", "1");
	music[1][0][7].init("트로트", "장윤정", "올래", "1");
	music[1][0][8].init("트로트", "장윤정", "트위스트", "1");
	music[1][1][0].init("트로트", "진성", "안동역에서", "1");
	music[1][1][1].init("트로트", "진성", "보릿고게", "1");
	music[1][1][2].init("트로트", "진성", "태클을 걸지마", "1");
	music[1][2][0].init("트로트", "조용필", "바람의 노래", "1");
	music[1][2][1].init("트로트", "조용필", "단발머리", "1");
	music[1][3][0].init("트로트", "장민호", "남자는 말합니다", "1");
	music[1][4][0].init("트로트", "윤수현", "천태만상", "1");
	music[1][5][0].init("트로트", "진미령", "미운 사랑", "1");
	music[1][6][0].init("트로트", "신유", "시계바늘", "1");
	music[1][7][0].init("트로트", "조항조", "거짓말", "1");
	music[1][7][1].init("트로트", "조항조", "남자라는 이유로", "1");
	music[1][8][0].init("트로트", "심수봉", "백만송이 장미 ", "1");
	music[1][9][0].init("트로트", "서경주", "당돌한 여자", "1");

	music[2][0][0].init("힙합", "프리스타일", "Y", "1");
	music[2][0][1].init("힙합", "프리스타일", "수취인 불명", "1");
	music[2][1][0].init("힙합", "싸이", "어땠을까", "1");
	music[2][1][1].init("힙합", "싸이", "뜨거운 안녕", "1");
	music[2][1][2].init("힙합", "싸이", "예술이야", "1");
	music[2][1][3].init("힙합", "싸이", "강남스타일", "1");
	music[2][2][0].init("힙합", "리쌍", "헤어지지 못하는 여자, 떠나기지 못하는 남자", "1");
	music[2][2][1].init("힙합", "리쌍", "발레리노", "1");
	music[2][2][2].init("힙합", "리쌍", "광대", "1");
	music[2][2][3].init("힙합", "리쌍", "눈물", "1");
	music[2][3][0].init("힙합", "산이", "한여름밤의 꿀", "1");
	music[2][4][0].init("힙합", "프라이머리", "자니", "1");
	music[2][4][1].init("힙합", "프라이머리", "물음표", "1");
	music[2][4][2].init("힙합", "프라이머리", "씨스루", "1");
	music[2][5][0].init("힙합", "엠씨몽", "I Love U Oh Thank U", "1");
	music[2][5][1].init("힙합", "엠씨몽", "죽을만큼 아파서", "1");
	music[2][5][2].init("힙합", "엠씨몽", "내 생애 가장 행복한 시간", "1");
	music[2][6][0].init("힙합", "다이나믹듀오", "죽일놈", "1");
	music[2][6][1].init("힙합", "다이나믹듀오", "고백", "1");

	music[3][0][0].init("댄스", "거북이", "비행기", "1");
	music[3][0][1].init("댄스", "거북이", "빙고", "1");
	music[3][1][0].init("댄스", "아이유", "미리 메리 크리스마스", "1");
	music[3][1][1].init("댄스", "아이유", "좋은날", "1");
	music[3][1][2].init("댄스", "아이유", "너랑나", "1");
	music[3][1][3].init("댄스", "아이유", "스물셋", "1");
	music[3][1][4].init("댄스", "아이유", "하루 끝", "1");
	music[3][1][5].init("댄스", "아이유", "분홍신", "1");
	music[3][2][0].init("댄스", "2NE1", "I Don't Care", "1");
	music[3][2][1].init("댄스", "2NE1", "Go Away", "1");
	music[3][3][0].init("댄스", "빅뱅", "붉은 노을", "1");
	music[3][3][1].init("댄스", "빅뱅", "FANTASTIC BABY", "1");
	music[3][3][2].init("댄스", "빅뱅", "거짓말", "1");
	music[3][4][0].init("댄스", "여자친구", "오늘부터 우리는", "1");
	music[3][5][0].init("댄스", "코요태", "순정", "1");
	music[3][5][1].init("댄스", "코요태", "실연", "1");
	music[3][6][0].init("댄스", "씨스타", "러빙유", "1");
	music[3][6][1].init("댄스", "씨스타", "SHAKE IT", "1");*/










	string intputsinger;
	string inputChar;
	int searchgenre;
	int searchsinger;
	int searchsong;

	int SelectTitle;
	int SelectMain;
	//로직

	while (true)
	{
		Ui.UITitle();
		cin >> SelectTitle;
		system("cls");
		switch (SelectTitle)
		{
		case 0:


			Ui.UIMain();

			cin >> SelectMain;
			system("cls");
			switch (SelectMain)
			{
			case M_genr:
				Ui.UISearchGenre();
				cin >> searchgenre;
				system("cls");
				switch (searchgenre)
				{
				case ballad:

					cout << "발라드" << endl;

					for (auto& m : music)
					{
						if (m.getgenre() == "발라드")
						{
							m.PrintGenre();
						}

					}

					/*for (int i = 0; i < 12; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if (music[0][i][j].getgenre() != "")
							{
								music[0][i][j].PrintGenre();
							}
						}
					}*/
					break;

				case hiphop:
					cout << "힙합" << endl;
					for (auto& m : music)
					{
						if (m.getgenre() == "힙합")
						{
							m.PrintGenre();
						}

					}
					/*for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							if (music[1][i][j].getgenre() != "")
							{
								music[1][i][j].PrintGenre();
							}
						}
					}*/
					break;
				case 트로트:
					cout << "트로트" << endl;
					for (auto& m : music)
					{
						if (m.getgenre() == "트로트")
						{
							m.PrintGenre();
						}

					}
					//for (int i = 0; i < 7; i++)
					///*{
					//	for (int j = 0; j < 4; j++)
					//	{
					//		if (music[2][i][j].getgenre() != "")
					//		{
					//			music[2][i][j].PrintGenre();
					//		}
					//	}
					//}*/
					break;
				case dance:
					cout << "댄스" << endl;
					for (auto& m : music)
					{
						if (m.getgenre() == "댄스")
						{
							m.PrintGenre();
						}

					}
					/*for (int i = 0; i < 7; i++)
					{
						for (int j = 0; j < 6; j++)
						{
							if (music[3][i][j].getgenre() != "")
							{
								music[3][i][j].PrintGenre();
							}
						}
					}*/
					break;

				default:
					break;
				}

				break;
			case M_singer:
				Ui.UISearchSinger();
				//cin >> fmusic.searchsinger;

				cin >> intputsinger;
				system("cls");

				for (auto& m : music)
				{
					if (m.getsinger() == intputsinger)
					{
						m.Printsinger();
					}

				}

				/*for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 12; j++)
					{
						for (int k = 0; k < 9; k++)
						{
							if (intputsinger == music[i][j][k].getsinger())
							{
								music[i][j][k].Printsinger();
							}

						}
					}
				}*/


				/*switch (fmusic.searchsinger)
				{
				case 0:
					cout << "0.아이유" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 4; i++)
					{
						music[0][0][i].Printsinger();
					}
					cout << "댄스" << endl;
					for (int i = 0; i < 6; i++)
					{
						music[3][1][i].Printsinger();
					}
					break;
				case 1:
					cout << "1.SG 워너비" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 4; i++)
					{
						music[0][1][i].Printsinger();
					}
					break;
				case 2:
					cout << "2.성시경" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 4; i++)
					{
						music[0][2][i].Printsinger();
					}
					break;
				case 3:
					cout << "3.규현" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][3][i].Printsinger();
					}
					break;
				case 4:
					cout << "4.씨야" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][4][i].Printsinger();
					}
					break;
				case 5:
					cout << "5. 하동균" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][5][i].Printsinger();
					}
					break;
				case 6:
					cout << "6. 정은지" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][6][i].Printsinger();
					}
					break;
				case 7:
					cout << "7. 린" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][7][i].Printsinger();
					}
					break;
				case 8:
					cout << "8.윤하" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][8][i].Printsinger();
					}
					break;
				case 9:
					cout << "9. 이적" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][9][i].Printsinger();
					}
					break;
				case 10:
					cout << "10. 김동률" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][10][i].Printsinger();
					}
					break;
				case 11:
					cout << "11. 오혁" << endl;
					cout << "발라드" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][11][i].Printsinger();
					}
					break;

				case 13:
					cout << "13. 장윤정" << endl;
					cout << "트로트" << endl;
					for (int i = 0; i < 9; i++)
					{
						music[1][0][i].Printsinger();
					}
					break;
				case 14:
					cout << "14. 진성" << endl;
					cout << "트로트" << endl;
					for (int i = 0; i < 3; i++)
					{
						music[1][1][i].Printsinger();
					}
					break;
				case 15:
					cout << "15. 조용필" << endl;
					cout << "트로트" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[1][2][i].Printsinger();
					}
					break;
				case 16:
					cout << "16. 장민호" << endl;
					cout << "트로트" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][3][i].Printsinger();
					}
					break;
				case 17:
					cout << "17. 윤수현" << endl;
					cout << "트로트" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][4][i].Printsinger();
					}
					break;
				case 18:
					cout << "18. 진미령" << endl;
					cout << "트로트" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][5][i].Printsinger();
					}
					break;
				case 19:
					cout << "19. 신유" << endl;
					cout << "트로트" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][6][i].Printsinger();
					}
					break;
				case 20:
					cout << "20. 조항조" << endl;
					cout << "트로트" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[1][7][i].Printsinger();
					}
					break;
				case 21:
					cout << "21. 심수봉" << endl;
					cout << "트로트" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][8][i].Printsinger();
					}
					break;
				case 22:
					cout << "22. 서경주" << endl;
					cout << "트로트" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][9][i].Printsinger();
					}
					break;
				case 23:
					cout << "23. 프리스타일" << endl;
					cout << "힙합" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[2][0][i].Printsinger();
					}
					break;
				case 24:
					cout << "24. 싸이" << endl;
					cout << "힙합" << endl;
					for (int i = 0; i < 4; i++)
					{
						music[2][1][i].Printsinger();
					}
					break;
				case 25:
					cout << "25. 리쌍" << endl;
					cout << "힙합" << endl;
					for (int i = 0; i < 4; i++)
					{
						music[2][2][i].Printsinger();
					}
					break;
				case 26:
					cout << "26. 산이" << endl;
					cout << "힙합" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[2][3][i].Printsinger();
					}
					break;
				case 27:
					cout << "27. 프라이머리" << endl;
					cout << "힙합" << endl;
					for (int i = 0; i < 3; i++)
					{
						music[2][4][i].Printsinger();
					}
					break;
				case 28:
					cout << "28. 엠씨몽" << endl;
					cout << "힙합" << endl;
					for (int i = 0; i < 3; i++)
					{
						music[2][5][i].Printsinger();
					}
					break;
				case 29:
					cout << "29. 다이나믹듀오" << endl;
					cout << "힙합" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[2][6][i].Printsinger();
					}
					break;
				case 30:
					cout << "30. 거북이" << endl;
					cout << "댄스" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[3][0][i].Printsinger();
					}
					break;
				case 31:
					cout << "31. 2NE1" << endl;
					cout << "댄스" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[3][2][i].Printsinger();
					}
					break;
				case 32:
					cout << "32. 빅뱅" << endl;
					cout << "댄스" << endl;
					for (int i = 0; i < 3; i++)
					{
						music[3][3][i].Printsinger();
					}
					break;
				case 33:
					cout << "33. 여자친구" << endl;
					cout << "댄스" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[3][4][i].Printsinger();
					}
					break;
				case 34:
					cout << "34. 코요태" << endl;
					cout << "댄스" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[3][5][i].Printsinger();
					}
					break;
				case 35:
					cout << "35. 씨스타" << endl;
					cout << "댄스" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[3][6][i].Printsinger();
					}
					break;



				default:
					break;
				}*/

				break;
			case M_titel:
				Ui.UISearchsong();

				cin >> inputChar;

				for (auto& m : music)
				{
					if (m.getsong() == inputChar)
					{
						m.Printsong();
					}

				}
				/*for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 12; j++)
					{
						for (int k = 0; k < 9; k++)
						{
							if (inputChar == music[i][j][k].getsong())
							{
								music[i][j][k].Printsong();
							}

						}
					}
				}*/


				break;

			case M_totallist:

				cout << "전체 노래목록" << endl;
				for (auto& m : music)
				{

					m.Printsong();

				}
				//for (int i = 0; i < 4; i++)
				//{
				//	for (int j = 0; j < 12; j++)
				//	{
				//		for (int k = 0; k < 9; k++)
				//		{
				//			if (music[i][j][k].getgenre() != "")
				//			{
				//				music[i][j][k].Printtotal();
				//			}


				//		}
				//	}
				//}



				break;




			default:
				break;
			}

		default:
			//break;
		}










	}









	return 0;
}