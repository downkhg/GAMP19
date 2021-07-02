using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public int HP = 100;
    public int Atk = 10;
    public int MP = 100;

    public int MaxHP;
    public int MaxMP;

    public int Lv = 1;
    public int Exp = 0;

    public void Attack(Player target)
    {
        target.HP -= Atk;
        if (target.Death())
        {
            StillExp(target);
            GameManager.GetInstance().objKillMonster = this.gameObject;
        }
    }

    public bool Death()
    {
        if (HP > 0)
            return false;
        else
            return true;
    }

    public void LvUp()
    {
        if(Exp >= 100)
        {
            Lv++;
            Atk += 5;
            HP += 5;
            MP += 5;
            MaxHP += 5;
            MaxMP += 5;
            Exp -= 100;
        }
    }

    public void StillExp(Player target)
    {
        Exp += target.Exp + target.Lv * 100;
    }

    public GUIStateBar guiHPBar;
    public int idxDegugGUI = 0;

    public void UpdateStateBar()
    {
        if (guiHPBar) guiHPBar.SetState(HP, MaxHP);
    }

    private void OnGUI()
    {
        int nWidth = 100;
        int nHeight = 20;
        int nV = 0;
        GUI.Box(new Rect(nWidth * idxDegugGUI, nHeight * nV, nWidth, nHeight), string.Format("{0}", gameObject.name)); nV++;
        GUI.Box(new Rect(nWidth * idxDegugGUI, nHeight * nV, nWidth, nHeight),string.Format("HP:{0}", HP)); nV++;
        GUI.Box(new Rect(nWidth * idxDegugGUI, nHeight * nV, nWidth, nHeight), string.Format("ATK:{0}", Atk)); nV++;
        GUI.Box(new Rect(nWidth * idxDegugGUI, nHeight * nV, nWidth, nHeight), string.Format("MP:{0}", MP)); nV++;
        GUI.Box(new Rect(nWidth * idxDegugGUI, nHeight * nV, nWidth, nHeight), string.Format("Lv/Exp:{0}/{1}", Lv, Exp)); nV++;
    }

    // Start is called before the first frame update
    void Start()
    {
        MaxHP = HP;
        MaxMP = MP;
        if (guiHPBar) guiHPBar.Init();
    }

    // Update is called once per frame
    void Update()
    {
        UpdateStateBar();
        if (Death())
        {
            Destroy(this.gameObject);
            GameManager.GetInstance().Life--;
        }
        LvUp();
    }
}
