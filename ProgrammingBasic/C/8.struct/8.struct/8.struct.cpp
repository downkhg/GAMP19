#include <stdio.h>
#include <string.h>
//����ü: ��������Ǻ���, �迭, ������, ������
//� ����� ��Ÿ���� �������� ������ �̿��Ͽ� ��Ÿ�����Ѵٸ�, ����ü�� Ȱ���Ѵ�.
//�߻�ȭ: ������ ������ȭ�Ͽ� ��Ÿ���� ��.
//����ü�� �Լ��� �ѱ涧 ������ �ϸ� ���� �ڿ��� ���� ��� �� �� �ִ�.
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
	//printf("HP:%d\n", (*pPlayer).nMP);
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
union Matrix4x4 {
	struct {
		float        _11, _12, _13, _14;
		float        _21, _22, _23, _24;
		float        _31, _32, _33, _34;
		float        _41, _42, _43, _44;

	};
	float m[4][4];
};

void UninonTestMain()
{
	Matrix4x4 mat;
	int nCount = 0;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			mat.m[y][x] = nCount;
			nCount++;
		}
	}
	printf("mat._11:%f\n", mat._11);
	printf("mat._21:%f\n", mat._21);
	printf("mat._31:%f\n", mat._31);
	printf("mat._41:%f\n", mat._41);
}

void main()
{
	StructMain();
}