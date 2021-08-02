#include <stdio.h>
#include <string.h>

void ArrayTestMain()
{
	const int nSize = 5;//배열의크기는 반드시 상수로 정의해야한다.
	int arrScore[nSize] = {90,80,70,60,50};
	int nMemorySize = sizeof(arrScore);
	int nArraySize = nMemorySize / sizeof(arrScore[0]);
	printf("MemorySize:%d\n",nMemorySize);
	printf("MemoryArray:%d\n", nArraySize);
	//arrScore[0] = 100; //0:첫번째원소
	//arrScore[1] = 90;
	//arrScore[2] = 80;
	//arrScore[3] = 70;
	//arrScore[4] = 60; //n-1:마지막원소
	printf("Score:");
	for (int i = 0; i < nSize; i++)
		printf("[%d]%d,",i,arrScore[i]);
	printf("\n");

	int arrCopyScore[nSize];
	printf("Score/CopyScore: %d/%d\n", 
		arrCopyScore,arrScore);
	//arrCopyScore = arrScore; //대입한다고해서 복사되지않음.
	for (int i = 0; i < nSize; i++)
	{
		arrCopyScore[i] = arrScore[i];
	}
	printf("CopyScore:");
	for (int i = 0; i < nSize; i++)
		printf("[%d]%d,", i, arrCopyScore[i]);
	printf("\n");
}
//배열에서 최소값을 찾아서 출력하라.
//(최소값, 배열내에서 가장 작은 값을 찾는것)
//데이터: 30,40,50,10,20, 최소값을 검사하기위해 저장할 변수
//알고리즘: 
//모든배열의 값을 비교해서 가장 작은 값이 무엇인지 찾는다.
//첫번째값을 저장하고, 저장된값보다 다음 값이 작으면 값을 최소값으로 교채한다.
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
//포인터: 주소값을 저장하는 변수
//&:변수에 주소값을 가져오는 연산자.
//*:포인터가 가지고 있는 주소의 메모리에 있는 데이터값.
void PointerMain()
{
	int nData = 10;
	int* pData = &nData;
	printf("1.nData[%d]:%d\n",&nData,nData);
	printf("1.pData[%d]:%d\n", *pData, pData);
	//nData의 값을 변경하면 *pData의 같은값이나온다 
	//->포인터는 원본메모리의 값에 접근할수있다.
	nData = 20;
	printf("2.nData[%d]:%d\n", &nData, nData);
	printf("2.pData[%d]:%d\n", *pData, pData);
	//*pData의 값을 변경하면 nData에 같은값이 나온다
	//->포인터를 통해서 원본의 변수값을 변경할수있다.
	*pData = 30;
	printf("3.nData[%d]:%d\n", &nData, nData);
	printf("3.pData[%d]:%d\n", *pData, pData);
	//포인터연산: 포인터의값을 증가시면 변수의타입의 크기만큼 증가/감소한다.
	//값이 증가하면 데이터값은 쓰레기값이 나오고 포인터의 주소값은 4가 증가한다.
	pData++;
	printf("4.nData[%d]:%d\n", &nData, nData);
	printf("4.pData[%d]:%d\n", *pData, pData);
	//값이 감소하면 주소값이 4감소하므로, nData의 주소값이므로, nData가 가지고 있는 값 30이 나온다.
	pData--;
	printf("5.nData[%d]:%d\n", &nData, nData);
	printf("5.pData[%d]:%d\n", *pData, pData);
}
//다음과 같이 코드를 다음 자료를 보고 코드를 작성해보자.
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
	const int nSize = 3;//배열의크기는 반드시 상수로 정의해야한다.
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
	//arrCopyScore = arrScore; //대입한다고해서 복사되지않음.
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