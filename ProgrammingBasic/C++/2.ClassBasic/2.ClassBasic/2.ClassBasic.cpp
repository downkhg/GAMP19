#include <iostream>
#include <string>
using namespace std;
//�߻�ȭ: ���� ��ü�� ���� Ŭ������ ����� ����.
//����: �Ӽ�-����, ����-�ѱ�/����
//�ڵ���: �Ӽ�-�ӵ�,���,���� ����-����,�극��ũ,����
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