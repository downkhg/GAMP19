#include <stdio.h>

int g_nData;//��������: �ٸ��Լ����� ���ٰ����� ����, ���α׷��� ����ɶ�

void CountData()
{
	int nData = 0;//��������: �Լ��ȿ����� ���ٰ����� ����, �Լ��� ����� ���� �������.
	static int nStaticData = 0;//������������:�Լ��� ����� ���� �����Ǵ� ����./
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
	printf("CountDataMain::g_nData:%d\n", g_nData);//���������� ����Լ������� ���� ��밡���ϴ�. //23. 3
	//�Լ��� �ٸ��Ƿ� �����Ҽ����� ����.
	//printf("CountDataMain::nStaticData:%d\n", nStaticData); 
	//printf("CountDataMain::nData:%d\n", nData); //
}

void SetStaticDateEx(int data);//�����Լ��� �����ϴ��� �ٸ����Ͽ��� �̿��Ҽ� �����Ƿ�, ȣ��� �����Ͽ����� �߻��Ѵ�.
void PrintDataEx();
void PrintStaticDataEx();//���������������ϴ��� �ش����Ͽ� �ִ� �Լ��� ���ؼ� ������ �����ϴ�.

extern int g_nDataEx; //�ٸ����Ͽ� �ִ� ������ ����
extern int g_nStaticDataEx; //�������������� �����ϴ��� �ٸ����Ͽ��� �̿��Ҽ� �����Ƿ�, ȣ��� �����Ͽ����� �߻��Ѵ�.

void GrobalLinkageTestMain()
{
	g_nDataEx = 10;
	//g_nStaticDataEx = 20; //�����Ͽ���: �ٸ����Ͽ� �ִ� ���� ���������� �����Ҽ�����.
	//SetStaticDateEx(200);//�����Ͽ���: �����Լ��� �ٸ����Ͽ����� �����Ҽ�����.
	PrintDataEx();
	PrintStaticDataEx();//�������������� �����ϴ� ������ ���ؼ� ���������� �ٸ������� �����Լ�/���������� ����ȣ���Ҽ��ִ�.
}

void main()//1
{
	CountDataMain(); //2
	printf("main::g_nData:%d:\n", g_nData); //24. 3

	GrobalLinkageTestMain();
}
