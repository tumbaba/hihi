

#include "com.h"

//cout<<setw(n);;     n��ŭ �������� 
//cout<<setfill("<<''<<"'};;     n��ŭ ��������
//while(getchar() == 'a'))
//extern int a  //�ٴٸ������� ����Ǿ��ٴ� ���� ��Ÿ����





int main()
{
	Scenes scense;

	

	enemy* ene = new enemy[10];

	ene[0].init("A", 10, 5, 1, 10);
	ene[1].init("B", 10, 5, 1, 10);
	ene[2].init("C", 10, 5, 1, 10);
	ene[3].init("D", 10, 5, 1, 10);
	ene[4].init("E", 10, 5, 1, 10);
	ene[5].init("F", 10, 5, 1, 10);
	ene[6].init("G", 10, 5, 1, 10);
	ene[7].init("H", 10, 5, 1, 10);
	ene[8].init("I", 10, 5, 1, 10);
	ene[9].init("BOSS", 10, 5, 1, 10);

	character* ch = new character[3];

	ch[0].init("w", 100, 10, 5, 0, 1);
	ch[1].init("g", 90, 13, 3, 0, 1);
	ch[0].init("m", 70, 17, 1, 0, 1);

	combat* com = new combat[30];

	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 10; k++)
		{
			com[j * 10 + k].init(ch[j], ene[k], 0, 0, 0, 0, 0);
		}
	}

	string name;





	//���� ����


	int screen_select = 0;
	int main_select = 0;
	int charter_select = 0;
	int dungeon_select = 0;



	//�ʱ�ȭ




	



	cin >> screen_select;



	//����
	while (true)
	{
		{


			system("cls");

			switch (screen_select)
			{
			case TITLE_SCENE: //Ÿ��Ʋ ȭ��

				scense.title();
				scense.main1();

				break;
				//tryAgain:
			case MAIN_SDENE: //����ȭ��
				scense.main2();


				cin >> main_select;
				system("cls");

				if (main_select == 1)
				{
					scense.Character_select();
					cin >> charter_select;
					system("cls");
					switch (charter_select)
					{
					case WARRIOR:
						cout << "�̸��� �Է����ּ���" << endl;
						cin >> name; ch[0].setname(name);


						system("cls");
						ch[0].showstate();

						break;
					case GUNNER:

						break;
					case MAGE:

						break;
					default:
						cout << "�߸� �Է� �ϼ̽��ϴ�." << endl;
						break;
					}
					break;
					//goto tryAgain;
				}
				else
				{

					scense.dungeon();
					cin >> dungeon_select;
					system("cls");
					switch (dungeon_select)

					{
					case AAA:


						com[0].AAAAAAAA();




						break;
					case BBB:


						


						break;
					case CCC:

						


						break;
					case DDD:

						


						break;
					case EEE:

						


						break;
					case FFF:

						

						break;
					case GGG:

						


						break;
					case HHH:

						


						break;
					case III:

						


						break;
					case BOSS:

						

						break;
					default:
						cout << "�߸� �Է� �ϼ̽��ϴ�." << endl;
						break;

					}
					break;
					//goto tryAgain;

				}

				break;
				cout << "�߸� �Է� �ϼ̽��ϴ�." << endl;
			default:

				break;
			}
			//cin >> main_select;



		}
		cin >> screen_select;
	}


	return 0;
}

