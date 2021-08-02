#include <stdio.h>
#include <string.h>

void ArrayTestMain()
{
	const int nSize = 5;//�迭��ũ��� �ݵ�� ����� �����ؾ��Ѵ�.
	int arrScore[nSize] = {90,80,70,60,50};
	int nMemorySize = sizeof(arrScore);
	int nArraySize = nMemorySize / sizeof(arrScore[0]);
	printf("MemorySize:%d\n",nMemorySize);
	printf("MemoryArray:%d\n", nArraySize);
	//arrScore[0] = 100; //0:ù��°����
	//arrScore[1] = 90;
	//arrScore[2] = 80;
	//arrScore[3] = 70;
	//arrScore[4] = 60; //n-1:����������
	printf("Score:");
	for (int i = 0; i < nSize; i++)
		printf("[%d]%d,",i,arrScore[i]);
	printf("\n");

	int arrCopyScore[nSize];
	printf("Score/CopyScore: %d/%d\n", 
		arrCopyScore,arrScore);
	//arrCopyScore = arrScore; //�����Ѵٰ��ؼ� �����������.
	for (int i = 0; i < nSize; i++)
	{
		arrCopyScore[i] = arrScore[i];
	}
	printf("CopyScore:");
	for (int i = 0; i < nSize; i++)
		printf("[%d]%d,", i, arrCopyScore[i]);
	printf("\n");
}
//�迭���� �ּҰ��� ã�Ƽ� ����϶�.
//(�ּҰ�, �迭������ ���� ���� ���� ã�°�)
//������: 30,40,50,10,20, �ּҰ��� �˻��ϱ����� ������ ����
//�˰���: 
//���迭�� ���� ���ؼ� ���� ���� ���� �������� ã�´�.
//ù��°���� �����ϰ�, ����Ȱ����� ���� ���� ������ ���� �ּҰ����� ��ä�Ѵ�.
void ArrayFindMinDataMain()
{
	int arrData[5] = { 30,40,50,10,20 };
	int nMin = arrData[0];

	for (int i = 0; i < 5; i++)
	{
		if (nMin > arrData[i])
		{
			nMin = arrData[i];
		}
	}
	printf("Min:%d\n", nMin);
}
//������: �ּҰ��� �����ϴ� ����
//&:������ �ּҰ��� �������� ������.
//*:�����Ͱ� ������ �ִ� �ּ��� �޸𸮿� �ִ� �����Ͱ�.
void PointerMain()
{
	int nData = 10;
	int* pData = &nData;
	printf("1.nData[%d]:%d\n",&nData,nData);
	printf("1.pData[%d]:%d\n", *pData, pData);
	//nData�� ���� �����ϸ� *pData�� �������̳��´� 
	//->�����ʹ� �����޸��� ���� �����Ҽ��ִ�.
	nData = 20;
	printf("2.nData[%d]:%d\n", &nData, nData);
	printf("2.pData[%d]:%d\n", *pData, pData);
	//*pData�� ���� �����ϸ� nData�� �������� ���´�
	//->�����͸� ���ؼ� ������ �������� �����Ҽ��ִ�.
	*pData = 30;
	printf("3.nData[%d]:%d\n", &nData, nData);
	printf("3.pData[%d]:%d\n", *pData, pData);
	//�����Ϳ���: �������ǰ��� �����ø� ������Ÿ���� ũ�⸸ŭ ����/�����Ѵ�.
	//���� �����ϸ� �����Ͱ��� �����Ⱚ�� ������ �������� �ּҰ��� 4�� �����Ѵ�.
	pData++;
	printf("4.nData[%d]:%d\n", &nData, nData);
	printf("4.pData[%d]:%d\n", *pData, pData);
	//���� �����ϸ� �ּҰ��� 4�����ϹǷ�, nData�� �ּҰ��̹Ƿ�, nData�� ������ �ִ� �� 30�� ���´�.
	pData--;
	printf("5.nData[%d]:%d\n", &nData, nData);
	printf("5.pData[%d]:%d\n", *pData, pData);
}
//������ ���� �ڵ带 ���� �ڷḦ ���� �ڵ带 �ۼ��غ���.
void SwapVal(int a, int b)
{
	printf("SwapVal[%d]%d<->[%d]:%d\n",&a,a,&b,b);
	int temp = a;
	a = b;
	b = temp;
}

void SwapPtr(int* a, int* b)
{
	printf("SwapPtr[%d]%d<->[%d]:%d\n", *a, a, *b, b);
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapRef(int& a, int& b)
{
	printf("SwapRef[%d]%d<->[%d]:%d\n", &a, a, &b, a);
	int temp = a;
	a = b;
	b = temp;
}

void FunctionAndPointerMain()
{
	int nDataA = 10;
	int nDataB = 20;
	printf("Origin:[%d]%d<->[%d]%d\n",&nDataA,nDataA,&nDataB,nDataB);
	SwapVal(nDataA, nDataB);
	printf("SwapVal:[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
	SwapPtr(&nDataA, &nDataB);
	printf("SwapPtr:[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
	SwapRef(nDataA, nDataB);
	printf("SwapRef:[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
}

void ArrayAndPointerMain()
{
	const int nSize = 3;//�迭��ũ��� �ݵ�� ����� �����ؾ��Ѵ�.
	int arrScore[nSize];
	int nMemorySize = sizeof(arrScore);
	int nArraySize = nMemorySize / sizeof(arrScore[0]);
	printf("MemorySize:%d\n", nMemorySize);
	printf("MemoryArray:%d\n", nArraySize);
	printf("arrScore[%d]:%d\n", &arrScore, arrScore);
	for (int i = 0; i < nSize; i++)
		arrScore[i] = 100 - (i * 10);
	printf("Score:");
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", &arrScore[i],i, arrScore[i]);
	printf("\n");

	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", arrScore+i, i, *(arrScore+i));
	printf("\n");
	int* pScore = arrScore;
	for (int i = 0; i < nSize; i++)
	{
		printf("[%d/%d]%d,", pScore, i, *pScore);
		pScore++;
	}
	printf("\n");

	int arrCopyScore[nSize];
	printf("Score/CopyScore: %d/%d\n",
		arrCopyScore, arrScore);
	//arrCopyScore = arrScore; //�����Ѵٰ��ؼ� �����������.
	for (int i = 0; i < nSize; i++)
	{
		arrCopyScore[i] = arrScore[i];
	}
	memcpy(arrCopyScore, arrScore, sizeof(arrScore));
	printf("CopyScore:");
	for (int i = 0; i < nSize; i++)
		printf("[%d]%d,", i, arrCopyScore[i]);
	printf("\n");
}

void main()
{
	//ArrayTestMain();
	//PointerMain();
	//FunctionAndPointerMain();
	ArrayAndPointerMain();
}