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

void main()
{
	AddTestMain();//1
} //8