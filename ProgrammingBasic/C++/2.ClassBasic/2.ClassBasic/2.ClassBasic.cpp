#include <iostream>
#include <string>
using namespace std;
//추상화: 실제 물체를 보고 클래스로 만드는 과정.
//전구: 속성-전원, 동작-켜기/끄기
//자동자: 속성-속도,기어,색상 동작-엑셀,브레이크,기어변경
//강아지(육성/전투): 속성-나이,체력,배고픔,크기,호감도,청결도,지능,호전도/체력,공격력,방어력,경험치,레벨  동작-생일,놀기,먹기,목욕,훈련/공격,렙업
//생명체는 어떻게 보느냐에 따라 추상화가 달라질수있다. 이것은 게임의 기획과도 유사하다.
class CCar
{
public:
	enum E_GEAR { P, R, N, D, ONE, TWO };
private:
	string m_strColor;
	int m_nSpeed;
	E_GEAR m_eGear;
	//정적멤버 변수의 선언
	//객체가 생성되기전에 접근가능 멤버변수. 모든객체가 공유한다.
	static int m_nCount; //자동차 생산 수
	//생성자: 메모리가 할당될때 호출되는 함수. 
	//CCar()//기본생성자: 매개변수가 없는 생성자. 객체의 매개변수를 지정하지않고 생성할때는 반드시 필요하다.
	//{
	//	m_strColor = "gray";
	//	m_nSpeed = 0;
	//	m_eGear = E_GEAR::N;
	//}
public:
	//객체가 생성되기전에 접근가능한 멤버 함수
	static int GetCount() { return m_nCount; }
	//Getter: 멤버변수의 값을 가져오는 함수
	string GetColor() { return m_strColor; } //자동차의 색상은 관찰가능하지만, 변경하는 것은 불법이다.
	int GetSpeed() { return m_nSpeed; } //속도는 누구나 관찰 할 수 있다.
	//Setter: 멤버변수의 값을 설정하는 함수
	void SetColor(string color) { m_strColor = color; } //자동차의 색깔을 내가 원한다면 바꿀수있다.
	void SetGear(E_GEAR gear){ m_eGear = gear; }
	//void SetSpeed(int speed) { m_nSpeed = speed; } //물리법칙상 속도는 임의로 변경이 불가능하다. 그러므로 변경할수없다.
	//생성자: 객체가 생성(메모리할당)될때 호출되는 함수.
	//디폴트매개변수변수를 이용하여 디폴트생성자와 같은 역할을 하도록할수있다.
	CCar(string color = "gray", E_GEAR gear = E_GEAR::N, int speed = 0)//매개변수가있는 생성자: 매개변수를 지정하면, 반드시 초기화해야만 메모리를 할당되게 만들수있다.
	{
		m_nCount++;
		cout << "CCar[" << this << "/"<<m_nCount<<"]:" << color << endl;
		m_strColor = color;
		m_eGear = gear;
		m_nSpeed = speed;
	}
	//복사생성자: 객체가 초기화될때 같은 객체를 복사하면 호출되는 함수 
	CCar(CCar& car)
	{
		m_nCount++;
		//memcpy_s(this, sizeof(CCar), &car, sizeof(CCar)); //일부 컴퓨터에서 문제가 발생
		m_strColor = car.m_strColor;
		m_nSpeed = car.m_nSpeed;
		m_eGear = car.m_eGear;
		cout << "Car Copy[" << this << "/" << m_nCount << "]:" << m_strColor << endl;
	}
	//소멸자: 할당된 메모리가 소멸될때 호출되는 함수
	~CCar()
	{
		m_nCount--;
		cout << "~CCar[" << this << "/" << m_nCount << "]:" << m_strColor << endl;
	}
	void Accel()
	{
		m_nSpeed++;
	}
	void Break()
	{
		m_nSpeed--;
	}
	//이 함수가 없다면, 계기판이 없는 자동차
	//추상화와 상관없이 필요하다면 기능을 추가해야한다.
	void Display()
	{
		cout << "#### " << m_strColor << " ####" << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_eGear << endl;
	}
};
//전역변수는 언제 소멸되는가?
//1.프로그램 종료시
//2.함수 종료시
// 
//정적멤버변수는 모든객체가 공유해야하기때문에 전역변수로 만든다.
int CCar::m_nCount = 0; //정적멤버변수의 정의

void SwapCarVal(CCar a, CCar b)
{
	cout << "##### SwapCarVal ####" << endl;
	CCar temp = a;
	a = b;
	b = temp;
}

void SwapCarRef(CCar& a, CCar& b)
{
	cout << "##### SwapCarRef ####" << endl;
	CCar temp = a;
	a = b;
	b = temp;
}

void SwapTestMain()
{
	cout << "##### SwapTestMain() start #####" << endl;
	CCar cCarA("red");
	CCar cCarB("blue");
	cout << "##### Origin #####" << endl;
	cCarA.Display();
	cCarB.Display();
	cout << "##### SwapVal #####" << endl;
	SwapCarVal(cCarA, cCarB);
	cCarA.Display();
	cCarB.Display();
	cout << "##### SwapRef #####" << endl;
	SwapCarRef(cCarA, cCarB);
	cCarA.Display();
	cCarB.Display();
	cout << "##### SwapTestMain() end #####" << endl;
}

void CarTestMain()
{
	cout << "CarTestMain() start" << endl;
	//객체의 메모리할당
	CCar cCar("red",CCar::E_GEAR::N,0); 
	CCar arrCar[3];
	CCar* pCar = NULL;//포인터는 실체가 없다.
	cout << "Dynamic Alloclate!" << endl;
	pCar = new CCar("blue");//동적할당된 메모리를 포인터가 가르킨다.(참조)
	//delete pCar;
	//은닉된 변수는 마음대로 변경할수없다.
	/*cCar.m_strColor = "green";
	cCar.m_eGear = CCar::E_GEAR::N;
	cCar.m_nSpeed = 0;*/
	cCar.Accel();
	cCar.Display();
	cout << "CarTestMain() end" << endl;
}
//물건을 주문하고 받는다.
//1.매장을 방문하고 시승을한다.
//2.계약서를 작성한다.
//3.공장에서 자동차를 생산한다.
//4.자동차를 출고받는다.
//5.자동차를 운행한다.
void BuyCarMain()
{
	string strInputColor;
	cout << "Color? ";
	cin >> strInputColor;
	cout << "### Production Car ###" << endl;
	CCar cCar(strInputColor);
	cout << "### Deliver a Car ###" << endl;

	int nControl;
	do
	{
		cout << "ControlCar(0: Gear 1: Aceel 2: Break):";
		cin >> nControl;
		switch (nControl)
		{
		case 0: //기어조작
			int nGear;
			cout << "SetGear" << endl;
			cin >> nGear;
			cCar.SetGear((CCar::E_GEAR)nGear);
			break;
		case 1: //가속
			cCar.Accel();
			break;
		case 2: //브레이크
			cCar.Break();
			break;
		default:
			nControl = -1;
			break;
		}
		cCar.Display();
	} 	while (nControl != -1);
}

void main()
{
	cout << "main() start" << endl;
	cout << "Car:" << CCar::GetCount() << endl;
	//CarTestMain();
	SwapTestMain();
	cout << "Car:" << CCar::GetCount() << endl;
	cout << "main() end" << endl;
}