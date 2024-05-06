#include<iostream>
#include<string>
using namespace std;
//화면
enum SCENES {
	TITLE_SCENE = 1,
	MAIN_SDENE = 2,

};

enum MAIN_SCENES {
	CHRACTERSELECT_SCENE = 1,
	GAME_START = 2,

};

enum DUNGEON {       //적 
	AAA = 1,
	BBB = 2,
	CCC = 3,
	DDD = 4,
	EEE = 5,
	FFF = 6,
	GGG = 7,
	HHH = 8,
	III = 9,
	BOSS = 10
};

enum CLASS {             //직업
	WARRIOR = 1,
	GUNNER = 2,
	MAGE = 3
};

//화면 UI
class Scenes
{
public:
	void title()
	{
		cout << "********************" << endl;
		cout << "********************" << endl;
		cout << "********************" << endl;
		cout << "****  RPG GAME  ****" << endl;
		cout << "********************" << endl;
		cout << "********************" << endl;
		cout << "********************" << endl;

	}
	void main1()
	{
		cout << "1. 타이틀화면 " << endl;
		cout << "2. 메인 메뉴 " << endl;

	}
	void main2()
	{
		cout << "메뉴를 선택하세요  " << endl;
		cout << "1. 케릭터 선택창 " << endl;
		cout << "2. 게임시작 " << endl;

	}
	void Character_select()
	{
		cout << "케릭터를 선택하세요  " << endl;
		cout << "1. 전사 " << endl;
		cout << "2. 거너" << endl;
		cout << "3. 마법사" << endl;

	}
	void dungeon()
	{
		cout << "입장할 던전을 선택하시오" << endl;
		cout << "1. AAA " << endl;
		cout << "2. BBB" << endl;
		cout << "3. CCC" << endl;
		cout << "4. DDD " << endl;
		cout << "5. EEE" << endl;
		cout << "6. FFF" << endl;
		cout << "7. GGG " << endl;
		cout << "8. HHH" << endl;
		cout << "9. III" << endl;
		cout << "10. BOSS" << endl;

	}
};


//직업 기본스텟
enum WARRIOR_STATE {     //기본스텟
	W_HP = 100,
	W_ATK = 10,
	W_DEF = 5,
	W_EXP = 0,
	W_LEVEL = 1
};
enum GUNNER_STATE {
	G_HP = 80,
	G_ATK = 13,
	G_DEF = 4,
	G_EXP = 0,
	G_LEVEL = 1
};
enum MAGE_STATE {
	M_HP = 60,
	M_ATK = 15,
	M_DEF = 1,
	M_EXP = 0,
	M_LEVEL = 1
};
//직업정보

class character
{
private:
	string name;
	int HP;
	int ATK;
	int DEF;
	int EXP;
	int LEVEL;
public:

	character() 
	{
		name = 'a';
		HP = 0;
		ATK = 0;
		DEF = 0;
		EXP = 0;
		LEVEL = 0;
	}
	character(const string n, int h, int a, int d, int e, int l)
		: name(n),HP(h), ATK(a), DEF(d), EXP(e), LEVEL(l)
	{
		
	}
	void init(const string n, int h, int a, int d, int e, int l)
	{
		name = n;
		HP = h;
		ATK = a;
		DEF = d;
		EXP = e;
		LEVEL = l;
	}
	void showstate()
	{
		cout << "이름 : " << name << endl;
		cout << "체력 : " << HP << endl;
		cout << "공격력 : " << ATK << endl;
		cout << "방어력 : " << DEF << endl;
		cout << "경험치 : " << EXP << endl;
		cout << "레벨 : " << LEVEL << endl;
	}
	string getname()const  { return name; }
	int getHP() { return HP; }
	int getATK() { return ATK; }
	int getDEF() { return DEF; }
	int getEXP() { return EXP; }
	int getLEVEL() { return LEVEL; }

	
	void setname(const string Name) { name = Name; }
	void setHP(int hp) { HP = +hp; }
	void setATK(int atk) { ATK = +atk; }
	void setDEF(int def) { DEF = +def; }
	void setEXP(int exp) { EXP = +exp; }
	void setLEVEL(int level) { LEVEL = +level; }

	
	
};





//
//class warrior : public character
//{
//private:
//	character war;
//	int enemy;
//
//public:
//	/*warrior(string& n, int h, int a, int d, int e, int f)
//		: name(n), HP(100), ATK(10), DEF(5), EXP(0), LEVEL(1)*/
//
//	void w_init()
//	{
//		character();
//	}
//		
//		
//	
//	void Show_warrior()
//	{
//		showstate();
//	
//	}
//	
//};






class gunner
{

public:
	string name;  //이름
	int HP;
	int ATK;
	int DEF;
	int EXP;
	int LEVEL;

	/*warrior(string& n, int h, int a, int d, int e, int f)
		: name(n), HP(100), ATK(10), DEF(5), EXP(0), LEVEL(1)*/

	gunner()
		:name(), HP(80), ATK(13), DEF(4), EXP(0), LEVEL(1)
	{

	}
	void Show_gunner()
	{

		cout << "이름 : " << name << endl;
		cout << "체력 : " << HP << endl;
		cout << "공격력 : " << ATK << endl;
		cout << "방어력 : " << DEF << endl;
		cout << "경험치 : " << EXP << endl;
		cout << "레벨 : " << LEVEL << endl;
	}
};
class mage
{

public:
	string name;  //이름
	int HP;
	int ATK;
	int DEF;
	int EXP;
	int LEVEL;

	/*warrior(string& n, int h, int a, int d, int e, int f)
		: name(n), HP(100), ATK(10), DEF(5), EXP(0), LEVEL(1)*/

	mage()
		:name(), HP(70), ATK(15), DEF(1), EXP(0), LEVEL(1)
	{

	}
	void Show_mage()
	{

		cout << "이름 : " << name << endl;
		cout << "체력 : " << HP << endl;
		cout << "공격력 : " << ATK << endl;
		cout << "방어력 : " << DEF << endl;
		cout << "경험치 : " << EXP << endl;
		cout << "레벨 : " << LEVEL << endl;
	}

};
//적정보
class enemy
{

