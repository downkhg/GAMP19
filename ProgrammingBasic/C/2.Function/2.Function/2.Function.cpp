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

//함수의 선언:이런함수가 있다는것을 미리 컴파일러에게 알림.
int Combination(int n, int r);
int Factorial(int n);

int CombinationTestMain(void)
{
	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);
	printf("C(%d, %d) = %d \n", a, b, Combination(a, b));
	return 0;
}
//함수의 정의:선언한 함수의 실체를 만듦.
int Factorial(int n)
{
	int i;
	long result = 1;

	for (i = 1; i <= n; i++)
		result *= i;
	return result;
}
int combination(int n, int r)
{
	int a = Factorial(n);
	int b = Factorial(r);
	int c = Factorial(n - r);
	return (a / b * c);
}
void main()
{
	//AddTestMain();//1
	CombinationTestMain();
} //8