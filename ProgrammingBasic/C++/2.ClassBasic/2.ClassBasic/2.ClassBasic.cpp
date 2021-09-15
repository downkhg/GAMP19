#include <iostream>
#include <string>
using namespace std;
//�߻�ȭ: ���� ��ü�� ���� Ŭ������ ����� ����.
//����: �Ӽ�-����, ����-�ѱ�/����
//�ڵ���: �Ӽ�-�ӵ�,���,���� ����-����,�극��ũ,����
class CCar
{
public:
	enum E_GEAR { P, R, N, D, ONE, TWO };
private:
	string m_strColor;
	int m_nSpeed;
	E_GEAR m_eGear;
	//������: �޸𸮰� �Ҵ�ɶ� ȣ��Ǵ� �Լ�. 
	//CCar()//�⺻������: �Ű������� ���� ������. ��ü�� �Ű������� ���������ʰ� �����Ҷ��� �ݵ�� �ʿ��ϴ�.
	//{
	//	m_strColor = "gray";
	//	m_nSpeed = 0;
	//	m_eGear = E_GEAR::N;
	//}
public:
	//Setter: ��������� ���� �����ϴ� �Լ�
	string GetColor() { return m_strColor; } //�ڵ����� ������ ��������������, �����ϴ� ���� �ҹ��̴�.
	//����Ʈ�Ű����������� �̿��Ͽ� ����Ʈ�����ڿ� ���� ������ �ϵ����Ҽ��ִ�.
	CCar(string color = "gray", E_GEAR gear = E_GEAR::N, int speed = 0)//�Ű��������ִ� ������: �Ű������� �����ϸ�, �ݵ�� �ʱ�ȭ�ؾ߸� �޸𸮸� �Ҵ�ǰ� ������ִ�.
	{
		cout << "CCar[" << this << "]:" << color << endl;
		m_strColor = color;
		m_eGear = gear;
		m_nSpeed = speed;
	}
	//�Ҹ���: �Ҵ�� �޸𸮰� �Ҹ�ɶ� ȣ��Ǵ� �Լ�
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
	void SetGear(E_GEAR gear)
	{
		m_eGear = gear;
	}
	void Display()
	{
		cout << "#### " << m_strColor << " ####" << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_eGear << endl;
	}
};

void CarTestMain()
{
	cout << "CarTestMain() start" << endl;
	//��ü�� �޸��Ҵ�
	CCar cCar("red",CCar::E_GEAR::N,0); 
	CCar arrCar[3];
	//���е� ������ ������� �����Ҽ�����.
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
	CarTestMain();
	cout << "main() end" << endl;
}