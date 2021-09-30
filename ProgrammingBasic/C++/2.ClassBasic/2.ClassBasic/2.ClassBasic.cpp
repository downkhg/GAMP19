#include <iostream>
#include <string>
using namespace std;
//�߻�ȭ: ���� ��ü�� ���� Ŭ������ ����� ����.
//����: �Ӽ�-����, ����-�ѱ�/����
//�ڵ���: �Ӽ�-�ӵ�,���,���� ����-����,�극��ũ,����
//������(����/����): �Ӽ�-����,ü��,�����,ũ��,ȣ����,û�ᵵ,����,ȣ����/ü��,���ݷ�,����,����ġ,����  ����-����,���,�Ա�,���,�Ʒ�/����,����
//����ü�� ��� �����Ŀ� ���� �߻�ȭ�� �޶������ִ�. �̰��� ������ ��ȹ���� �����ϴ�.
class CCar
{
public:
	enum E_GEAR { P, R, N, D, ONE, TWO };
private:
	string m_strColor;
	int m_nSpeed;
	E_GEAR m_eGear;
	//������� ������ ����
	//��ü�� �����Ǳ����� ���ٰ��� �������. ��簴ü�� �����Ѵ�.
	static int m_nCount; //�ڵ��� ���� ��
	//������: �޸𸮰� �Ҵ�ɶ� ȣ��Ǵ� �Լ�. 
	//CCar()//�⺻������: �Ű������� ���� ������. ��ü�� �Ű������� ���������ʰ� �����Ҷ��� �ݵ�� �ʿ��ϴ�.
	//{
	//	m_strColor = "gray";
	//	m_nSpeed = 0;
	//	m_eGear = E_GEAR::N;
	//}
public:
	//��ü�� �����Ǳ����� ���ٰ����� ��� �Լ�
	static int GetCount() { return m_nCount; }
	//Getter: ��������� ���� �������� �Լ�
	string GetColor() { return m_strColor; } //�ڵ����� ������ ��������������, �����ϴ� ���� �ҹ��̴�.
	int GetSpeed() { return m_nSpeed; } //�ӵ��� ������ ���� �� �� �ִ�.
	//Setter: ��������� ���� �����ϴ� �Լ�
	void SetColor(string color) { m_strColor = color; } //�ڵ����� ������ ���� ���Ѵٸ� �ٲܼ��ִ�.
	void SetGear(E_GEAR gear){ m_eGear = gear; }
	//void SetSpeed(int speed) { m_nSpeed = speed; } //������Ģ�� �ӵ��� ���Ƿ� ������ �Ұ����ϴ�. �׷��Ƿ� �����Ҽ�����.
	//������: ��ü�� ����(�޸��Ҵ�)�ɶ� ȣ��Ǵ� �Լ�.
	//����Ʈ�Ű����������� �̿��Ͽ� ����Ʈ�����ڿ� ���� ������ �ϵ����Ҽ��ִ�.
	CCar(string color = "gray", E_GEAR gear = E_GEAR::N, int speed = 0)//�Ű��������ִ� ������: �Ű������� �����ϸ�, �ݵ�� �ʱ�ȭ�ؾ߸� �޸𸮸� �Ҵ�ǰ� ������ִ�.
	{
		m_nCount++;
		cout << "CCar[" << this << "/"<<m_nCount<<"]:" << color << endl;
		m_strColor = color;
		m_eGear = gear;
		m_nSpeed = speed;
	}
	//���������: ��ü�� �ʱ�ȭ�ɶ� ���� ��ü�� �����ϸ� ȣ��Ǵ� �Լ� 
	CCar(CCar& car)
	{
		m_nCount++;
		//memcpy_s(this, sizeof(CCar), &car, sizeof(CCar)); //�Ϻ� ��ǻ�Ϳ��� ������ �߻�
		m_strColor = car.m_strColor;
		m_nSpeed = car.m_nSpeed;
		m_eGear = car.m_eGear;
		cout << "Car Copy[" << this << "/" << m_nCount << "]:" << m_strColor << endl;
	}
	//�Ҹ���: �Ҵ�� �޸𸮰� �Ҹ�ɶ� ȣ��Ǵ� �Լ�
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
	//�� �Լ��� ���ٸ�, ������� ���� �ڵ���
	//�߻�ȭ�� ������� �ʿ��ϴٸ� ����� �߰��ؾ��Ѵ�.
	void Display()
	{
		cout << "#### " << m_strColor << " ####" << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_eGear << endl;
	}
};
//���������� ���� �Ҹ�Ǵ°�?
//1.���α׷� �����
//2.�Լ� �����
// 
//������������� ��簴ü�� �����ؾ��ϱ⶧���� ���������� �����.
int CCar::m_nCount = 0; //������������� ����

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
	//��ü�� �޸��Ҵ�
	CCar cCar("red",CCar::E_GEAR::N,0); 
	CCar arrCar[3];
	CCar* pCar = NULL;//�����ʹ� ��ü�� ����.
	cout << "Dynamic Alloclate!" << endl;
	pCar = new CCar("blue");//�����Ҵ�� �޸𸮸� �����Ͱ� ����Ų��.(����)
	//delete pCar;
	//���е� ������ ������� �����Ҽ�����.
	/*cCar.m_strColor = "green";
	cCar.m_eGear = CCar::E_GEAR::N;
	cCar.m_nSpeed = 0;*/
	cCar.Accel();
	cCar.Display();
	cout << "CarTestMain() end" << endl;
}
//������ �ֹ��ϰ� �޴´�.
//1.������ �湮�ϰ� �ý����Ѵ�.
//2.��༭�� �ۼ��Ѵ�.
//3.���忡�� �ڵ����� �����Ѵ�.
//4.�ڵ����� ���޴´�.
//5.�ڵ����� �����Ѵ�.
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
		case 0: //�������
			int nGear;
			cout << "SetGear" << endl;
			cin >> nGear;
			cCar.SetGear((CCar::E_GEAR)nGear);
			break;
		case 1: //����
			cCar.Accel();
			break;
		case 2: //�극��ũ
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