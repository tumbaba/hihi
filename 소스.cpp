#include "stdafx.h"
#include "UI.h"
#include "Music.h"
int main()
{
	//�ʱ�ȭ
	UI Ui;
	Music fmusic;
	Music* music = new Music [100];
	
	music[0].init("�߶��", "������", "������ ���", "");
	music[1].init("�߶��", "������", "�� ��� ���� ����", "");
	music[2].init("�߶��", "������", "�ݿ��Ͽ� ������", "");
	music[3].init("�߶��", "������", "���� �ǹ�", "");
	music[4].init("�߶��", "������", "", "");
	music[5].init("�߶��", "SG���ʺ�", "Time Less", "");
	music[6].init("�߶��", "SG���ʺ�", "����", "");
	music[7].init("�߶��", "SG���ʺ�", "��ٰ�", "");
	music[8].init("�߶��", "SG���ʺ�", "���� ���±�", "");
	
	

	
	


	int SelectMain=0;
	int SelectTitle = 0;
	//����
	cin >> SelectTitle;
	while (true)
	{
		system("cls");
		switch (SelectTitle)
		{
		case 0:

		
		Ui.UIMain();
		
		// cin >> SelectMain;
		
		switch (SelectMain)
		{
		case M_genr:
			Ui.UISearchGenre();
			cin >> fmusic.searchgenre;
			system("cls");
			switch (fmusic.searchgenre)
			{
			case ballad:
				for (int i = 0; i < 10; i++)
				
				{
					cout << "�߶��" << endl;
						music[i].PrintGenre();
				}
				
				break;
			case hiphop:
				for (int i = 0; i < 10; i++)

				{
					music[i].PrintGenre();
				}
				break;
			case Ʈ��Ʈ:
				for (int i = 0; i < 10; i++)

				{
					music[i].PrintGenre();
				}
				break;
			case dance:
				for (int i = 0; i < 10; i++)

				{
					music[i].PrintGenre();
				}
				break;

			default:
				break;
			}

			break;
		case M_singer:
			Ui.UISearchSinger();
			cin >> fmusic.searchsinger;
			switch (fmusic.searchsinger)
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

			break;
		case M_titel:
			Ui.UISearchsong();
			cin >> fmusic.searchsong;
			switch (fmusic.searchsong)
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
			break;

		case M_totallist:

			for (int i = 0; i < 100; i++)
			{
				music[i].Printsong();
			}

			break;




		default:
			break;
		}

default:
	break;
}






		



}









	return 0;
}