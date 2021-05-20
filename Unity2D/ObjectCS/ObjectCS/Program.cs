using System;
using System.Collections.Generic;
using CSClass;

namespace ObjectCS
{
    class Player
    {
        public string Name;
        public int Exp;
        public int Lv;
        public int Atk;
        public int HP;

        public Player(string name, int hp, int atk)
        {
            Name = name; 
            HP = hp;
            Atk = atk;
            Lv = 0;
            Exp = 0;
        }
        public void Attack(Player target)
        {
            target.HP -= this.Atk;
        }

        public bool Death()
        {
            if (HP > 0)
                return false;
            else
                return true;
        }

        public void Show()
        {
            Console.WriteLine("###########" + Name + "###########");
            Console.WriteLine("HP:"+HP);
            Console.WriteLine("Atk:" + Atk);
            Console.WriteLine("Exp/Lv:" + Exp + "/" + Lv);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            //BattleMain();
            PokemonGame();
        }

        static void BattleMain()
        {
            Player player = new Player("Player",100,10);
            Player monster = new Player("Monster",100,10);
            player.Show();
            monster.Show();
            while (true)
            {
                if (player.Death() == false)
                {
                    player.Attack(monster);
                    player.Show();
                }
                else
                    break;

                if (monster.Death() == false)
                {
                    monster.Attack(player);
                    monster.Show();
                }
                else
                    break;
            }
        }

        static void PokemonGame()
        {
            bool bLoop = true;

            Trainner trainner = new Trainner();
            Pokemon picacu = new Pokemon("picacu",100,10);
            Pokemon ev = new Pokemon("ev", 100, 10);

            trainner.Catch(picacu);

            List<Pokemon> listWilds = new List<Pokemon>();
            listWilds.Add(new Pokemon("파이리", 100, 10));
            listWilds.Add(new Pokemon("꼬부기", 100, 10));
            listWilds.Add(new Pokemon("이상해씨", 100, 10));

            while (bLoop)
            {
                Console.WriteLine("가고싶은곳을 입력하세요!(마을,상점,필드,게임종료)");
                string strInputStage = Console.ReadLine();

                switch (strInputStage)
                {
                    case "마을":
                        Console.WriteLine(strInputStage + " 입니다.");
                        break;
                    case "상점":
                        Console.WriteLine(strInputStage + " 입니다.");
                        break;
                    case "게임종료":
                        bLoop = false;
                        break;
                    case "필드":
                        {
                            Console.WriteLine(strInputStage + " 입니다.");

                            Console.WriteLine("가고 싶은 서식지를 선택하세요!(0:파이리,1:꼬부기,2:이상해씨)");
                            int nSelectArea = int.Parse(Console.ReadLine());
                            Pokemon wild = listWilds[nSelectArea];

                            Console.WriteLine("싸울 포켓몬을 선택하세요!");
                            trainner.ShowPokemons();
                            int nSelect = int.Parse(Console.ReadLine());
                            
                            Pokemon battleMonster = trainner.Throw(nSelect);
                            Pokemon catchMonster = BattlePoketmon(battleMonster, wild);

                            if (catchMonster != null)
                            {
                                trainner.Catch(catchMonster);
                                Console.WriteLine(wild.Name + "를 잡는데 성공했다 !!!");
                            }
                            else
                                Console.WriteLine(wild.Name + "가 도망쳤다 !!!");
                        }
                        break;
                    default:
                        Console.WriteLine("존재하지않는 장소 입니다.");
                        break;
                }
            }

            Console.WriteLine("게임종료");
        }

        static Pokemon BattlePoketmon(Pokemon monster, Pokemon wild)
        {
            while (true)
            {
                if (monster.Death() == false)
                {
                    monster.Attack(wild);
                    monster.Show();
                }
                else
                    break;

                if (wild.Death() == false)
                {
                    wild.Attack(monster);
                    wild.Show();
                }
                else
                {
                    return wild;
                    break;
                }
            }

            return null;
        }
    }
}
