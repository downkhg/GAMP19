#include <stdio.h>
#include <stdlib.h>
//�����Ҵ�: ���α׷� �����߿� �޸𸮸� �Ҵ��ϴ� ��. ������ �����ؾ��Ѵ�. -> �޸𸮴���(leak):�������������� �޸𸮰� ���´�.
//�����Ҵ�: ���α׷� �������� �޸𸮰� �Ҵ�Ǵ� ��. ��������,�������� -> �����ϴܰ迡 ������.
//void������: ���¸� �˼����� �ּҸ� �����ϴ� ������.
//�ٸ����� �������÷��͸� �̿��Ͽ� �����Ҵ�� �޸𸮸� �����Ѵ�.
void DynamicAllcateMain()
{
	int* pData = new int();// (int*)malloc(sizeof(int));
	printf("Data:%d\n",*pData);
	//free(pData);
	delete pData;
}

void DynamicAllcateArrayMain()
{
	int nSize;
	printf("arrSize:");
	scanf("%d", &nSize);
	int* pData = new int[nSize];// (int*)malloc(sizeof(int) * nSize);
	for (int i = 0; i < nSize; i++)
	{
		pData[i] = i * 10;

		printf("[%d]%d\n",i,pData[i]);
	}
	//free(pData);
	delete[] pData;
}

void main()
{
	//DynamicAllcateMain();
	DynamicAllcateArrayMain();
}