	string name;
	int HP;
	int ATK;
	int DEF;
	int EXP;
public:
	enemy() {}
	enemy(const string n, int h, int a, int d, int e)
		: name(n), HP(h), ATK(a), DEF(d), EXP(e)
	{
		
	}

	void init(const string n, int h, int a, int d, int e)
	{
		name = n;
		HP = h;
		ATK = a;
		DEF = d;
		EXP = e;

	}
	string getname() { return name; }
	int getHP() const { return HP; }
	int getATK() const { return ATK; }
	int getDEF() const { return DEF; }
	int getEXP() const { return EXP; }



	/*{

		cout << name << endl;
		cout << HP << endl;
		cout << ATK << endl;
		cout << DEF << endl;
		cout << EXP << endl;

	}
		*/

};






//class enemy_AAA
//{
//public:
//	string name;
//	int HP;
//	int ATK;
//	int DEF;
//	int EXP;
//
//	/*enemy_AAA(string& n,int h,int a,int d,int e)
//		:name(n),HP(20),ATK(5),DEF(1),EXP(10)*/
//	enemy_AAA()
//		:name("AAA"), HP(20), ATK(5), DEF(1), EXP(100)
//	{}
//	void AAA_state()
//	{
//		cout << name << endl;
//		cout << HP << endl;
//		cout << ATK << endl;
//		cout << DEF << endl;
//		cout << EXP << endl;
//	}
//};
//class enemy_BBB
//{
//public:
//	string name;
//	int HP;
//	int ATK;
//	int DEF;
//	int EXP;
//
//	/*enemy_AAA(string& n,int h,int a,int d,int e)
//		:name(n),HP(20),ATK(5),DEF(1),EXP(10)*/
//	enemy_BBB()
//		:name("BBB"), HP(1000), ATK(50), DEF(1), EXP(100)
//	{}
//	void BBB_state()
//	{
//		cout << name << endl;
//		cout << HP << endl;
//		cout << ATK << endl;
//		cout << DEF << endl;
//		cout << EXP << endl;
//	}
//};
//class enemy_CCC
//{
//public:
//	string name;
//	int HP;
//	int ATK;
//	int DEF;
//	int EXP;
//
//	/*enemy_AAA(string& n,int h,int a,int d,int e)
//		:name(n),HP(20),ATK(5),DEF(1),EXP(10)*/
//	enemy_CCC()
//		:name("CCC"), HP(20), ATK(5), DEF(1), EXP(100)
//	{}
//	void AAA_state()
//	{
//		cout << name << endl;
//		cout << HP << endl;
//		cout << ATK << endl;
//		cout << DEF << endl;
//		cout << EXP << endl;
//	}
//};
//class enemy_DDD
//{
//public:
//	string name;
//	int HP;
//	int ATK;
//	int DEF;
//	int EXP;
//
//	/*enemy_AAA(string& n,int h,int a,int d,int e)
//		:name(n),HP(20),ATK(5),DEF(1),EXP(10)*/
//	enemy_DDD()
//		:name("DDD"), HP(20), ATK(5), DEF(1), EXP(100)
//	{}
//	void AAA_state()
//	{
//		cout << name << endl;
//		cout << HP << endl;
//		cout << ATK << endl;
//		cout << DEF << endl;
//		cout << EXP << endl;
//	}
//};
//class enemy_EEE
//{
//public:
//	string name;
//	int HP;
//	int ATK;
//	int DEF;
//	int EXP;
//
//	/*enemy_AAA(string& n,int h,int a,int d,int e)
//		:name(n),HP(20),ATK(5),DEF(1),EXP(10)*/
//	enemy_EEE()
//		:name("EEE"), HP(20), ATK(5), DEF(1), EXP(100)
//	{}
//	void AAA_state()
//	{
//		cout << name << endl;
//		cout << HP << endl;
//		cout << ATK << endl;
//		cout << DEF << endl;
//		cout << EXP << endl;
//	}
//};
//class enemy_FFF
//{
//public:
//	string name;
//	int HP;
//	int ATK;
//	int DEF;
//	int EXP;
//
//	/*enemy_AAA(string& n,int h,int a,int d,int e)
//		:name(n),HP(20),ATK(5),DEF(1),EXP(10)*/
//	enemy_FFF()
//		:name("FFF"), HP(20), ATK(5), DEF(1), EXP(100)
//	{}
//	void AAA_state()
//	{
//		cout << name << endl;
//		cout << HP << endl;
//		cout << ATK << endl;
//		cout << DEF << endl;
//		cout << EXP << endl;
//	}
//};
//class enemy_GGG
//{
//public:
//	string name;
//	int HP;
//	int ATK;
//	int DEF;
//	int EXP;
//
//	/*enemy_AAA(string& n,int h,int a,int d,int e)
//		:name(n),HP(20),ATK(5),DEF(1),EXP(10)*/
//	enemy_GGG()
//		:name("GGG"), HP(20), ATK(5), DEF(1), EXP(100)
//	{}
//	void AAA_state()
//	{
//		cout << name << endl;
//		cout << HP << endl;
//		cout << ATK << endl;
//		cout << DEF << endl;
//		cout << EXP << endl;
//	}
//};
//class enemy_HHH
//{
//public:
//	string name;
//	int HP;
//	int ATK;
//	int DEF;
//	int EXP;
//
//	/*enemy_AAA(string& n,int h,int a,int d,int e)
//		:name(n),HP(20),ATK(5),DEF(1),EXP(10)*/
//	enemy_HHH()
//		:name("HHH"), HP(20), ATK(5), DEF(1), EXP(100)
//	{}
//	void AAA_state()
//	{
//		cout << name << endl;
//		cout << HP << endl;
//		cout << ATK << endl;
//		cout << DEF << endl;
//		cout << EXP << endl;
//	}
//};
//class enemy_III
//{
//public:
//	string name;
//	int HP;
//	int ATK;
//	int DEF;
//	int EXP;
//
//	/*enemy_AAA(string& n,int h,int a,int d,int e)
//		:name(n),HP(20),ATK(5),DEF(1),EXP(10)*/
//	enemy_III()
//		:name("III"), HP(20), ATK(5), DEF(1), EXP(100)
//	{}
//	void AAA_state()
//	{
//		cout << name << endl;
//		cout << HP << endl;
//		cout << ATK << endl;
//		cout << DEF << endl;
//		cout << EXP << endl;
//	}
//};
//class enemy_BOSS
//{
//public:
//	string name;
//	int HP;
//	int ATK;
//	int DEF;
//	int EXP;
//
//	/*enemy_AAA(string& n,int h,int a,int d,int e)
//		:name(n),HP(20),ATK(5),DEF(1),EXP(10)*/
//	enemy_BOSS()
//		:name("BOSS"), HP(20), ATK(5), DEF(1), EXP(100)
//	{}
//	void AAA_state()
//	{
//		cout << name << endl;
//		cout << HP << endl;
//		cout << ATK << endl;
//		cout << DEF << endl;
//		cout << EXP << endl;
//	}
//};
//전투
class combat
{
private:

