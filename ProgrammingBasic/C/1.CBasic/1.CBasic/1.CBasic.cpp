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
//������ �Է¹޾� ������ ���ϴ� ���α׷������
//(��, 90���̻� A, 90���̸�, 80���̻� B, 80���̸�, 70���̻� C, 70���̸� 60���̻� D, 60���̸� F)
//������: ����, ����
//�˰���:  90���̻� A, 90���̸�, 80���̻� B, 80���̸�, 70���̻� C, 70���̸� 60���̻� D, 60���̸� F
// S >= 90, A S<90 && S>=80 B,
void GradeMain()
{
	int Score = 70;
	char Grade;

	//if (Score >= 90)//60<=90 -> F
	//{
	//	Grade = 'A';
	//}
	//else if (Score >= 80)//60<=80 -> F
	//{
	//	Grade = 'B';
	//}
	//else if (Score >= 70)//60<=70 -> F
	//{
	//	Grade = 'C';
	//}
	//else if (Score >= 60)//60<=60 -> T
	//{
	//	Grade = 'D';
	//}
	//else 
	//{
	//	Grade = 'F';
	//}


	if (Score >= 90)//70>=90 -> F
	{
		Grade = 'A';
	}
	//80 <= S < 90
	//S >= 80
	//S < 90 && S >= 80 B,
	if (Score >= 80 && Score < 90)//70<=80 -> F
	{
		Grade = 'B';
	}
	if (Score >= 70 && Score < 80)//70<=70 -> T
	{
		Grade = 'C';
	}
	if (Score >= 60 && Score < 70)//70<=60 -> F
	{
		Grade = 'D';
	}
	if (Score < 60)
	{
		Grade = 'F';
	}

	printf("%d -> %c\n",Score,Grade);//60->D
}
//���� �μ��� �Է¹޾�, ��Ģ������ �ϴ� ���α׷�.
//������: �μ�,���,����(+,-,*,/)
//�˰���: �μ��� ���ڿ� ���� ��Ģ������ ����� �����Ѵ�.
void CalMain()
{
	int nInputA;
	int nInputB;
	int nResult;
	char cInputOp;
	printf("ex) 10-20\n");
	scanf("%d%c%d",&nInputA,&cInputOp,&nInputB);// 10/3 //10*5
	/*if (cInputOp == '+')
		nResult = nInputA + nInputB;
	else if (cInputOp == '-')
		nResult = nInputA - nInputB;
	else if (cInputOp == '*')
		nResult = nInputA * nInputB;
	else if (cInputOp == '/')
		nResult = nInputA / nInputB;
	else
		printf("!?!?!?!?!!?!?!\n");*/
	switch (cInputOp)// '/' //'*'
	{
	case '+':
		nResult = nInputA + nInputB;
		break;
	case '-':
		nResult = nInputA - nInputB;
		break;
	case '*': 
		nResult = nInputA * nInputB; // 10 * 5 = 50
		//break; //�����Ǹ� ���� break���� �ڵ尡 �����. �ǵ��� ��������� �߻���ϸ� ���������� ��������ʴ� ���� ���ذ� ����.
	case '/': //op == /
		nResult = nInputA / nInputB; // 10/3 = 3 //10 / 5 = 2
		break;
	default:
		printf("!?!?!?!?!!?!?!\n");
		break;
	}
	printf("%d = %d %c %d",nResult,nInputA,cInputOp,nInputB);//3 = 10 / 3 // 10 * 5 = 2
}
//������ ���ͷ� ��ȯ�ϴµ� 0~2���� ��ȯ�� ���͸� ���.
// (1���� 1609����)
//������: ����,����
//�˰���: 0~2���� ���͸� ���Ϸ� ��ȯ.
//1.�ݺ��Ǵ� �˰����� ��� �ڵ�� �ű��.
//2.�ݺ��Ǵ� �κ��� ã�Ƽ� ���ѷ���������.
//3.������ ������ �����Ŀ� break�� �ִ´�.
//4.3�� �ݴ�Ǵ� ������ �ݺ����� �������� �����Ѵ�.
void MailToMeterMain()
{
	int nMail;
	int nMeter;

	nMail = 0;
	//while (true)
	while(nMail <= 2)
	{
		nMeter = nMail * 1609;
		printf("Mail to Meter:%d->%d\n", nMail, nMeter);
		nMail++;
		//if (nMail > 2) break;
	}
	//for�� ����Ƚ�� �ݺ��ϴµ� ���ȴ�.
	for (nMail = 0; nMail < 3; nMail++)
	{
		nMeter = nMail * 1609;
		printf("Mail to Meter:%d->%d\n", nMail, nMeter);
	}

	/*nMail = 1;
	nMeter = nMail * 1609;
	printf("Mail to Meter:%d->%d\n", nMail, nMeter);

	nMail = 2;
	nMeter = nMail * 1609;
	printf("Mail to Meter:%d->%d\n", nMail, nMeter);*/
}

