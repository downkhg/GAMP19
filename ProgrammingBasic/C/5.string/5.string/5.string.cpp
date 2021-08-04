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
}
//1.�ݺ�������ؼ� �����
//2.�ݺ����� ��������ʰ� ���ڿ����̺귯�� �̿��Ͽ� �����
void main()
{
	//StringTestMain();
	//InputIDMain();
	FullNameMain();
}