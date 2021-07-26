//전처리기: 컴파일전에 처리하는 것
#include <stdio.h>//표준입출력 라이브러리.
#define PI 3.141592

void HelloWorldMain()
{
	//빌드: 실행파일을 빌드하면 컴파일되어 실행파일이 만들어진다.
	//ctrl+F5: 빌드+실행(디버거없이 실행하기)
	printf("Hello World!\n");//\n: 줄바꿈문자.
	printf("khg\n");//;(세미콜론):문장끝을 의미함.
}

//원의 면적을 구하는 프로그램만들기(단, 반지름을 입력받고, 원의면적을 출력한다.)
//반지름*반지름*3.14(PI) = 원의면적
//데이터(재료):반지름,PI,원의면적 ->변수: 데이터가 저장되는 공간. 데이터타입: 데이터를 저장하는 종류 정수:int, 실수:float
//알고리즘(레시피):반지름*반지름*3.14(PI) = 원의면적
void CircleAreaMain()
{
	//1.반지름 변수를 생성하고, 값을 넣는다.
	//2.파이변수를 생성하고, 3.14 값을 넣는다.
	//3.원의반지름 변수를 생성하고, 반지름*반지름*PI를 한 결과를 넣는다.
	//4.원의 넓이를 출력한다.
	float raduis = 1;
	const float pi = 3.14;
	//pi = 4;//컴파일러야 내가 실수하면 니가 알려줘.
	printf("Raduis:");
	scanf("%f", &raduis);//입력시에는 변수값의 &을 붙어야한다.
	//float area = raduis * raduis * pi;
	float area = raduis * raduis * PI;
	printf("Area:%f\n",area);
}
//태양과지구에 거리가 x인데 이거리에 빛이 도달하려면 시간이 얼마나 걸리는가.(분)
//빛의 속도: 30만 m/s 
//태양과지구사이거리: 14960만 m
//____________________________________
//_
//데이터: 빛의 속도, 태양과지구사이거리, 시간(초) -> 변수: 데이터를 저장하는 공간 -> 타입,이름
//알고리즘: 긴막대기(태양과지구사의거리)/짧은막대기(빛의속도) = 개수 -> 시간
//초 -> 분 = 초/60 = 분
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

//아스키(ASCII)코드: 컴퓨터에서 문자를 나타내기위해사용되는 문자표
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
//점수를 입력받아 학점을 구하는 프로그램만들기
//(단, 90점이상 A, 90점미만, 80점이상 B, 80점미만, 70점이상 C, 70점미만 60점이상 D, 60점미만 F)
//데이터: 점수, 학점
//알고리즘:  90점이상 A, 90점미만, 80점이상 B, 80점미만, 70점이상 C, 70점미만 60점이상 D, 60점미만 F
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
//계산기 두수를 입력받아, 사칙연산을 하는 프로그램.
//데이터: 두수,결과,문자(+,-,*,/)
//알고리즘: 두수를 문자에 따라서 사칙연산을 결과에 저장한다.
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
		//break; //생략되면 다음 break까지 코드가 실행됨. 의도적 생략기법은 잘사용하면 유용하지만 사용하지않는 편이 이해가 쉽다.
	case '/': //op == /
		nResult = nInputA / nInputB; // 10/3 = 3 //10 / 5 = 2
		break;
	default:
		printf("!?!?!?!?!!?!?!\n");
		break;
	}
	printf("%d = %d %c %d",nResult,nInputA,cInputOp,nInputB);//3 = 10 / 3 // 10 * 5 = 2
}
//마일을 미터로 변환하는데 0~2까지 변환된 미터를 출력.
// (1마일 1609미터)
//데이터: 마일,미터
//알고리즘: 0~2까지 미터를 마일로 변환.
//1.반복되는 알고리즘을 모두 코드로 옮긴다.
//2.반복되는 부분을 찾아서 무한루프돌린다.
//3.끝나는 조건을 증감후에 break로 넣는다.
//4.3에 반대되는 조건을 반복문의 조건으로 설정한다.
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
	//for문 일정횟수 반복하는데 사용된다.
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

//1.데이터와 알고리즘을 분리한다.
//2.데이터는 변수 알고리즘은 연산,반복,조건 등이 조합된다.
//3.반복되는 경우는 먼저 반복하고 정답을 출력한다.
//박테리아의 초기수: 10, 160마리, 4시간지났을때 끝남.
//정답을 분석하여 문제를 텍스트화 한다.
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

//종이를 접으면 (면적)이 (1/2로 줄어)들때,
//(종이면적이 1/10이하)로 줄어들려면, (몇번접)아야하는가?
//데이터: 종이의면적, 종이의 면적이 10%이하, 접은횟수
//알고리즘: 
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
/* 다음모양을 출력하라.
해당모양의 이름의 함수안에 조건만 변경하여 해당모양이 출력되도록만들기
Full    Rect   Window Stair
y01234x
0#####  #####  #####  #
1#####  #   #  # # #  ##
2#####  #   #  #####  ###
3#####  #   #  # # #  ####
4#####  #####  #####  ##### */
//1.규칙을 찾는다.
//Rect(y,x) (1,1)(1,2)(1,3) (2,1)(2,2)(2,3) (3,1)(3,2)(3,3) 1~3
//Window  (1,1)(1,3) (3,1)(3,3) -> 홀수
//Stair '#' (0,0) (1,0)(1,1) (2,0)(2,1)(2,2) 
//		    (3,0)(3,1)(3,2)(3,3) (4,0)(4,1)(4,2)(4,3)
//2.규칙대로 조건을 모두 준다.
//
//3.규칙에서 줄일만한 부분이 없는지 찾는다.
//(조건문없이가능) -> y가 증가할때마다 x의 값이 증가한다.
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
	//HelloWorldMain();//함수의 호출
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