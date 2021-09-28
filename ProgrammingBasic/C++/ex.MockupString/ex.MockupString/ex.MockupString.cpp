#include <iostream>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���

using namespace std;
//���ڿ� Ŭ������ Ȱ���غ���, �ش� �Լ��� ������ ������ �����ϰ� �׽�Ʈ�� �Ͽ�
//���������� �۵��ϴ���, Ȯ���غ���.
void STDStringMain()
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //������
	string strMsg2("DataTest"); //������
	string strCopyMsg = strMsg; //���������
	string strCopyMsg2;
	strCopyMsg2 = strMsg2; //���Կ�����

	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ� //Test
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str()); //0x01:Test
	cout << strMsg2.c_str() << endl; //DataTest
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str()); //0x02:DataTest
	printf("%d:%s\n", strCopyMsg.c_str(), strCopyMsg.c_str()); //0x03:Test
	printf("%d:%s\n", strCopyMsg2.c_str(), strCopyMsg2.c_str()); //0x04:DataTest
	cout << "##### STDStringMain End######" << endl;
}
//Find ���ϰ� 2 �Ű����� 1
//1.char 2.int 3.float
void STDStringHangManMain()
{
	string strAnswer = "GAME";
	char cInput;
	string strEmpty = "____";
	while (true)
	{
		printf("Q:%s\n", strEmpty.c_str());
		scanf_s("%c", &cInput);
		int idx = 0;
		int nResultIdx = strAnswer.find(cInput);
		if (nResultIdx > -1)
		{
			//strEmpty[nResultIdx] = cInput;
			string strTemp = strEmpty.replace(nResultIdx, 1, 1, cInput);
			printf("Q:%s\n", strEmpty.c_str());
		}
		else
			printf("%c is not found!\n", cInput);
		if (strEmpty == strAnswer)
			break;
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
//�Ű������� const�� ��������
//1.�ǹ̾��� 2. ���������ʰ��Ϸ��� 3.�����Ϸ���
//1.�ٲܼ����� 2.�����Ҽ��ִ�. 3.�ǹ̾���
namespace Mockup
{
	class string
	{
		char* pStr; //�����Ҵ�� ���ڿ��� �ּҸ� ������ ������
	public:
		string()
		{
			pStr = NULL;
		}
		//�����ڿ��� �����Ҵ�� �޸𸮴� ��ü�� �Ҹ�ɶ� ȣ��Ǿ���Ѵ�.
		string(const char* str)
		{
			int nSize = strlen(str) + 1;
			//�Ű������� ���� ���ڿ��� �����Ҵ�(���ڿ��� ���� +1 ��ŭ)�� ���ڿ��� �����Ϳ� �����ϰ�,
			pStr = new char[strlen(str) + 1];
			//�����Ҵ�ȸ޸𸮿� �Ű������� ���ڿ��� �����Ѵ�.
			strcpy_s(pStr, nSize, str);
			cout << "FakeString[" << this << "]:" << (int)pStr << endl;
		}
		string(string& str)
		{
			/*int nSize = strlen(str.pStr) + 1;
			pStr = new char[nSize];
			strcpy_s(pStr, nSize, str.pStr);*/
			pStr = str.pStr;
			cout << "FakeString Copy[" << this << "]:" << (int)pStr << endl;
		}
		//�����ڿ��� �����Ҵ��Ͽ����Ƿ� �ݵ�� �Ҹ��ڿ��� �����Ҵ�� ��ü�� �����Ѵ�.
		~string()
		{
			cout << "~FakeString[" << this << "]:" << (int)pStr << endl;
			delete[] pStr;
		}
		string operator=(const string str)
		{
			pStr = str.pStr;
			return *this;
		}
		int find(const char find)
		{
			return 0;
		}
		string& replace(int offset, int number, int count, int replace)
		{
			return *this;
		}
		const char* c_str()
		{
			return pStr;
		}
		bool operator==(const string& str)
		{
			return false;
		}
		char operator[](int idx)
		{
			return 0;
		}
		friend ostream& operator<< (ostream & os, const string & str)
		{
			return os << str.pStr;
		}
	};
}

void MockupStringMain()
{
	cout << "##### FakeStringMain Start ######" << endl;
	Mockup::string strMsg("Test"); //������
	Mockup::string strMsg2("DataTest"); //������
	Mockup::string strCopyMsg = strMsg; //���������
	Mockup::string strCopyMsg2;
	strCopyMsg2 = strMsg2; //���Կ�����

	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ� //Test
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str()); //0x01: Test
	cout << strMsg2.c_str() << endl; //DataTest
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str()); //0x02: DataTest
	cout << strCopyMsg.c_str() << endl; //0x01: Test
	printf("%d:%s\n", strCopyMsg.c_str(), strCopyMsg.c_str()); //0x01:Test -> 0x03:Test
	printf("%d:%s\n", strCopyMsg2.c_str(), strCopyMsg2.c_str()); //0x01:Test -> 0x03:Test
	cout << "##### FakeStringMain End######" << endl;
	cout << strMsg << endl;
}
//== ���ϰ�, [] �Ű����� 1
//1.int 2.bool 3.char
//== �Ű����� 3
//[] ���ϰ� 1
//1.char 2.char* 3.string
void MockupStringHangManMain()
{
	Mockup::string strAnswer = "GAME";
	char cInput;
	Mockup::string strEmpty = "____";
	while (true)
	{
		printf("Q:%s\n", strEmpty.c_str());
		scanf_s("%c", &cInput);
		int idx = 0;
		int nResultIdx = strAnswer.find(cInput);
		if (nResultIdx > -1)
		{
			//strEmpty[nResultIdx] = cInput;
			strEmpty.replace(nResultIdx, 1, 1, cInput);
			printf("Q:%s\n", strEmpty.c_str());
		}
		else
			printf("%c is not found!\n", cInput);
		if (strEmpty == strAnswer)
			break;
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
	//_CrtSetBreakAlloc(150); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	STDStringMain();
	MockupStringMain();
}