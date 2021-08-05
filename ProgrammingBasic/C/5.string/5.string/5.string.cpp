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

	if (strcmp(strFistName, strLastName) == 0)
		printf("%s == %s", strFistName, strLastName);
	else
		printf("%s != %s", strFistName, strLastName);
}
//1.반복문사용해서 만들기
//2.반복문을 사용하지않고 문자열라이브러리 이용하여 만들기
//정답:GAME
//Q:____
//A:A
//Q:_A__
//A:E
//Q:_A_E
//......
//A:G
//Q:GAME
//데이터: 정답(문자열),입력값(문자),빈(문자열)
//알고리즘: 정답에 입력값이 있다면, (????:빈문자열)에 해당문자열을 보여준다.
//정답안에 입력값이 있다? -> 찾기: 문자열을 모두 확인하고 입력문자열이 있는지 확인한다.
//정답과 빈문자열이 같다-> 문자열을 모두 비교해서 모든 값이 같으면 같다.  
void HangManGame()
{
	char strAnswer[24] = "GAME";
	char cInput;
	char strEmpty[24] = "____";
	while (true)
	{
		printf("Q:%s\n", strEmpty);
		scanf("%c", &cInput);
		int idx = 0;
		int nResultIdx = -1;
		while ('\0' != strAnswer[idx])
		{
			if (cInput == strAnswer[idx])
			{
				nResultIdx = idx;
				printf("Find %c is %d\n", cInput, idx);
				break;
			}
			idx++;
		}
		if (nResultIdx > -1)
		{
			strEmpty[nResultIdx] = cInput;
			printf("Q:%s\n", strEmpty);
		}
		else
			printf("%c is not found!\n", cInput);
		int nMachCount = 0;
		int nCount = 0;
		for (idx = 0; strAnswer[idx] != '\0'; idx++)
		{
			if (strAnswer[idx] == strEmpty[idx]) nMachCount++;
			nCount++;
		}
		if (nCount == nMachCount)
			break;
	}
}

void main()
{
	//StringTestMain();
	//InputIDMain();
	//FullNameMain();
	HangManGame();
}