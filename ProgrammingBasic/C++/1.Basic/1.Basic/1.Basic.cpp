#include <iostream>//stdio.h

using namespace std; //표준

namespace  A
{
	int g_nData;
	void PrintData() { cout << "Print:"<< g_nData << endl; }
}

namespace  B
{
	int g_nData;
	void PrintData() { cout << "Print:" << g_nData << endl; }
}

using namespace A;
//using namespace B;

void NamespaceTestMain()
{
	g_nData = 10;
	PrintData();

	B::g_nData = 20;
	B::PrintData();
}
//함수의 오버로딩: 같은이름으로 여러함수를 정의하는것.
//int Sum(int a, int b, int c) { return a + b + c; }
//int Sum(int a, int b) { return a + b; }
//디폴트매개변수: 매개변수의 값을 지정하지않으면 지정값이 변수에 할당된다.
int Sum(int a, int b = 0, int c = 0) { return a + b + c; }

void SumTestMain()
{
	cout << "Sum3:" << Sum(10, 20, 30) << endl;
	cout << "Sum2:" << Sum(10, 20) << endl;
	cout << "Sum1:" << Sum(10) << endl;
}

void RefTestMain()
{
	int nData = 10;
	int& refData = nData; //참조를 반드시 해야한다.
	cout << "1.nData:" << nData << endl;
	cout << "1.refData:" << refData << endl;
	nData = 20;
	cout << "2.nData:" << nData << endl;
	cout << "2.refData:" << refData << endl;
	refData = 30;
	cout << "3.nData:" << nData << endl;
	cout << "3.refData:" << refData << endl;
}
void StringTestMain()
{
	string strFirstName;
	string strLastName;
	string strFullName;
	strFirstName = "hg";
	strLastName = "k";
	strFullName = strFirstName + strLastName;
	cout << strFullName <<  endl;
}
void ChararrayTestMain()
{
	const int SIZE = 128;
	char strFirstName[SIZE];
	char strLastName[SIZE];
	char strFullName[SIZE] = "";
	strcpy_s(strLastName, "hg");
	strcpy_s(strFirstName, "k");
	strcat_s(strFullName, strLastName);
	strcat_s(strFullName, strFirstName);
	cout << strFullName;
}
//단어맞추기게임
//1.문자열객체를 이용하고, 배열처럼 처리한다.
//2.문자열의 함수를 이용하여 처리하는 방법.
void HangManMain()
{
	string strAnswer = "GAME";
	char cInput;
	string strEmpty = "____";
	while (true)
	{
		printf("Q:%s\n", strEmpty.c_str());
		scanf("%c", &cInput);
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
		/*int nMachCount = 0;
		int nCount = 0;
		for (idx = 0; strAnswer[idx] != '\0'; idx++)
		{
			if (strAnswer[idx] == strEmpty[idx]) nMachCount++;
			nCount++;
		}
		if (nCount == nMachCount)
			break;*/
	}
}
void main()
{
	//std::c
	//NamespaceTestMain();
	//SumTestMain();
	//cout << "Hello Wolrd!" << std::endl;//\n:줄바꿈문자
	//RefTestMain();
	//StringTestMain();
	//ChararrayTestMain();
	HangManMain();
}