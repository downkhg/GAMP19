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

void GradeMain()
{

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
	YearCheckMain();
}