#include <stdio.h>

void StringTestMain()
{
	const int nSize = 4;
	char strMsg[nSize];

	strMsg[0] = 'a';
	strMsg[1] = 'b';
	strMsg[2] = 'c';
	//strMsg[3] = '\0';//널문자: 문자열끝을 알리기위해서

	int nIdx = 0;
	printf("while:");
	while (strMsg[nIdx] != '\0')
	{
		printf("%c",strMsg[nIdx]);
		nIdx++;
	}
	printf("\n");
	printf("Idx:%d\n",nIdx);

	printf("string:%s",strMsg);
}

void InputIDMain()
{
	const int SIZE = 24;
	char strID[SIZE];
	printf("InputID:");
	scanf("%s", strID);
	int nSize = 0;
	while (strID[nSize] != '\0')
	{
		printf("[%d]:%c\n", nSize, strID[nSize]);
		nSize++;
	}

	printf("[%d/%d]%s",nSize,SIZE,strID);
}

void main()
{
	//StringTestMain();
	InputIDMain();
}