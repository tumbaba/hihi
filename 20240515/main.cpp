#include <algorithm>
#include "stdafx.h"
#include "UI.h"
#include "Music.h"
#include "Util.h"


int main()
{
	//�ʱ�ȭ
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



	music[0][0][0].init("�߶��", "������", "������ ���", "1");
	music[0][0][1].init("�߶��", "������", "�� ��� ���� ����", "1");
	music[0][0][2].init("�߶��", "������", "�ݿ��Ͽ� ������", "1");
	music[0][0][3].init("�߶��", "������", "���� �ǹ�", "1");
	music[0][1][0].init("�߶��", "SG ���ʺ�", "timeless", "1");
	music[0][1][1].init("�߶��", "SG ���ʺ�", "����", "1");
	music[0][1][2].init("�߶��", "SG ���ʺ�", "��ٰ�", "1");
	music[0][1][3].init("�߶��", "SG ���ʺ�", "�˿͹�", "1");
	music[0][2][0].init("�߶��", "���ð�", "����", "1");
	music[0][2][1].init("�߶��", "���ð�", "�Ÿ�����", "1");
	music[0][2][2].init("�߶��", "���ð�", "���� ���� ��", "1");
	music[0][2][3].init("�߶��", "���ð�", "���� ������", "1");
	music[0][3][0].init("�߶��", "����", "��ȭ������", "1");
	music[0][4][0].init("�߶��", "����", "����� �λ�", "1");
	music[0][5][0].init("�߶��", "�ϵ���", "�׳ฦ ��������", "1");
	music[0][6][0].init("�߶��", "������", "All For You", "1");
	music[0][7][0].init("�߶��", "��", "������ݾ�", "1");
	music[0][8][0].init("�߶��", "����", "��ٸ���", "1");
	music[0][9][0].init("�߶��", "����", "�������ƿ� �״�", "1");
	music[0][10][0].init("�߶��", "�赿��", "�ٽ� ����Ѵ� ���ұ�", "1");
	music[0][11][0].init("�߶��", "����", "�ҳ�", "1");


	music[1][0][0].init("Ʈ��Ʈ", "������", "��ȥ", "1");
	music[1][0][1].init("Ʈ��Ʈ", "������", "�����", "1");
	music[1][0][2].init("Ʈ��Ʈ", "������", "��", "1");
	music[1][0][3].init("Ʈ��Ʈ", "������", "§�ڶ�", "1");
	music[1][0][4].init("Ʈ��Ʈ", "������", "�ҳ���", "1");
	music[1][0][5].init("Ʈ��Ʈ", "������", "ù���", "1");
	music[1][0][6].init("Ʈ��Ʈ", "������", "��ι�", "1");
	music[1][0][7].init("Ʈ��Ʈ", "������", "�÷�", "1");
	music[1][0][8].init("Ʈ��Ʈ", "������", "Ʈ����Ʈ", "1");
	music[1][1][0].init("Ʈ��Ʈ", "����", "�ȵ�������", "1");
	music[1][1][1].init("Ʈ��Ʈ", "����", "�������", "1");
	music[1][1][2].init("Ʈ��Ʈ", "����", "��Ŭ�� ������", "1");
	music[1][2][0].init("Ʈ��Ʈ", "������", "�ٶ��� �뷡", "1");
	music[1][2][1].init("Ʈ��Ʈ", "������", "�ܹ߸Ӹ�", "1");
	music[1][3][0].init("Ʈ��Ʈ", "���ȣ", "���ڴ� ���մϴ�", "1");
	music[1][4][0].init("Ʈ��Ʈ", "������", "õ�¸���", "1");
	music[1][5][0].init("Ʈ��Ʈ", "���̷�", "�̿� ���", "1");
	music[1][6][0].init("Ʈ��Ʈ", "����", "�ð�ٴ�", "1");
	music[1][7][0].init("Ʈ��Ʈ", "������", "������", "1");
	music[1][7][1].init("Ʈ��Ʈ", "������", "���ڶ�� ������", "1");
	music[1][8][0].init("Ʈ��Ʈ", "�ɼ���", "�鸸���� ��� ", "1");
	music[1][9][0].init("Ʈ��Ʈ", "������", "�絹�� ����", "1");

	music[2][0][0].init("����", "������Ÿ��", "Y", "1");
	music[2][0][1].init("����", "������Ÿ��", "������ �Ҹ�", "1");
	music[2][1][0].init("����", "����", "�����", "1");
	music[2][1][1].init("����", "����", "�߰ſ� �ȳ�", "1");
	music[2][1][2].init("����", "����", "�����̾�", "1");
	music[2][1][3].init("����", "����", "������Ÿ��", "1");
	music[2][2][0].init("����", "����", "������� ���ϴ� ����, �������� ���ϴ� ����", "1");
	music[2][2][1].init("����", "����", "�߷�����", "1");
	music[2][2][2].init("����", "����", "����", "1");
	music[2][2][3].init("����", "����", "����", "1");
	music[2][3][0].init("����", "����", "�ѿ������� ��", "1");
	music[2][4][0].init("����", "�����̸Ӹ�", "�ڴ�", "1");
	music[2][4][1].init("����", "�����̸Ӹ�", "����ǥ", "1");
	music[2][4][2].init("����", "�����̸Ӹ�", "������", "1");
	music[2][5][0].init("����", "������", "I Love U Oh Thank U", "1");
	music[2][5][1].init("����", "������", "������ŭ ���ļ�", "1");
	music[2][5][2].init("����", "������", "�� ���� ���� �ູ�� �ð�", "1");
	music[2][6][0].init("����", "���̳��͵��", "���ϳ�", "1");
	music[2][6][1].init("����", "���̳��͵��", "���", "1");

	music[3][0][0].init("��", "�ź���", "�����", "1");
	music[3][0][1].init("��", "�ź���", "����", "1");
	music[3][1][0].init("��", "������", "�̸� �޸� ũ��������", "1");
	music[3][1][1].init("��", "������", "������", "1");
	music[3][1][2].init("��", "������", "�ʶ���", "1");
	music[3][1][3].init("��", "������", "������", "1");
	music[3][1][4].init("��", "������", "�Ϸ� ��", "1");
	music[3][1][5].init("��", "������", "��ȫ��", "1");
	music[3][2][0].init("��", "2NE1", "I Don't Care", "1");
	music[3][2][1].init("��", "2NE1", "Go Away", "1");
	music[3][3][0].init("��", "���", "���� ����", "1");
	music[3][3][1].init("��", "���", "FANTASTIC BABY", "1");
	music[3][3][2].init("��", "���", "������", "1");
	music[3][4][0].init("��", "����ģ��", "���ú��� �츮��", "1");
	music[3][5][0].init("��", "�ڿ���", "����", "1");
	music[3][5][1].init("��", "�ڿ���", "�ǿ�", "1");
	music[3][6][0].init("��", "����Ÿ", "������", "1");
	music[3][6][1].init("��", "����Ÿ", "SHAKE IT", "1");*/










	string intputsinger;
	string inputChar;
	int searchgenre;
	int searchsinger;
	int searchsong;

	int SelectTitle;
	int SelectMain;
	//����

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

					cout << "�߶��" << endl;

					for (auto& m : music)
					{
						if (m.getgenre() == "�߶��")
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
					cout << "����" << endl;
					for (auto& m : music)
					{
						if (m.getgenre() == "����")
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
				case Ʈ��Ʈ:
					cout << "Ʈ��Ʈ" << endl;
					for (auto& m : music)
					{
						if (m.getgenre() == "Ʈ��Ʈ")
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
					cout << "��" << endl;
					for (auto& m : music)
					{
						if (m.getgenre() == "��")
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
					cout << "0.������" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 4; i++)
					{
						music[0][0][i].Printsinger();
					}
					cout << "��" << endl;
					for (int i = 0; i < 6; i++)
					{
						music[3][1][i].Printsinger();
					}
					break;
				case 1:
					cout << "1.SG ���ʺ�" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 4; i++)
					{
						music[0][1][i].Printsinger();
					}
					break;
				case 2:
					cout << "2.���ð�" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 4; i++)
					{
						music[0][2][i].Printsinger();
					}
					break;
				case 3:
					cout << "3.����" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][3][i].Printsinger();
					}
					break;
				case 4:
					cout << "4.����" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][4][i].Printsinger();
					}
					break;
				case 5:
					cout << "5. �ϵ���" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][5][i].Printsinger();
					}
					break;
				case 6:
					cout << "6. ������" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][6][i].Printsinger();
					}
					break;
				case 7:
					cout << "7. ��" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][7][i].Printsinger();
					}
					break;
				case 8:
					cout << "8.����" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][8][i].Printsinger();
					}
					break;
				case 9:
					cout << "9. ����" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][9][i].Printsinger();
					}
					break;
				case 10:
					cout << "10. �赿��" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][10][i].Printsinger();
					}
					break;
				case 11:
					cout << "11. ����" << endl;
					cout << "�߶��" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[0][11][i].Printsinger();
					}
					break;

				case 13:
					cout << "13. ������" << endl;
					cout << "Ʈ��Ʈ" << endl;
					for (int i = 0; i < 9; i++)
					{
						music[1][0][i].Printsinger();
					}
					break;
				case 14:
					cout << "14. ����" << endl;
					cout << "Ʈ��Ʈ" << endl;
					for (int i = 0; i < 3; i++)
					{
						music[1][1][i].Printsinger();
					}
					break;
				case 15:
					cout << "15. ������" << endl;
					cout << "Ʈ��Ʈ" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[1][2][i].Printsinger();
					}
					break;
				case 16:
					cout << "16. ���ȣ" << endl;
					cout << "Ʈ��Ʈ" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][3][i].Printsinger();
					}
					break;
				case 17:
					cout << "17. ������" << endl;
					cout << "Ʈ��Ʈ" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][4][i].Printsinger();
					}
					break;
				case 18:
					cout << "18. ���̷�" << endl;
					cout << "Ʈ��Ʈ" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][5][i].Printsinger();
					}
					break;
				case 19:
					cout << "19. ����" << endl;
					cout << "Ʈ��Ʈ" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][6][i].Printsinger();
					}
					break;
				case 20:
					cout << "20. ������" << endl;
					cout << "Ʈ��Ʈ" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[1][7][i].Printsinger();
					}
					break;
				case 21:
					cout << "21. �ɼ���" << endl;
					cout << "Ʈ��Ʈ" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][8][i].Printsinger();
					}
					break;
				case 22:
					cout << "22. ������" << endl;
					cout << "Ʈ��Ʈ" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[1][9][i].Printsinger();
					}
					break;
				case 23:
					cout << "23. ������Ÿ��" << endl;
					cout << "����" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[2][0][i].Printsinger();
					}
					break;
				case 24:
					cout << "24. ����" << endl;
					cout << "����" << endl;
					for (int i = 0; i < 4; i++)
					{
						music[2][1][i].Printsinger();
					}
					break;
				case 25:
					cout << "25. ����" << endl;
					cout << "����" << endl;
					for (int i = 0; i < 4; i++)
					{
						music[2][2][i].Printsinger();
					}
					break;
				case 26:
					cout << "26. ����" << endl;
					cout << "����" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[2][3][i].Printsinger();
					}
					break;
				case 27:
					cout << "27. �����̸Ӹ�" << endl;
					cout << "����" << endl;
					for (int i = 0; i < 3; i++)
					{
						music[2][4][i].Printsinger();
					}
					break;
				case 28:
					cout << "28. ������" << endl;
					cout << "����" << endl;
					for (int i = 0; i < 3; i++)
					{
						music[2][5][i].Printsinger();
					}
					break;
				case 29:
					cout << "29. ���̳��͵��" << endl;
					cout << "����" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[2][6][i].Printsinger();
					}
					break;
				case 30:
					cout << "30. �ź���" << endl;
					cout << "��" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[3][0][i].Printsinger();
					}
					break;
				case 31:
					cout << "31. 2NE1" << endl;
					cout << "��" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[3][2][i].Printsinger();
					}
					break;
				case 32:
					cout << "32. ���" << endl;
					cout << "��" << endl;
					for (int i = 0; i < 3; i++)
					{
						music[3][3][i].Printsinger();
					}
					break;
				case 33:
					cout << "33. ����ģ��" << endl;
					cout << "��" << endl;
					for (int i = 0; i < 1; i++)
					{
						music[3][4][i].Printsinger();
					}
					break;
				case 34:
					cout << "34. �ڿ���" << endl;
					cout << "��" << endl;
					for (int i = 0; i < 2; i++)
					{
						music[3][5][i].Printsinger();
					}
					break;
				case 35:
					cout << "35. ����Ÿ" << endl;
					cout << "��" << endl;
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

				cout << "��ü �뷡���" << endl;
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