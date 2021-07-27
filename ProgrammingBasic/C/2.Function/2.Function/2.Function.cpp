#include <stdio.h>
//함수명: 그기능을 대표하는 이름을 짓는것이 적당함.
//매개변수: 함수안에 외부의값을 전달함.
//반환형 함수의이름(매개변수,...)
int Add(int a, int b)//4. 10,20
{
	return a + b; //5. 10+20 = 30 //반환값: 함수내부의 값을 외부에 전달하는것.
}

float Add(float a, float b)//4. 10,20
{
	return a + b; //5. 10+20 = 30 //반환값: 함수내부의 값을 외부에 전달하는것.
}

void AddTestMain()//2
{
	int nResult = Add(10, 20);//3. //6.30
	float fResult = Add(3.14f, 2.5f);
	printf("Result:%d/%f\n", nResult, fResult);//7. 30
}

void main()
{
	AddTestMain();//1
} //8