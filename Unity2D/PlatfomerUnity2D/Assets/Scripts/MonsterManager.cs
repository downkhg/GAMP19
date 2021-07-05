using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public struct MonsterInfo
{
    public Player playerStatus;
    public string name;
    public string comment;
    public MonsterInfo(string _name, string _comment, Player _playerStatus)
    {
        playerStatus = _playerStatus;
        name = _name;
        comment = _comment;
    }

    public MonsterInfo(string _name, string _comment, int hp, int mp, int atk, int exp)
    {
        playerStatus = new Player(hp, mp, atk, exp);
        name = _name;
        comment = _comment;
    }
}

public class MonsterManager : MonoBehaviour
{
    Dictionary<string, MonsterInfo> listMonsterInfos;

    public MonsterInfo GetMonster(string name)
    {
        return listMonsterInfos[name];
    }

    public void Initialize()
    {
        MonsterInfo[] monsterInfos = new MonsterInfo[]
        {
            new MonsterInfo("opssum","opssum",20,20,5,0),
            new MonsterInfo("eagle", "eagle", 50, 20, 20, 100),
            new MonsterInfo("frog", "frog", 100, 20, 10, 200)
        }; 
        listMonsterInfos = new Dictionary<string, MonsterInfo>(monsterInfos.Length);
        foreach(MonsterInfo monster in monsterInfos)
        {
            listMonsterInfos.Add(monster.name, monster);
        }
        //foreach(KeyValuePair<string,MonsterInfo> monster in listMonsterInfos)
        foreach(var monster in listMonsterInfos)
        {
            Debug.Log(monster.Key);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        Initialize();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