	character& mychar;
	enemy& AAA;



	int b_a;   // 받은 피해
	int b_b;   // 준 피해

	int a;   //받는 피해
	int b;   //입힌 피해
	int i;   //전투 횟수
public:

	combat()
		: mychar(*(new character())), AAA(*(new enemy())), b_a(0), b_b(0), a(0), b(0), i(0)
	{}

	void init(character& c, enemy& e, int aa, int ab, int ac, int ad, int ae)
	{
		mychar = c;
		AAA = e;
		b_b = aa;
		b_b = ab;
		a = ac;
		b = ad;
		i = ae;

	}





	int damage_recive_a()
	{
		a = mychar.getHP() - b_a;
		return a;
	}
	int damage_dealt_b()
	{
		b = AAA.getHP() - b_b;
		return b;
	}

	int damage_recive()
	{
		b_a = AAA.getATK() - mychar.getDEF();
		return b_a;
	}
	int damage_dealt()
	{
		b_b = mychar.getATK() - AAA.getDEF();
		return b_b;
	}

	void combat1()
	{


		for (i = 1; (i * (b_b)) < AAA.getHP() + b_b; i++)
		{
			cout << "이름 : " << mychar.getname() << endl;
			cout << "레벨 : " << mychar.getLEVEL() << endl;
			cout << "체력 : " << mychar.getHP() - (i * (b_a)) << endl;
			cout << "공격력 :" << mychar.getATK() << endl;
			cout << "방어력 : " << mychar.getDEF() << endl;
			cout << endl;
			cout << "적 이름 : " << AAA.getname() << endl;
			cout << "체력 : " << AAA.getHP() - (i * (b_b)) << endl;
			cout << "공격력 :" << AAA.getATK() << endl;
			cout << "방어력 : " << AAA.getDEF() << endl;
			cout << endl;
			cout << mychar.getname() << " 은(는) " << AAA.getname() << "에게 " << b_b << " 만큼 피해를 줬다." << endl;
			cout << AAA.getname() << " 은(는) " << mychar.getname() << "에게 " << b_a << " 만큼 피해를 줬다." << endl;
		}




	}
	/*void battel()
	{
		if (mychar.HP - (i * (b_a)) < 0 || AAA.HP - (i * (b_b)) < 0)
		{
			win();
		}

	}*/

	//int EXP_level()  // 전투가 끝나면 
	//{
	//	mychar.EXP = mychar.EXP + AAA.EXP;
	//	switch (mychar.LEVEL)
	//	{
	//	case 1:
	//		if (mychar.EXP >= 100)
	//		{
	//			mychar.EXP -= 100;
	//			mychar.LEVEL += 1;
	//			mychar.HP += 100;   //hp 증가량
	//			mychar.ATK += 20;   //atk 증가량
	//			mychar.DEF += 10;   //def 증가량
	//		}
	//		break;
	//	case 2:
	//		if (mychar.EXP >= 100)
	//		{
	//			mychar.EXP -= 100;
	//			mychar.LEVEL += 1;
	//			mychar.HP += 100;   //hp 증가량
	//			mychar.ATK += 20;   //atk 증가량
	//			mychar.DEF += 10;   //def 증가량

	//		}
	//		break;
	//	case 3:
	//		if (mychar.EXP >= 100)
	//		{
	//			mychar.EXP -= 100;
	//			mychar.LEVEL += 1;
	//			mychar.HP += 100;   //hp 증가량
	//			mychar.ATK += 20;   //atk 증가량
	//			mychar.DEF += 10;   //def 증가량

	//		}
	//		break;
	//	case 4:

	//		
	//		break;
	//	default:
	//		break;

	//	}
	//	return mychar.EXP;
	//	return mychar.LEVEL;
	//	
	//	/*cout << "나의 경험치 : " << mychar.EXP << endl;
	//	cout << "나의 레벨 : " << mychar.LEVEL << endl;*/
	//	/*return mychar.EXP;
	//	return mychar.LEVEL;*/
	//}

