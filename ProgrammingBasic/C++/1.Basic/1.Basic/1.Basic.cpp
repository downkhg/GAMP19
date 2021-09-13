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

void main()
{
	//std::c
	//NamespaceTestMain();
	SumTestMain();
	cout << "Hello Wolrd!" << std::endl;//\n:줄바꿈문자
}