#include <stdio.h>
//�Լ���: �ױ���� ��ǥ�ϴ� �̸��� ���°��� ������.
//�Ű�����: �Լ��ȿ� �ܺ��ǰ��� ������.
//��ȯ�� �Լ����̸�(�Ű�����,...)
int Add(int a, int b)//4. 10,20
{
	return a + b; //5. 10+20 = 30 //��ȯ��: �Լ������� ���� �ܺο� �����ϴ°�.
}

float Add(float a, float b)//4. 10,20
{
	return a + b; //5. 10+20 = 30 //��ȯ��: �Լ������� ���� �ܺο� �����ϴ°�.
}

void AddTestMain()//2
{
	int nResult = Add(10, 20);//3. //6.30
	float fResult = Add(3.14f, 2.5f);
	printf("Result:%d/%f\n", nResult, fResult);//7. 30
}

//�Լ��� ����:�̷��Լ��� �ִٴ°��� �̸� �����Ϸ����� �˸�.
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
//�Լ��� ����:������ �Լ��� ��ü�� ����.
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