//��ó����: ���������� ó���ϴ� ��
#include <stdio.h>//ǥ������� ���̺귯��.
#define PI 3.141592

void HelloWorldMain()
{
	//����: ���������� �����ϸ� �����ϵǾ� ���������� ���������.
	//ctrl+F5: ����+����(����ž��� �����ϱ�)
	printf("Hello World!\n");//\n: �ٹٲ޹���.
	printf("khg\n");//;(�����ݷ�):���峡�� �ǹ���.
}

//���� ������ ���ϴ� ���α׷������(��, �������� �Է¹ް�, ���Ǹ����� ����Ѵ�.)
//������*������*3.14(PI) = ���Ǹ���
//������(���):������,PI,���Ǹ��� ->����: �����Ͱ� ����Ǵ� ����. ������Ÿ��: �����͸� �����ϴ� ���� ����:int, �Ǽ�:float
//�˰���(������):������*������*3.14(PI) = ���Ǹ���
void CircleAreaMain()
{
	//1.������ ������ �����ϰ�, ���� �ִ´�.
	//2.���̺����� �����ϰ�, 3.14 ���� �ִ´�.
	//3.���ǹ����� ������ �����ϰ�, ������*������*PI�� �� ����� �ִ´�.
	//4.���� ���̸� ����Ѵ�.
	float raduis = 1;
	const float pi = 3.14;
	//pi = 4;//�����Ϸ��� ���� �Ǽ��ϸ� �ϰ� �˷���.
	printf("Raduis:");
	scanf("%f", &raduis);//�Է½ÿ��� �������� &�� �پ���Ѵ�.
	//float area = raduis * raduis * pi;
	float area = raduis * raduis * PI;
	printf("Area:%f\n",area);
}
//�¾�������� �Ÿ��� x�ε� �̰Ÿ��� ���� �����Ϸ��� �ð��� �󸶳� �ɸ��°�.(��)
//���� �ӵ�: 30�� m/s 
//�¾���������̰Ÿ�: 14960�� m
//____________________________________
//_
//������: ���� �ӵ�, �¾���������̰Ÿ�, �ð�(��) -> ����: �����͸� �����ϴ� ���� -> Ÿ��,�̸�
//�˰���: �丷���(�¾���������ǰŸ�)/ª�������(���Ǽӵ�) = ���� -> �ð�
//�� -> �� = ��/60 = ��
void LightSpeedMain()
{
	int nLightSpeed = 30;
	int nDistance = 14960;

	int nSec = nDistance/ nLightSpeed;
	printf("%d s\n", nSec);
	printf("%d m\n", nSec/60);
	printf("%d m %d s\n", nSec / 60, nSec%60);
	int nMin = nSec / 60;
	printf("%d m %d s\n", nMin, nSec-(nMin*60));
}

void SizeMain()
{
	int x;

	printf("x:%d\n", sizeof(x));
	printf("char:%d\n", sizeof(char));
	printf("int:%d\n", sizeof(int));
	printf("short:%d\n", sizeof(short));
	printf("long:%d\n", sizeof(long));
	printf("float:%d\n", sizeof(float));
	printf("double:%d\n", sizeof(double));
}

//�ƽ�Ű(ASCII)�ڵ�: ��ǻ�Ϳ��� ���ڸ� ��Ÿ�������ػ��Ǵ� ����ǥ
void CharMain()
{
	int nDataA = 'A';
	char cDataA = 'A';

	printf("nDataA:%d,%c\n",nDataA,nDataA);
	printf("cDataA:%d,%c\n", cDataA, cDataA);
}

void OpMain()
{
	int nDataA = 10;
	int nDataB = 20;
	int nDataC = nDataA++;
	int nDataD = --nDataB;

	printf("A/C:%d/%d\n", nDataA, nDataC);
	printf("B/D:%d/%d\n", nDataB, nDataD);
}

void BitMaskMain()
{
	unsigned int color = 0x00385555;
	unsigned int result;
	printf("Color:%#08x\n",color);
	result = color & 0x00ff00ff;
	printf("BitMask:%#08x\n", result);
	result = result >> 16;
	printf("Result:%#08x\n", result);
}

void YearCheckMain()
{
	int year;
	printf("year:");
	scanf("%d",&year);//2012 //2100
	//(2012%4 = 0 == 0 -> T && 2012%100= 12!=0 ->T) ->T || 2012%400=12== 0 -> F ->T
	//(2100%4= 0 == 0 ->T && 2100%100=0!=0->F ->) F || 2100%400=100==0->F ->F
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		printf("leap year: %d\n", year);//2012
	}
	else
		printf("not leap year!:%d\n",year);//2100
}

void GradeMain()
{

}

void main()
{
	//HelloWorldMain();//�Լ��� ȣ��
	//CircleAreaMain();//
	//SizeMain();
	//CharMain();
	//LightSpeedMain();
	//OpMain();
	//BitMaskMain();
	YearCheckMain();
}