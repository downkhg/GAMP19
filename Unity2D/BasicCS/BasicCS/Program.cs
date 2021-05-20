using System;
using System.Collections.Generic;

namespace BasicCS
{
    class Program
    {
        //static Program cProgram = new Program();

        static void Main(string[] args)
        {
            ////Console.WriteLine("Hello World!");
            //Console.WriteLine("khg");//;세미콜론
            //Console.WriteLine("Add:" + Add(10, 20));
            //ValMain(); //함수의 호출
            //CriticalAttackMain();
            //PlayerAttackMonsterMain();
            //CriticalAttackMain();
            //StageMain();
            //AttackWhileMain();
            //BattleMain();
            MonsterListMain();
            //cProgram.Add(10, 20);
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
        //크리티컬데미지 추가하기
        //플레이어가 몬스터를 공격하는데 일정확률로 크리티컬이 발생한다.
        //플레이어의 공격력만큼 몬스터의 체력이 감소한다. 이때 플레이어의 데미지는 크리티컬이 발생하면 150%의 데미지가 발생한다.
        //크리티컬? 일정확률로 더 큰데미지를 준다.
        //일정확률? C# 일정확률 -> 랜덤 구글링한다.
        static void CriticalAttackMain()
        {
            int nMonsterHP = 100;
            int nPlayerAtk = 10;
            Random cRandom = new Random();
            int nRandom = cRandom.Next(1, 3);//1~2까지만 나온다.(n-1)
            Console.WriteLine("Random:" + nRandom);
            int nAttack = nPlayerAtk;
            if (nRandom == 1)//1/2 = 50%
            {
                nAttack = (int)((float)nPlayerAtk * 1.5f);
                nMonsterHP = nMonsterHP - (int)((float)nPlayerAtk * 1.5f);
                Console.WriteLine("Critical!!!");
            }
            else
                nMonsterHP = nMonsterHP - nPlayerAtk;
            Console.WriteLine("PlayerAtk:" + nAttack);
            Console.WriteLine("MonsterHP:" + nMonsterHP);
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
        //게임의 스테이지를 선택하고, 
        //해당 스테이지에 들어가면 ~입니다.
        //라고 보여주도록 만들기
        //(단 선택은 해당 지역의 이름을 입력하면 이동하는 것으로 한다..)
        static void StageMain()
        {
            Console.WriteLine("가고싶은곳을 입력하세요!(마을,상점,필드)");
            string strInputStage = Console.ReadLine();

            switch (strInputStage)
            {
                case "마을":
                    Console.WriteLine(strInputStage + " 입니다.");
                    break;
                case "상점":
                    Console.WriteLine(strInputStage + " 입니다.");
                    break;
                case "필드":
                    Console.WriteLine(strInputStage + " 입니다.");
                    break;
                default:
                    Console.WriteLine("존재하지않는 장소 입니다.");
                    break;
            }
            //연관연산자를 이용하여 간단하게 나타냄

            if (strInputStage == "마을" ||
                strInputStage == "상점" ||
                strInputStage == "필드")
                Console.WriteLine(strInputStage + " 입니다.");
            else
                Console.WriteLine("존재하지않는 장소 입니다.");

            if (strInputStage == "마을")
                Console.WriteLine(strInputStage + " 입니다.");
            else if (strInputStage == "상점")
                Console.WriteLine(strInputStage + " 입니다.");
            else if (strInputStage == "필드")
                Console.WriteLine(strInputStage + " 입니다.");
            else
                Console.WriteLine("존재하지않는 장소 입니다.");

        }
        //플레이어가 공격을 (죽을때:hp가 0이될때)까지 반복한다.
        static void AttackWhileMain()
        {
            int nMonsterHP = 100;
            int nPlayerAtk = 11;

            //while (true)
            while (nMonsterHP > 0)
            {
                //if (nMonsterHP <= 0) break;
                nMonsterHP = nMonsterHP - nPlayerAtk;

                Console.WriteLine("MonsterHP:" + nMonsterHP);
            }
        }
        //플레이어가 몬스터를 공격하면, 몬스터는 플레이어를 반격한다.
        //반격: 공격을 받고 공격한다.
        //어느한쪽이 쓰러질때까지
        static void BattleMain()
        {
            int nMonsterHP = 100;
            int nMonsterAtk = 11;

            int nPlayerAtk = 11;
            int nPlayerHP = 100;
            
            while (true)
            {
                //플레이어가 살아있을때만 공격한다.
                if (nPlayerHP >= 0)
                {
                    //몬스터를 공격한다.
                    nMonsterHP = nMonsterHP - nPlayerAtk;
                    Console.WriteLine("MonsterHP:" + nMonsterHP);
                }
                else
                    break;

                //몬스터가 살아있을때만 공격한다.
                if (nMonsterHP >= 0)
                {
                    //플레이어를 공격한다.
                    nPlayerHP = nPlayerHP - nMonsterAtk;
                    Console.WriteLine("PlayerHP:" + nPlayerHP);
                }
                else
                    break;

            }
        }

        //몬스터리스트를 만들고, 슬라임,스켈레톤,좀비,드래곤을 추가한다.
        //0,3번리스트의 이름을 확인하고
        //모든리스트의 값을 확인한다.
        static void MonsterListMain()
        {
            List<string> listMonster = new List<string>();

            listMonster.Add("Slime"); //0
            listMonster.Add("Skeleton"); //1
            listMonster.Add("Zombie"); //2
            listMonster.Add("Dragon"); //3

            Console.WriteLine("[0]" + listMonster[0]); //[0]Slime
            Console.WriteLine("[3]" + listMonster[3]); //[3]Dragon

            for(int i = 0; i<listMonster.Count; i++)
            {
                Console.WriteLine("[" + i + "]" + listMonster[i]);
            }
            //[0]Slime
            //[1]Skeleton
            //[2]Zombie
            //[3]Dragon
        }
    }
    
}
