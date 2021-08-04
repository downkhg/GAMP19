#include <stdio.h>
#include <string.h>

void StringTestMain()
{
	const int nSize = 4;
	char strMsg[nSize] = "abc";//문자열초기화시 마지막에 널문자가 포함된다.

	/*strMsg[0] = 'a';
	strMsg[1] = 'b';
	strMsg[2] = 'c';*/
	//strMsg[3] = '\0';//널문자: 문자열끝을 알리기위해서
	printf("for:");
	for (int i = 0; i < nSize; i++)
		printf("%c",strMsg[i]);
	printf("\n");

	int nIdx = 0;
	printf("while:");
	while (strMsg[nIdx] != '\0')
	{
		printf("%c",strMsg[nIdx]);
		nIdx++;
	}
	printf("\n");
	printf("Idx:%d\n",nIdx);

	printf("string:%s\n",strMsg);
}
//1.문자열은 왜 &이 없이 입력이 가능할까? 배열의이름은 주소값을 가지므로, 
//2.문자열은 왜 널문자('\0')이 필요할까? 준비해놓은 메모리에서필요한만큼만 보여주기위해서.
//3.ID를 입력받을때 글자수가 제한되어있는 이유는 무엇일까?
void InputIDMain()
{
	const int SIZE = 24;
	char strID[SIZE];
	printf("InputID:");
	scanf("%s", strID);
	int nSize = 0;
	printf("for:");
	for (int i = 0; i < SIZE; i++)
		printf("%c", strID[i]);
	printf("\n");

	while (strID[nSize] != '\0')
	{
		printf("[%d]:%c\n", nSize, strID[nSize]);
		nSize++;
	}
	printf("[%d/%d]%s",nSize,SIZE,strID);
}

void FullNameMain()
{
	char strFistName[128]; //이름
	char strLastName[128]; //성
	char strFullName[256];

	strcpy(strFistName, "hg");
	strcpy(strLastName, "k");

	//strcat(strFullName, strFistName);
	//strcat(strFullName, strLastName);

	sprintf(strFullName,"%s %s",strFistName, strLastName);

	printf("FullName:%s\n",strFullName);
}
//1.반복문사용해서 만들기
//2.반복문을 사용하지않고 문자열라이브러리 이용하여 만들기
void main()
{
	//StringTestMain();
	//InputIDMain();
	FullNameMain();
}