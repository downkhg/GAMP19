#include <iostream>
using namespace std;
class SingleObject
{
	static SingleObject* m_pInstance; //모든객체가 공유한다.
	SingleObject() { cout << "SingleObject:" << this << endl; }
	int m_nData;
public:
	
	~SingleObject() { cout << "~SingleObject:" << this << endl; }
	static SingleObject* GetInstance()
	{
		cout << "GetInstance Start:" << endl;
		if(m_pInstance == NULL)
			m_pInstance = new SingleObject();
		cout << "GetInstance End:" << endl;
		return m_pInstance;
	}
	void ShowMessage()
	{
		cout << this << " SingleObject ShowMSG["<<&m_nData<<"]:"<< m_nData << endl;
	}
	void Release()
	{
		delete m_pInstance;
	}
};

class Program
{
public:
	static void main()
	{
		//객체를 알지못해도 필요할때 불러내어 사용가능하다.
		cout << SingleObject::GetInstance() << endl;
	}
};

SingleObject* SingleObject::m_pInstance;//정적멤버변수는 전역변수와 같이 선언한다.

//싱글톤: 클래스의 인스턴스가 1개이상 존재 할수없는 클래스를 만드는 기법.(생성자 은닉,정적멤버)
int main()
{
	//SingleObject cSingleObject[3]; //외부에서 객체를 생성하면 다음과 같이 객체가 1개이상 만들어질가능성이 있다.

	SingleObject* pSingleObjectA = NULL;
	SingleObject* pArrSingleObjects[2] = {};
	
	pSingleObjectA = SingleObject::GetInstance();
	pSingleObjectA->ShowMessage();
	for (int i = 0; i < 2; i++)
		pArrSingleObjects[i] = SingleObject::GetInstance();

	cout << "pSingleObjectA:" << pSingleObjectA << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "pSingleObject[" << i << "]:" << pArrSingleObjects[i] << endl;
		pArrSingleObjects[i]->ShowMessage();
	}
	//인스턴스가 1개이므로 굳이 여러번 불러줄필요는 없다.
	pSingleObjectA->Release();

	Program::main();
}