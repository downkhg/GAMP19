#include<stdio.h>

int g_nDataEx; //��������: �ٸ����Ͽ����� ���ٰ����ϳ�, extern�� �̿��Ͽ� ������ �����ؾ� �ٸ����Ͽ����� ���ٰ����ϴ�.
static int g_nStaticDataEx;//������������: �� ���Ͽ����� ���ٰ����ϴ�.

static void SetStaticDateEx(int data)//�����Լ�: �ٸ����Ͽ����� �����Ҽ�����.
{
	g_nStaticDataEx = data;
}

void PrintDataEx()
{
	printf("PrintDataEx:%d\n", g_nDataEx);
}

void PrintStaticDataEx()
{
	SetStaticDateEx(20);
	printf("PrintStaticDataEx:%d\n", g_nStaticDataEx);
}

