#include <stdio.h>
#include <string.h>
//구조체: 사용자정의변수, 배열, 참조자, 포인터
//어떤 대상을 나타낼때 여러가지 변수를 이용하여 나타내야한다면, 구조체를 활용한다.
//추상화: 어떤대상을 데이터화하여 나타내는 것.
//구조체를 함수에 넘길때 참조를 하면 더욱 자원을 적게 사용 할 수 있다.
struct SPlayer
{
	char strName[24];
	int nHP;
	int nMP;
	int nAtk;
	int nDef;
};
SPlayer InitPlayer(const char* name, int hp, int mp, int atk, int def)
{
	//name[0] = 1;
	SPlayer sPlayer;
	printf("InitPlayer:%d\n", &sPlayer);
	strcpy(sPlayer.strName, name);
	sPlayer.nMP = mp;
	sPlayer.nHP = hp;
	sPlayer.nAtk = atk;
	sPlayer.nDef = def;
	return sPlayer;
}
void InitPlayerRef(SPlayer& sPlayer, const char* name, int hp, int mp, int atk, int def)
{
	printf("InitPlayerRef:%d\n", &sPlayer);
	strcpy(sPlayer.strName, name);
	sPlayer.nMP = mp;
	sPlayer.nHP = hp;
	sPlayer.nAtk = atk;
	sPlayer.nDef = def;
}
void PrintPlayer(SPlayer sPlayer)
{
	printf("PrintPlayer:%d\n", &sPlayer);
	printf("Name:%s\n",sPlayer.strName);
	printf("HP:%d\n", sPlayer.nMP);
	printf("MP:%d\n", sPlayer.nHP);
	printf("Atk:%d\n", sPlayer.nAtk);
	printf("Def:%d\n", sPlayer.nDef);
}
void PrintPlayerPtr(SPlayer* pPlayer)
{
	printf("PrintPlayerPtr:%d\n", pPlayer);
	printf("Name:%s\n", pPlayer->strName);
	printf("HP:%d\n", pPlayer->nMP);
	printf("MP:%d\n", pPlayer->nHP);
	printf("Atk:%d\n", pPlayer->nAtk);
	printf("Def:%d\n", pPlayer->nDef);
}
void StructMain()
{
	SPlayer sPlayer;
	SPlayer sPlayerA;

	//sPlayer.strName = "test";
	strcpy(sPlayer.strName, "test");
	/*sPlayer.nMP = 100;
	sPlayer.nHP = 100;
	sPlayer.nAtk = 10;
	sPlayer.nDef = 10;*/
	PrintPlayer(sPlayer);

	sPlayerA = InitPlayer("testA", 100, 100, 10, 10);
	PrintPlayer(sPlayerA);

	printf("sPlayer:%d\n", &sPlayer);
	printf("sPlayerA:%d\n", &sPlayerA);

	SPlayer arrPlayer[3];
	for (int i = 0; i < 3; i++)
	{
		printf("arrPlayer[%d]:%d\n",i,&arrPlayer[i]);
		char name[24];
		sprintf(name, "test%d", i);
		//arrPlayer[i] = InitPlayer(name, 100, 100, 10, 10);
		InitPlayerRef(arrPlayer[i], name, 100, 100, 10, 10);
		PrintPlayer(arrPlayer[i]);
		PrintPlayerPtr(&arrPlayer[i]);
	}
}

void main()
{
	StructMain();
}