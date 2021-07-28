#include<stdio.h>

int g_nDataEx; //전역변수: 다른파일에서도 접근가능하나, extern을 이용하여 변수를 선언해야 다른파일에서도 접근가능하다.
static int g_nStaticDataEx;//정적전역변수: 이 파일에서만 접근가능하다.

static void SetStaticDateEx(int data)//정적함수: 다른파일에서는 접근할수없다.
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

