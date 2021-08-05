#include <stdio.h>
#include <string.h>

void StringTestMain()
{
	const int nSize = 4;
	char strMsg[nSize] = "abc";//���ڿ��ʱ�ȭ�� �������� �ι��ڰ� ���Եȴ�.

	/*strMsg[0] = 'a';
	strMsg[1] = 'b';
	strMsg[2] = 'c';*/
	//strMsg[3] = '\0';//�ι���: ���ڿ����� �˸������ؼ�
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
//1.���ڿ��� �� &�� ���� �Է��� �����ұ�? �迭���̸��� �ּҰ��� �����Ƿ�, 
//2.���ڿ��� �� �ι���('\0')�� �ʿ��ұ�? �غ��س��� �޸𸮿����ʿ��Ѹ�ŭ�� �����ֱ����ؼ�.
//3.ID�� �Է¹����� ���ڼ��� ���ѵǾ��ִ� ������ �����ϱ�?
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
	char strFistName[128]; //�̸�
	char strLastName[128]; //��
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
//1.�ݺ�������ؼ� �����
//2.�ݺ����� ��������ʰ� ���ڿ����̺귯�� �̿��Ͽ� �����
//����:GAME
//Q:____
//A:A
//Q:_A__
//A:E
//Q:_A_E
//......
//A:G
//Q:GAME
//������: ����(���ڿ�),�Է°�(����),��(���ڿ�)
//�˰���: ���信 �Է°��� �ִٸ�, (????:���ڿ�)�� �ش繮�ڿ��� �����ش�.
//����ȿ� �Է°��� �ִ�? -> ã��: ���ڿ��� ��� Ȯ���ϰ� �Է¹��ڿ��� �ִ��� Ȯ���Ѵ�.
//����� ���ڿ��� ����-> ���ڿ��� ��� ���ؼ� ��� ���� ������ ����.  
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