#include <iostream>
#include <string>
using namespace std;
//추상화: 실제 물체를 보고 클래스로 만드는 과정.
//전구: 속성-전원, 동작-켜기/끄기
//자동자: 속성-속도,기어,색상 동작-엑셀,브레이크,기어변경
class CCar
{
public:
	enum E_GEAR { P, R, N, D, ONE, TWO };
private:
	string m_strColor;
	int m_nSpeed;
	E_GEAR m_eGear;
	//생성자: 메모리가 할당될때 호출되는 함수. 
	//CCar()//기본생성자: 매개변수가 없는 생성자. 객체의 매개변수를 지정하지않고 생성할때는 반드시 필요하다.
	//{
	//	m_strColor = "gray";
	//	m_nSpeed = 0;
	//	m_eGear = E_GEAR::N;
	//}
public:
	//Getter: 멤버변수의 값을 가져오는 함수
	string GetColor() { return m_strColor; } //자동차의 색상은 관찰가능하지만, 변경하는 것은 불법이다.
	int GetSpeed() { return m_nSpeed; } //속도는 누구나 관찰 할 수 있다.
	//Setter: 멤버변수의 값을 설정하는 함수
	void SetColor(string color) { m_strColor = color; } //자동차의 색깔을 내가 원한다면 바꿀수있다.
	void SetGear(E_GEAR gear){ m_eGear = gear; }
	//void SetSpeed(int speed) { m_nSpeed = speed; } //물리법칙상 속도는 임의로 변경이 불가능하다. 그러므로 변경할수없다.
	//디폴트매개변수변수를 이용하여 디폴트생성자와 같은 역할을 하도록할수있다.
	CCar(string color = "gray", E_GEAR gear = E_GEAR::N, int speed = 0)//매개변수가있는 생성자: 매개변수를 지정하면, 반드시 초기화해야만 메모리를 할당되게 만들수있다.
	{
		cout << "CCar[" << this << "]:" << color << endl;
		m_strColor = color;
		m_eGear = gear;
		m_nSpeed = speed;
	}
	//복사생성자: 객체가 초기화될때 같은 객체를 복사하면 호출되는 함수 
	CCar(CCar& car)
	{
		memcpy_s(this, sizeof(CCar), &car, sizeof(CCar));
		cout << "Car Copy[" << this << "]:" << m_strColor << endl;
	}
	//소멸자: 할당된 메모리가 소멸될때 호출되는 함수
	~CCar()
	{
		cout << "~CCar[" << this << "]:" << m_strColor << endl;
	}
	void Accel()
	{
		m_nSpeed++;
	}
	void Break()
	{
		m_nSpeed--;
	}
	
	void Display()
	{
		cout << "#### " << m_strColor << " ####" << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_eGear << endl;
	}
};

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

void main()
{
	cout << "main() start" << endl;
	//CarTestMain();
	SwapTestMain();
	cout << "main() end" << endl;
}