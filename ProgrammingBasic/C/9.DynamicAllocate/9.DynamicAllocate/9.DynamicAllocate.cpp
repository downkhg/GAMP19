#include <stdio.h>
#include <stdlib.h>
//�����Ҵ�: ���α׷� �����߿� �޸𸮸� �Ҵ��ϴ� ��. ������ �����ؾ��Ѵ�. -> �޸𸮴���(leak):�������������� �޸𸮰� ���´�. -> �����Ϸ��� �����Ҽ������Ƿ� ���� �ּҰ��� �����ؾ��Ѵ�.
//�����Ҵ�: ���α׷� �������� �޸𸮰� �Ҵ�Ǵ� ��. ��������,�������� -> �����ϴܰ迡 ������. �����Ϸ��� ������ �̸��� ���� �޸𸮿� ���ٰ����ϵ��� ����.
//void������: ���¸� �˼����� �ּҸ� �����ϴ� ������.
//�ٸ����� �������÷��͸� �̿��Ͽ� �����Ҵ�� �޸𸮸� �����Ѵ�.
//������: �ּҰ��� �����ϴ� ���� 
//�����Ҵ�� �޸��� �ּҰ��� �����ϱ����ؼ� �����Ͱ� �ݵ�� �ʿ��ϴ�.
//���� �����Ϳ� ���������ʴٸ� �� �ּҴ� �ٽô� �����Ҽ�������. �����ϰų� ���� �� �� ����.
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