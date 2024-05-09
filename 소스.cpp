#include "stdafx.h"
#include "UI.h"
#include "Music.h"
int main()
{
	//초기화
	UI Ui;
	Music fmusic;
	Music* music = new Music [100];
	
	music[0].init("발라드", "아이유", "내손을 잡아", "");
	music[1].init("발라드", "아이유", "봄 사랑 벚꽃 말고", "");
	music[2].init("발라드", "아이유", "금요일에 만나요", "");
	music[3].init("발라드", "아이유", "너의 의미", "");
	music[4].init("발라드", "아이유", "", "");
	music[5].init("발라드", "SG워너비", "Time Less", "");
	music[6].init("발라드", "SG워너비", "라라라", "");
	music[7].init("발라드", "SG워너비", "살다가", "");
	music[8].init("발라드", "SG워너비", "내게 오는길", "");
	
	

	
	


	int SelectMain=0;
	int SelectTitle = 0;
	//로직
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
					cout << "발라드" << endl;
						music[i].PrintGenre();
				}
				
				break;
			case hiphop:
				for (int i = 0; i < 10; i++)

				{
					music[i].PrintGenre();
				}
				break;
			case 트로트:
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