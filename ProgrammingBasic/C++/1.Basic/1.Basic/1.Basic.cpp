#include <iostream>//stdio.h

using namespace std; //ǥ��

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
//�Լ��� �����ε�: �����̸����� �����Լ��� �����ϴ°�.
//int Sum(int a, int b, int c) { return a + b + c; }
//int Sum(int a, int b) { return a + b; }
//����Ʈ�Ű�����: �Ű������� ���� �������������� �������� ������ �Ҵ�ȴ�.
int Sum(int a, int b = 0, int c = 0) { return a + b + c; }

void SumTestMain()
{
	cout << "Sum3:" << Sum(10, 20, 30) << endl;
	cout << "Sum2:" << Sum(10, 20) << endl;
	cout << "Sum1:" << Sum(10) << endl;
}

void main()
{
	//std::c
	//NamespaceTestMain();
	SumTestMain();
	cout << "Hello Wolrd!" << std::endl;//\n:�ٹٲ޹���
}