using System;

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
            BattleMain();
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
    }
}
