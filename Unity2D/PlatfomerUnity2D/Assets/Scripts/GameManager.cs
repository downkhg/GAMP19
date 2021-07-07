using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public TrackerCamera trackerCamera;

    public Responner responnerPlayer;
    public Responner responnerEagle;
    public Responner responnerOpossum;

    public MonsterManager monsterManager;

    public int Life = 3;

    static GameManager instance;

    public static GameManager GetInstance()
    {
        return instance;
    }

    public List<string> listMonsterPedia;

    public void SetPedia(string name)
    {
        listMonsterPedia.Add(name);
    }

    public void GetPedia(string name)
    {
        listMonsterPedia.Find(x => x == name);
    }

    private void OnGUI()
    {
        int w = 100;
        int h = 20;

        //foreach(string item  in listMonsterPedia)
        for(int i = 0; i < listMonsterPedia.Count; i++)
        {
            GUI.Box(new Rect(0, h * i, w, h), listMonsterPedia[i]);
        }
    }

    public GUIManager guiManager;

    public void EventChageScene(int stateNumber)
    {
        guiManager.SetScence((GUIManager.E_GUISCENCE_STATE)stateNumber);
    }
    public void EventExit()
    {
        Application.Quit();
    }

    private void Start()
    {
        monsterManager = GetComponent<MonsterManager>();

        SetPedia("eagle");
        SetPedia("frog");
        SetPedia("opossum");
        //SetPedia("eagle");
        //SetPedia("frog");
        //SetPedia("opossum");
        //SetPedia("eagle");
        //SetPedia("frog");
        //SetPedia("opossum");
        //SetPedia("eagle");
        //SetPedia("frog");
        //SetPedia("opossum");

        //SetPedia("frog");

        instance = this;
        guiManager.Initialize();
    }
    // Update is called once per frame
    void Update()
    {
        CameraTrackerSetting();
        EagleResponPointSetting();
        guiManager.UpdateScene();
    }

    void CameraTrackerSetting()
    {
        if (responnerPlayer.objPlayer)
        {
            trackerCamera.objTarget = responnerPlayer.objPlayer;
        }
    }

    void EagleResponPointSetting()
    {
        if (responnerEagle.objPlayer)
        {
            Eagle eagle = responnerEagle.objPlayer.GetComponent<Eagle>();

            if (eagle.objResponPoint == null)
                eagle.objResponPoint = responnerEagle.gameObject;

            if (eagle.objPatrolPoint == null)
                eagle.objPatrolPoint = responnerOpossum.gameObject;
        }
    }
}
