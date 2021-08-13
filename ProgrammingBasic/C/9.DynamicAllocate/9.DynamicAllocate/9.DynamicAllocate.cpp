#include <stdio.h>
#include <stdlib.h>
//동적할당: 프로그램 실행중에 메모리를 할당하는 것. 삭제도 직접해야한다. -> 메모리누수(leak):삭제하지않으면 메모리가 남는다.
//정적할당: 프로그램 실행전에 메모리가 할당되는 것. 지역변수,전역변수 -> 컴파일단계에 결정됨.
//void포인터: 형태를 알수없는 주소를 저장하는 포인터.
//다른언어에는 가지비컬렉터를 이용하여 동적할당된 메모리를 관리한다.
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