	int win()
	{
		if (mychar.getHP() - (i * (b_a)) <= 0)
		{
			cout << "GAME OVER" << endl;
		}
		else if (mychar.getHP() - (i * (b_a)) > 0)
		{
			cout << "YOU WIN" << endl;
			mychar.setEXP(AAA.getEXP());



			if (mychar.getEXP() <= 100)
			{
				mychar.setEXP(-100);
				mychar.setLEVEL(1);
				mychar.setHP(100);   //hp 증가량
				mychar.setATK(20);   //atk 증가량
				mychar.setDEF(10);   //def 증가량
			}

			cout << "나의 경험치 : " << mychar.getEXP() << endl;
			cout << "나의 레벨 : " << mychar.getLEVEL() << endl;
			return mychar.getEXP();
			return mychar.getLEVEL();
		}
	}
	void AAAAAAAA()
	{
		combat::damage_recive_a();
		combat::damage_dealt_b();
		combat::damage_recive();
		combat::damage_dealt();

		combat::combat1();
		combat::win();

	}
};
//class combatBBB
//{
//public:
//
//	warrior& mychar;
//	enemy_BBB& BBB;
//
//
//
//	int b_a;   // 받은 피해
//	int b_b;   // 준 피해
//
//	int a; //받는 피해
//	int b;   //입힌 피해
//	int i; //전투 횟수
//public:
//
//	combatBBB()
//		: mychar(*(new warrior())), BBB(*(new enemy_BBB())), b_a(0), b_b(0), a(0), b(0), i(0)
//	{}
//
//
//
//
//
//	int damage_recive_a()
//	{
//		a = mychar.HP -= b_a;
//		return a;
//	}
//	int damage_dealt_b()
//	{
//		b = BBB.HP -= b_b;
//		return b;
//	}
//
//	int damage_recive()
//	{
//		b_a = BBB.ATK - mychar.DEF;
//		return b_a;
//	}
//	int damage_dealt()
//	{
//		b_b = mychar.ATK - BBB.DEF;
//		return b_b;
//	}
//
//	void combat1()
//	{
//
//
//		for (i = 1; (i * (b_b)) < BBB.HP + b_b; i++)
//		{
//			cout << "이름 : " << mychar.name << endl;
//			cout << "레벨 : " << mychar.LEVEL << endl;
//			cout << "체력 : " << mychar.HP - (i * (b_a)) << endl;
//			cout << "공격력 :" << mychar.ATK << endl;
//			cout << "방어력 : " << mychar.DEF << endl;
//			cout << endl;
//			cout << "적 이름 : " << BBB.name << endl;
//			cout << "체력 : " << BBB.HP - (i * (b_b)) << endl;
//			cout << "공격력 :" << BBB.ATK << endl;
//			cout << "방어력 : " << BBB.DEF << endl;
//			cout << endl;
//			cout << mychar.name << " 은(는) " << BBB.name << "에게 " << b_b << " 만큼 피해를 줬다." << endl;
//			cout << BBB.name << " 은(는) " << mychar.name << "에게 " << b_a << " 만큼 피해를 줬다." << endl;
//			if (mychar.HP - (i * (b_a)) < 0)
//			{
//				break;
//			}
//		}
//
//
//
//
//	}
//
//
//	int win()
//	{
//		if (mychar.HP - (i * (b_a)) <= 0)
//		{
//			cout << "GAME OVER" << endl;
//		}
//		else if (mychar.HP - (i * (b_a)) > 0)
//		{
//			cout << "YOU WIN" << endl;
//			mychar.EXP = mychar.EXP + BBB.EXP;
//
//			switch (mychar.LEVEL)
//			{
//			case 1:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//				}
//				break;
//			case 2:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 3:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 4:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 5:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 6:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 7:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 8:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 9:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 10:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//
//			default:
//				break;
//
//			}
//
//
//			cout << "나의 경험치 : " << mychar.EXP << endl;
//			cout << "나의 레벨 : " << mychar.LEVEL << endl;
//			return mychar.EXP;
//			return mychar.LEVEL;
//		}
//	}
//	void AAAAAAAA()
//	{
//		combatBBB::damage_recive_a();
//		combatBBB::damage_dealt_b();
//		combatBBB::damage_recive();
//		combatBBB::damage_dealt();
//
//		combatBBB::combat1();
//		combatBBB::win();
//		
//	}
//
//};
//class combatCCC
//{
//public:
//
//	warrior& mychar;
//	enemy_CCC& CCC;
//
//
//
//	int b_a;   // 받은 피해
//	int b_b;   // 준 피해
//
//	int a; //받는 피해
//	int b;   //입힌 피해
//	int i; //전투 횟수
//public:
//
//	combatCCC()
//		: mychar(*(new warrior())), CCC(*(new enemy_CCC())), b_a(0), b_b(0), a(0), b(0), i(0)
//	{}
//
//
//
//
//
//	int damage_recive_a()
//	{
//		a = mychar.HP -= b_a;
//		return a;
//	}
//	int damage_dealt_b()
//	{
//		b = CCC.HP -= b_b;
//		return b;
//	}
//
//	int damage_recive()
//	{
//		b_a = CCC.ATK - mychar.DEF;
//		return b_a;
//	}
//	int damage_dealt()
//	{
//		b_b = mychar.ATK - CCC.DEF;
//		return b_b;
//	}
//
//	void combat1()
//	{
//
//
//		for (i = 1; (i * (b_b)) < CCC.HP + b_b; i++)
//		{
//			cout << "이름 : " << mychar.name << endl;
//			cout << "레벨 : " << mychar.LEVEL << endl;
//			cout << "체력 : " << mychar.HP - (i * (b_a)) << endl;
//			cout << "공격력 :" << mychar.ATK << endl;
//			cout << "방어력 : " << mychar.DEF << endl;
//			cout << endl;
//			cout << "적 이름 : " << CCC.name << endl;
//			cout << "체력 : " << CCC.HP - (i * (b_b)) << endl;
//			cout << "공격력 :" << CCC.ATK << endl;
//			cout << "방어력 : " << CCC.DEF << endl;
//			cout << endl;
//			cout << mychar.name << " 은(는) " << CCC.name << "에게 " << b_b << " 만큼 피해를 줬다." << endl;
//			cout << CCC.name << " 은(는) " << mychar.name << "에게 " << b_a << " 만큼 피해를 줬다." << endl;
//			if (mychar.HP - (i * (b_a)) < 0)
//			{
//				break;
//			}
//		}
//
//
//
//
//	}
//
//
//	int win()
//	{
//		if (mychar.HP - (i * (b_a)) <= 0)
//		{
//			cout << "GAME OVER" << endl;
//		}
//		else if (mychar.HP - (i * (b_a)) > 0)
//		{
//			cout << "YOU WIN" << endl;
//			mychar.EXP = mychar.EXP + CCC.EXP;
//
//			switch (mychar.LEVEL)
//			{
//			case 1:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//				}
//				break;
//			case 2:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 3:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 4:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 5:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 6:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 7:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 8:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 9:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 10:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//
//			default:
//				break;
//
//			}
//
//
//			cout << "나의 경험치 : " << mychar.EXP << endl;
//			cout << "나의 레벨 : " << mychar.LEVEL << endl;
//			return mychar.EXP;
//			return mychar.LEVEL;
//		}
//	}
//	void AAAAAAAA()
//	{
//		combatCCC::damage_recive_a();
//		combatCCC::damage_dealt_b();
//		combatCCC::damage_recive();
//		combatCCC::damage_dealt();
//
//		combatCCC::combat1();
//		combatCCC::win();
//		
//	}
//
//};
//class combatDDD
//{
//public:
//
//	warrior& mychar;
//	enemy_DDD& DDD;
//
//
//
//	int b_a;   // 받은 피해
//	int b_b;   // 준 피해
//
//	int a; //받는 피해
//	int b;   //입힌 피해
//	int i; //전투 횟수
//public:
//
//	combatDDD()
//		: mychar(*(new warrior())), DDD(*(new enemy_DDD())), b_a(0), b_b(0), a(0), b(0), i(0)
//	{}
//
//
//
//
//
//	int damage_recive_a()
//	{
//		a = mychar.HP -= b_a;
//		return a;
//	}
//	int damage_dealt_b()
//	{
//		b = DDD.HP -= b_b;
//		return b;
//	}
//
//	int damage_recive()
//	{
//		b_a = DDD.ATK - mychar.DEF;
//		return b_a;
//	}
//	int damage_dealt()
//	{
//		b_b = mychar.ATK - DDD.DEF;
//		return b_b;
//	}
//
//	void combat1()
//	{
//
//
//		for (i = 1; (i * (b_b)) < DDD.HP + b_b; i++)
//		{
//			cout << "이름 : " << mychar.name << endl;
//			cout << "레벨 : " << mychar.LEVEL << endl;
//			cout << "체력 : " << mychar.HP - (i * (b_a)) << endl;
//			cout << "공격력 :" << mychar.ATK << endl;
//			cout << "방어력 : " << mychar.DEF << endl;
//			cout << endl;
//			cout << "적 이름 : " << DDD.name << endl;
//			cout << "체력 : " << DDD.HP - (i * (b_b)) << endl;
//			cout << "공격력 :" << DDD.ATK << endl;
//			cout << "방어력 : " << DDD.DEF << endl;
//			cout << endl;
//			cout << mychar.name << " 은(는) " << DDD.name << "에게 " << b_b << " 만큼 피해를 줬다." << endl;
//			cout << DDD.name << " 은(는) " << mychar.name << "에게 " << b_a << " 만큼 피해를 줬다." << endl;
//			if (mychar.HP - (i * (b_a)) < 0)
//			{
//				break;
//			}
//		}
//
//
//
//
//	}
//
//
//	int win()
//	{
//		if (mychar.HP - (i * (b_a)) <= 0)
//		{
//			cout << "GAME OVER" << endl;
//		}
//		else if (mychar.HP - (i * (b_a)) > 0)
//		{
//			cout << "YOU WIN" << endl;
//			mychar.EXP = mychar.EXP + DDD.EXP;
//
//			switch (mychar.LEVEL)
//			{
//			case 1:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//				}
//				break;
//			case 2:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 3:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 4:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 5:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 6:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 7:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 8:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 9:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 10:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//
//			default:
//				break;
//
//			}
//
//
//			cout << "나의 경험치 : " << mychar.EXP << endl;
//			cout << "나의 레벨 : " << mychar.LEVEL << endl;
//			return mychar.EXP;
//			return mychar.LEVEL;
//		}
//	}
//	void AAAAAAAA()
//	{
//		combatDDD::damage_recive_a();
//		combatDDD::damage_dealt_b();
//		combatDDD::damage_recive();
//		combatDDD::damage_dealt();
//
//		combatDDD::combat1();
//		combatDDD::win();
//		
//	}
//
//};
//class combatEEE
//{
//public:
//
//	warrior& mychar;
//	enemy_EEE& EEE;
//
//
//
//	int b_a;   // 받은 피해
//	int b_b;   // 준 피해
//
//	int a; //받는 피해
//	int b;   //입힌 피해
//	int i; //전투 횟수
//public:
//
//	combatEEE()
//		: mychar(*(new warrior())), EEE(*(new enemy_EEE())), b_a(0), b_b(0), a(0), b(0), i(0)
//	{}
//
//
//
//
//
//	int damage_recive_a()
//	{
//		a = mychar.HP -= b_a;
//		return a;
//	}
//	int damage_dealt_b()
//	{
//		b = EEE.HP -= b_b;
//		return b;
//	}
//
//	int damage_recive()
//	{
//		b_a = EEE.ATK - mychar.DEF;
//		return b_a;
//	}
//	int damage_dealt()
//	{
//		b_b = mychar.ATK - EEE.DEF;
//		return b_b;
//	}
//
//	void combat1()
//	{
//
//
//		for (i = 1; (i * (b_b)) < EEE.HP + b_b; i++)
//		{
//			cout << "이름 : " << mychar.name << endl;
//			cout << "레벨 : " << mychar.LEVEL << endl;
//			cout << "체력 : " << mychar.HP - (i * (b_a)) << endl;
//			cout << "공격력 :" << mychar.ATK << endl;
//			cout << "방어력 : " << mychar.DEF << endl;
//			cout << endl;
//			cout << "적 이름 : " << EEE.name << endl;
//			cout << "체력 : " << EEE.HP - (i * (b_b)) << endl;
//			cout << "공격력 :" << EEE.ATK << endl;
//			cout << "방어력 : " << EEE.DEF << endl;
//			cout << endl;
//			cout << mychar.name << " 은(는) " << EEE.name << "에게 " << b_b << " 만큼 피해를 줬다." << endl;
//			cout << EEE.name << " 은(는) " << mychar.name << "에게 " << b_a << " 만큼 피해를 줬다." << endl;
//			if (mychar.HP - (i * (b_a)) < 0)
//			{
//				break;
//			}
//		}
//
//
//
//
//	}
//
//
//	int win()
//	{
//		if (mychar.HP - (i * (b_a)) <= 0)
//		{
//			cout << "GAME OVER" << endl;
//		}
//		else if (mychar.HP - (i * (b_a)) > 0)
//		{
//			cout << "YOU WIN" << endl;
//			mychar.EXP = mychar.EXP + EEE.EXP;
//
//			switch (mychar.LEVEL)
//			{
//			case 1:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//				}
//				break;
//			case 2:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 3:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 4:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 5:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 6:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 7:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 8:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 9:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 10:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//
//			default:
//				break;
//
//			}
//
//
//			cout << "나의 경험치 : " << mychar.EXP << endl;
//			cout << "나의 레벨 : " << mychar.LEVEL << endl;
//			return mychar.EXP;
//			return mychar.LEVEL;
//		}
//	}
//	void AAAAAAAA()
//	{
//		combatEEE::damage_recive_a();
//		combatEEE::damage_dealt_b();
//		combatEEE::damage_recive();
//		combatEEE::damage_dealt();
//
//		combatEEE::combat1();
//		combatEEE::win();
//		
//	}
//
//};
//class combatFFF
//{
//public:
//
//	warrior& mychar;
//	enemy_FFF& FFF;
//
//
//
//	int b_a;   // 받은 피해
//	int b_b;   // 준 피해
//
//	int a; //받는 피해
//	int b;   //입힌 피해
//	int i; //전투 횟수
//public:
//
//	combatFFF()
//		: mychar(*(new warrior())), FFF(*(new enemy_FFF())), b_a(0), b_b(0), a(0), b(0), i(0)
//	{}
//
//
//
//
//
//	int damage_recive_a()
//	{
//		a = mychar.HP -= b_a;
//		return a;
//	}
//	int damage_dealt_b()
//	{
//		b = FFF.HP -= b_b;
//		return b;
//	}
//
//	int damage_recive()
//	{
//		b_a = FFF.ATK - mychar.DEF;
//		return b_a;
//	}
//	int damage_dealt()
//	{
//		b_b = mychar.ATK - FFF.DEF;
//		return b_b;
//	}
//
//	void combat1()
//	{
//
//
//		for (i = 1; (i * (b_b)) < FFF.HP + b_b; i++)
//		{
//			cout << "이름 : " << mychar.name << endl;
//			cout << "레벨 : " << mychar.LEVEL << endl;
//			cout << "체력 : " << mychar.HP - (i * (b_a)) << endl;
//			cout << "공격력 :" << mychar.ATK << endl;
//			cout << "방어력 : " << mychar.DEF << endl;
//			cout << endl;
//			cout << "적 이름 : " << FFF.name << endl;
//			cout << "체력 : " << FFF.HP - (i * (b_b)) << endl;
//			cout << "공격력 :" << FFF.ATK << endl;
//			cout << "방어력 : " << FFF.DEF << endl;
//			cout << endl;
//			cout << mychar.name << " 은(는) " << FFF.name << "에게 " << b_b << " 만큼 피해를 줬다." << endl;
//			cout << FFF.name << " 은(는) " << mychar.name << "에게 " << b_a << " 만큼 피해를 줬다." << endl;
//			if (mychar.HP - (i * (b_a)) < 0)
//			{
//				break;
//			}
//		}
//
//
//
//
//	}
//
//
//	int win()
//	{
//		if (mychar.HP - (i * (b_a)) <= 0)
//		{
//			cout << "GAME OVER" << endl;
//		}
//		else if (mychar.HP - (i * (b_a)) > 0)
//		{
//			cout << "YOU WIN" << endl;
//			mychar.EXP = mychar.EXP + FFF.EXP;
//
//			switch (mychar.LEVEL)
//			{
//			case 1:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//				}
//				break;
//			case 2:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 3:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 4:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 5:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 6:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 7:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 8:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 9:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 10:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//
//			default:
//				break;
//
//			}
//
//
//			cout << "나의 경험치 : " << mychar.EXP << endl;
//			cout << "나의 레벨 : " << mychar.LEVEL << endl;
//			return mychar.EXP;
//			return mychar.LEVEL;
//		}
//	}
//	void AAAAAAAA()
//	{
//		combatFFF::damage_recive_a();
//		combatFFF::damage_dealt_b();
//		combatFFF::damage_recive();
//		combatFFF::damage_dealt();
//
//		combatFFF::combat1();
//		combatFFF::win();
//
//	}
//};
//
//class combatGGG
//{
//public:
//
//	warrior& mychar;
//	enemy_GGG& GGG;
//
//
//
//	int b_a;   // 받은 피해
//	int b_b;   // 준 피해
//
//	int a; //받는 피해
//	int b;   //입힌 피해
//	int i; //전투 횟수
//public:
//
//	combatGGG()
//		: mychar(*(new warrior())), GGG(*(new enemy_GGG())), b_a(0), b_b(0), a(0), b(0), i(0)
//	{}
//
//
//
//
//
//	int damage_recive_a()
//	{
//		a = mychar.HP -= b_a;
//		return a;
//	}
//	int damage_dealt_b()
//	{
//		b = GGG.HP -= b_b;
//		return b;
//	}
//
//	int damage_recive()
//	{
//		b_a = GGG.ATK - mychar.DEF;
//		return b_a;
//	}
//	int damage_dealt()
//	{
//		b_b = mychar.ATK - GGG.DEF;
//		return b_b;
//	}
//
//	void combat1()
//	{
//
//
//		for (i = 1; (i * (b_b)) < GGG.HP + b_b; i++)
//		{
//			cout << "이름 : " << mychar.name << endl;
//			cout << "레벨 : " << mychar.LEVEL << endl;
//			cout << "체력 : " << mychar.HP - (i * (b_a)) << endl;
//			cout << "공격력 :" << mychar.ATK << endl;
//			cout << "방어력 : " << mychar.DEF << endl;
//			cout << endl;
//			cout << "적 이름 : " << GGG.name << endl;
//			cout << "체력 : " << GGG.HP - (i * (b_b)) << endl;
//			cout << "공격력 :" << GGG.ATK << endl;
//			cout << "방어력 : " << GGG.DEF << endl;
//			cout << endl;
//			cout << mychar.name << " 은(는) " << GGG.name << "에게 " << b_b << " 만큼 피해를 줬다." << endl;
//			cout << GGG.name << " 은(는) " << mychar.name << "에게 " << b_a << " 만큼 피해를 줬다." << endl;
//			if (mychar.HP - (i * (b_a)) < 0)
//			{
//				break;
//			}
//		}
//
//
//
//
//	}
//
//
//	int win()
//	{
//		if (mychar.HP - (i * (b_a)) <= 0)
//		{
//			cout << "GAME OVER" << endl;
//		}
//		else if (mychar.HP - (i * (b_a)) > 0)
//		{
//			cout << "YOU WIN" << endl;
//			mychar.EXP = mychar.EXP + GGG.EXP;
//
//			switch (mychar.LEVEL)
//			{
//			case 1:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//				}
//				break;
//			case 2:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 3:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 4:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 5:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 6:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 7:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 8:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 9:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 10:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//
//			default:
//				break;
//
//			}
//
//
//			cout << "나의 경험치 : " << mychar.EXP << endl;
//			cout << "나의 레벨 : " << mychar.LEVEL << endl;
//			return mychar.EXP;
//			return mychar.LEVEL;
//		}
//	}
//	void AAAAAAAA()
//	{
//		combatGGG::damage_recive_a();
//		combatGGG::damage_dealt_b();
//		combatGGG::damage_recive();
//		combatGGG::damage_dealt();
//
//		combatGGG::combat1();
//		combatGGG::win();
//		
//	}
//
//};
//class combatHHH
//{
//public:
//
//	warrior& mychar;
//	enemy_HHH& HHH;
//
//
//
//	int b_a;   // 받은 피해
//	int b_b;   // 준 피해
//
//	int a; //받는 피해
//	int b;   //입힌 피해
//	int i; //전투 횟수
//public:
//
//	combatHHH()
//		: mychar(*(new warrior())), HHH(*(new enemy_HHH())), b_a(0), b_b(0), a(0), b(0), i(0)
//	{}
//
//
//
//
//
//	int damage_recive_a()
//	{
//		a = mychar.HP -= b_a;
//		return a;
//	}
//	int damage_dealt_b()
//	{
//		b = HHH.HP -= b_b;
//		return b;
//	}
//
//	int damage_recive()
//	{
//		b_a = HHH.ATK - mychar.DEF;
//		return b_a;
//	}
//	int damage_dealt()
//	{
//		b_b = mychar.ATK - HHH.DEF;
//		return b_b;
//	}
//
//	void combat1()
//	{
//
//
//		for (i = 1; (i * (b_b)) < HHH.HP + b_b; i++)
//		{
//			cout << "이름 : " << mychar.name << endl;
//			cout << "레벨 : " << mychar.LEVEL << endl;
//			cout << "체력 : " << mychar.HP - (i * (b_a)) << endl;
//			cout << "공격력 :" << mychar.ATK << endl;
//			cout << "방어력 : " << mychar.DEF << endl;
//			cout << endl;
//			cout << "적 이름 : " << HHH.name << endl;
//			cout << "체력 : " << HHH.HP - (i * (b_b)) << endl;
//			cout << "공격력 :" << HHH.ATK << endl;
//			cout << "방어력 : " << HHH.DEF << endl;
//			cout << endl;
//			cout << mychar.name << " 은(는) " << HHH.name << "에게 " << b_b << " 만큼 피해를 줬다." << endl;
//			cout << HHH.name << " 은(는) " << mychar.name << "에게 " << b_a << " 만큼 피해를 줬다." << endl;
//			if (mychar.HP - (i * (b_a)) < 0)
//			{
//				break;
//			}
//		}
//
//
//
//
//	}
//
//
//	int win()
//	{
//		if (mychar.HP - (i * (b_a)) <= 0)
//		{
//			cout << "GAME OVER" << endl;
//		}
//		else if (mychar.HP - (i * (b_a)) > 0)
//		{
//			cout << "YOU WIN" << endl;
//			mychar.EXP = mychar.EXP + HHH.EXP;
//
//			switch (mychar.LEVEL)
//			{
//			case 1:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//				}
//				break;
//			case 2:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 3:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 4:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 5:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 6:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 7:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 8:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 9:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 10:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//
//			default:
//				break;
//
//			}
//
//
//			cout << "나의 경험치 : " << mychar.EXP << endl;
//			cout << "나의 레벨 : " << mychar.LEVEL << endl;
//			return mychar.EXP;
//			return mychar.LEVEL;
//		}
//	}
//	void AAAAAAAA()
//	{
//		combatHHH::damage_recive_a();
//		combatHHH::damage_dealt_b();
//		combatHHH::damage_recive();
//		combatHHH::damage_dealt();
//
//		combatHHH::combat1();
//		combatHHH::win();
//		
//	}
//
//};
//class combatIII
//{
//public:
//
//	warrior& mychar;
//	enemy_III& III;
//
//
//
//	int b_a;   // 받은 피해
//	int b_b;   // 준 피해
//
//	int a; //받는 피해
//	int b;   //입힌 피해
//	int i; //전투 횟수
//public:
//
//	combatIII()
//		: mychar(*(new warrior())), III(*(new enemy_III())), b_a(0), b_b(0), a(0), b(0), i(0)
//	{}
//
//
//
//
//
//	int damage_recive_a()
//	{
//		a = mychar.HP -= b_a;
//		return a;
//	}
//	int damage_dealt_b()
//	{
//		b = III.HP -= b_b;
//		return b;
//	}
//
//	int damage_recive()
//	{
//		b_a = III.ATK - mychar.DEF;
//		return b_a;
//	}
//	int damage_dealt()
//	{
//		b_b = mychar.ATK - III.DEF;
//		return b_b;
//	}
//
//	void combat1()
//	{
//
//
//		for (i = 1; (i * (b_b)) < III.HP + b_b; i++)
//		{
//			cout << "이름 : " << mychar.name << endl;
//			cout << "레벨 : " << mychar.LEVEL << endl;
//			cout << "체력 : " << mychar.HP - (i * (b_a)) << endl;
//			cout << "공격력 :" << mychar.ATK << endl;
//			cout << "방어력 : " << mychar.DEF << endl;
//			cout << endl;
//			cout << "적 이름 : " << III.name << endl;
//			cout << "체력 : " << III.HP - (i * (b_b)) << endl;
//			cout << "공격력 :" << III.ATK << endl;
//			cout << "방어력 : " << III.DEF << endl;
//			cout << endl;
//			cout << mychar.name << " 은(는) " << III.name << "에게 " << b_b << " 만큼 피해를 줬다." << endl;
//			cout << III.name << " 은(는) " << mychar.name << "에게 " << b_a << " 만큼 피해를 줬다." << endl;
//			if (mychar.HP - (i * (b_a)) < 0)
//			{
//				break;
//			}
//		}
//
//
//
//
//	}
//
//
//	int win()
//	{
//		if (mychar.HP - (i * (b_a)) <= 0)
//		{
//			cout << "GAME OVER" << endl;
//		}
//		else if (mychar.HP - (i * (b_a)) > 0)
//		{
//			cout << "YOU WIN" << endl;
//			mychar.EXP = mychar.EXP + III.EXP;
//
//			switch (mychar.LEVEL)
//			{
//			case 1:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//				}
//				break;
//			case 2:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 3:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 4:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 5:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 6:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 7:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 8:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 9:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//			case 10:
//				if (mychar.EXP >= 100)
//				{
//					mychar.EXP -= 100;
//					mychar.LEVEL += 1;
//					mychar.HP += 100;   //hp 증가량
//					mychar.ATK += 20;   //atk 증가량
//					mychar.DEF += 10;   //def 증가량
//
//				}
//				break;
//
//			default:
//				break;
//
//			}
//
//
//			cout << "나의 경험치 : " << mychar.EXP << endl;
//			cout << "나의 레벨 : " << mychar.LEVEL << endl;
//			return mychar.EXP;
//			return mychar.LEVEL;
//		}
//	}
//	void AAAAAAAA()
//	{
//		combatIII::damage_recive_a();
//		combatIII::damage_dealt_b();
//		combatIII::damage_recive();
//		combatIII::damage_dealt();
//
//		combatIII::combat1();
//		combatIII::win();
//		
//	}
//
//};
//class combatBOSS
//{
//public:
//
//	warrior& mychar;
//	enemy_BOSS& BOSS;
//
//
//
//	int b_a;   // 받은 피해
//	int b_b;   // 준 피해
//
//	int a; //받는 피해
//	int b;   //입힌 피해
//	int i; //전투 횟수
//public:
//
//	combatBOSS()
//		: mychar(*(new warrior())), BOSS(*(new enemy_BOSS())), b_a(0), b_b(0), a(0), b(0), i(0)
//	{}
//
//
//
//
//
//	int damage_recive_a()
//	{
//		a = mychar.HP -= b_a;
//		return a;
//	}
//	int damage_dealt_b()
//	{
//		b = BOSS.HP -= b_b;
//		return b;
//	}
//
//	int damage_recive()
//	{
//		b_a = BOSS.ATK - mychar.DEF;
//		return b_a;
//	}
//	int damage_dealt()
//	{
//		b_b = mychar.ATK - BOSS.DEF;
//		return b_b;
//	}
//
//	void combat1()
//	{
//
//
//		for (i = 1; (i * (b_b)) < BOSS.HP + b_b; i++)
//		{
//			cout << "이름 : " << mychar.name << endl;
//			cout << "레벨 : " << mychar.LEVEL << endl;
//			cout << "체력 : " << mychar.HP - (i * (b_a)) << endl;
//			cout << "공격력 :" << mychar.ATK << endl;
//			cout << "방어력 : " << mychar.DEF << endl;
//			cout << endl;
//			cout << "적 이름 : " << BOSS.name << endl;
//			cout << "체력 : " << BOSS.HP - (i * (b_b)) << endl;
//			cout << "공격력 :" << BOSS.ATK << endl;
//			cout << "방어력 : " << BOSS.DEF << endl;
//			cout << endl;
//			cout << mychar.name << " 은(는) " << BOSS.name << "에게 " << b_b << " 만큼 피해를 줬다." << endl;
//			cout << BOSS.name << " 은(는) " << mychar.name << "에게 " << b_a << " 만큼 피해를 줬다." << endl;
//			if (mychar.HP - (i * (b_a)) < 0)
//			{
//				break;
//			}
//		}
//
//
//
//
//	}
//
//
//	void win()
//	{
//		if (mychar.HP - (i * (b_a)) <= 0)
//		{
//			cout << "GAME OVER" << endl;
//		}
//		else if (mychar.HP - (i * (b_a)) > 0)
//		{
//			cout << "*******************" << endl;
//			cout << "*******************" << endl;
//			cout << "**CONGRATULATIONS**" << endl;
//			cout << "*******************" << endl;
//			cout << "*******CLEAR*******" << endl;
//			cout << "*******************" << endl;
//			cout << "*******************" << endl;
//		}
//	}
//	void AAAAAAAA()
//	{
//		combatBOSS::damage_recive_a();
//		combatBOSS::damage_dealt_b();
//		combatBOSS::damage_recive();
//		combatBOSS::damage_dealt();
//
//		combatBOSS::combat1();
//		combatBOSS::win();
//
//	}
// 
//};



