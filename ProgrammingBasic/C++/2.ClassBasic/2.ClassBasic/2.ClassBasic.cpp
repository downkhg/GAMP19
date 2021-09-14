#include <iostream>
#include <string>
using namespace std;
//추상화: 실제 물체를 보고 클래스로 만드는 과정.
//전구: 속성-전원, 동작-켜기/끄기
//자동자: 속성-속도,기어,색상 동작-엑셀,브레이크,기어변경
class CCar
{
	enum E_GEAR { P, R, N, D, ONE, TWO };

	string m_strColor;
	int m_nSpeed;
	E_GEAR m_eGear;

	void Accel()
	{
		m_nSpeed++;
	}
	void Break()
	{
		m_nSpeed--;
	}
	void SetGear(E_GEAR gear)
	{
		m_eGear = gear;
	}
};

void CarTestMain()
{

}

void main()
{
	CarTestMain();
}