//1.�����Ϳ� �˰����� �и��Ѵ�.
//2.�����ʹ� ���� �˰����� ����,�ݺ�,���� ���� ���յȴ�.
//3.�ݺ��Ǵ� ���� ���� �ݺ��ϰ� ������ ����Ѵ�.
//���׸����� �ʱ��: 10, 160����, 4�ð��������� ����.
//������ �м��Ͽ� ������ �ؽ�Ʈȭ �Ѵ�.
void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	while(nBateria < 160)
	//while (true)
	{
		nBateria = nBateria * 2;//20
		nTime++;
		printf("Time:%d, Bateria:%d\n", nTime, nBateria);
		if (nBateria >= 160) break;
		//if (nTime == 4) break;
	}

	//nBateria = nBateria * 2;//20
	//nTime = 1;

	//nBateria = nBateria * 2;//40
	//nTime = 2;

	//nBateria = nBateria * 2;//80
	//nTime = 3;

	//nBateria = nBateria * 2;//160
	//nTime = 4;

	printf("Time:%d\n", nTime);
}

//���̸� ������ (����)�� (1/2�� �پ�)�鶧,
//(���̸����� 1/10����)�� �پ�����, (�����)�ƾ��ϴ°�?
//������: �����Ǹ���, ������ ������ 10%����, ����Ƚ��
//�˰���: 
void PaperAreaMain()
{
	int nPaperArea = 100;
	int nPaperCount = 0;
	int nMinArea = nPaperArea * 0.1f;

	while (true)
	{
		nPaperArea *= 0.5f; //50
		nPaperCount++;//1
		//50 <= 5 = 50*0.1f -> F
		printf("Aera:%d, Count:%d\n", nPaperArea, nPaperCount);
		//50 <= 5
		if (nPaperArea <= nMinArea * 0.1) break;
	}

	//nPaperArea *= 0.5f; //25
	//nPaperCount++;//2

	//nPaperArea *= 0.5f; //12.5
	//nPaperCount++;//3

	//nPaperArea *= 0.5f; //6.25
	//nPaperCount++;//4

	printf("Aera:%d, Count:%d",nPaperArea,nPaperCount);
}
/* ��������� ����϶�.
�ش����� �̸��� �Լ��ȿ� ���Ǹ� �����Ͽ� �ش����� ��µǵ��ϸ����
Full    Rect   Window Stair
y01234x
0#####  #####  #####  #
1#####  #   #  # # #  ##
2#####  #   #  #####  ###
3#####  #   #  # # #  ####
4#####  #####  #####  ##### */
//1.��Ģ�� ã�´�.
//Rect(y,x) (1,1)(1,2)(1,3) (2,1)(2,2)(2,3) (3,1)(3,2)(3,3) 1~3
//Window  (1,1)(1,3) (3,1)(3,3) -> Ȧ��
//Stair '#' (0,0) (1,0)(1,1) (2,0)(2,1)(2,2) 
//		    (3,0)(3,1)(3,2)(3,3) (4,0)(4,1)(4,2)(4,3)
//2.��Ģ��� ������ ��� �ش�.
//
//3.��Ģ���� ���ϸ��� �κ��� ������ ã�´�.
//(���ǹ����̰���) -> y�� �����Ҷ����� x�� ���� �����Ѵ�.
void FullMain()
{
	for (int y = 0; y < 5; y++)//(?,0) //(?,1) //(?,2)//(?,3)//(?,4)//(?,5)
	{
		//(0,0),(1,0),(2,0),(3,0),(4,0)\n
		//(0,1),(1,1),(2,1),(3,1),(4,1)\n
		//(0,2),(1,2),(2,2),(3,2),(4,2)\n
		//(0,3),(1,3),(2,3),(3,3),(4,3)\n
		//(0,4),(1,4),(2,4),(3,4),(4,4)\n
		for (int x = 0; x < 5; x++)
		{
			printf("#");
		}
		printf("\n");
	}
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
	//YearCheckMain();
	//GradeMain();
	//CalMain();
	//MailToMeterMain();
	//BateriaMain();
	//PaperAreaMain();
	FullMain();
}