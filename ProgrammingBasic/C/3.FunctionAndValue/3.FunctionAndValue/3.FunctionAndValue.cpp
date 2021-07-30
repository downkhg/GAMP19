#include <stdio.h>

int g_nData;//전역변수: 다른함수에서 접근가능한 변수, 프로그램이 종료될때

void CountData()
{
	int nData = 0;//지역변수: 함수안에서만 접근가능한 변수, 함수를 벗어나면 값이 사라진다.
	static int nStaticData = 0;//정적지역변수:함수를 벗어나도 값이 유지되는 변수./
	nData++; 
	nStaticData++; 
	g_nData++; 
	printf("CountData::g_nData:%d\n", g_nData);  
	printf("CountData::nStaticData:%d\n", nStaticData); 
	printf("CountData::nData:%d\n", nData); 
}

void CountDataMain()
{
	for (int i = 0; i < 3; i++) 
	{
		printf("####### %d #######\n", i);
		CountData(); 
	}
	printf("CountDataMain::g_nData:%d\n", g_nData);//전역변수는 어느함수에서나 쉽게 사용가능하다. //23. 3
	//함수가 다르므로 접근할수없는 변수.
	//printf("CountDataMain::nStaticData:%d\n", nStaticData); 
	//printf("CountDataMain::nData:%d\n", nData); //
}

void SetStaticDateEx(int data);//정적함수를 선언하더라도 다른파일에서 이용할수 없으므로, 호출시 컴파일오류가 발생한다.
void PrintDataEx();
void PrintStaticDataEx();//정적전역변수라하더라도 해당파일에 있는 함수를 통해서 접근은 가능하다.

extern int g_nDataEx; //다른파일에 있는 변수의 선언
extern int g_nStaticDataEx; //정적전역변수를 선언하더라도 다른파일에서 이용할수 없으므로, 호출시 컴파일오류가 발생한다.

void GrobalLinkageTestMain()
{
	g_nDataEx = 10;
	//g_nStaticDataEx = 20; //컴파일오류: 다른파일에 있는 정적 전역변수는 접근할수없다.
	//SetStaticDateEx(200);//컴파일오류: 정적함수도 다른파일에서는 접근할수없다.
	PrintDataEx();
	PrintStaticDataEx();//정적전역변수에 접근하는 변수를 통해서 간접적으로 다른파일의 정적함수/전역변수를 간접호출할수있다.
}

void main()//1
{
	CountDataMain(); //2
	printf("main::g_nData:%d:\n", g_nData); //24. 3

	GrobalLinkageTestMain();
}
