using System;

namespace BasicCS
{
    class Program
    {
        static void Main(string[] args)
        {
            ////Console.WriteLine("Hello World!");
            //Console.WriteLine("khg");//;세미콜론
            //Console.WriteLine("Add:" + Add(10, 20));
            //ValMain(); //함수의 호출
            //CriticalAttackMain();
            PlayerAttackMonsterMain();
        }
        //매개변수: 값을 전달할때 사용하는 변수
        static int Add(int a, int b) //10, 20 
        {
            int c = a + b; //30 //대입: 값을 넣음
            return c;
        }
        static void ValMain() //함수의 정의
        {
            int nScore = 0; //정수
            float fRat = 1.0f / 4.0f; //실수
            Console.WriteLine("Score:" + nScore);
            Console.WriteLine("Rat:" + fRat);
        }
        static void CriticalAttackMain()
        {
            //내용채우기
        }
        //플레이어가 몬스터를 공격하기(데이터,연산(알고리즘))
        //플레이어? 몬스터?
        //플레이어의 공격력이 10이고 몬스터의 체력이 100일때,
        //몬스터가 공격하면 어떤 결과를 구하는 프로그램을 작성하고 그결과를 출력하라.
        //공격?: (몬스터의 체력:int)에서 (플레이어의 공격력:int)을 뺀다.
        static void PlayerAttackMonsterMain()
        {
            int nMonsterHP = 100;
            int nPlayerAtk = 10;

            nMonsterHP = nMonsterHP - nPlayerAtk;

            Console.WriteLine("MonsterHP:" + nMonsterHP);
        }
    }
}
