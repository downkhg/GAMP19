#include <stdio.h>
#include <string.h>

//����ü: ��������Ǻ���
//� ����� ��Ÿ���� �������� ������ �̿��Ͽ� ��Ÿ�����Ѵٸ�, ����ü�� Ȱ���Ѵ�.
//�߻�ȭ: ������ ������ȭ�Ͽ� ��Ÿ���� ��.
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
	strcpy(sPlayer.strName, "test");
	sPlayer.nMP = mp;
	sPlayer.nHP = hp;
	sPlayer.nAtk = atk;
	sPlayer.nDef = def;
	return sPlayer;
}
void PrintPlayer(SPlayer sPlayer)
{
	printf("Name:%s\n",sPlayer.strName);
	printf("HP:%d\n", sPlayer.nMP);
	printf("MP:%d\n", sPlayer.nHP);
	printf("Atk:%d\n", sPlayer.nAtk);
	printf("Def:%d\n", sPlayer.nDef);
}
void StructMain()
{
	SPlayer sPlayer;
	//sPlayer.strName = "test";
	strcpy(sPlayer.strName, "test");
	sPlayer.nMP = 100;
	sPlayer.nHP = 100;
	sPlayer.nAtk = 10;
	sPlayer.nDef = 10;
	SPlayer sPlayerA = InitPlayer("testA", 100, 100, 10, 10);

	SPlayer arrPlayer[3];

	for (int i = 0; i < 3; i++)
	{
		char name[24];
		sprintf(name, "test%d", i);
		arrPlayer[i] = InitPlayer(name, 100, 100, 10, 10);
		PrintPlayer(arrPlayer[i]);
	}
}

void main()
{

}