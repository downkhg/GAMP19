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

    public int Life = 3;

    static GameManager instance;

    public static GameManager GetInstance()
    {
        return instance;
    }

    public enum E_GUISCENCE_STATE { TITLE, THEEND, GAMEOVER, PLAY }
    public E_GUISCENCE_STATE curGUIScene;
    public List<GameObject> listGUIScenes;
    void ShowGUIScenes(E_GUISCENCE_STATE state)
    {
        for(int i = 0;  i<listGUIScenes.Count; i++)
        {
            if (i == (int)state)
                listGUIScenes[i].SetActive(true);
            else
                listGUIScenes[i].SetActive(false);
        }
    }
    public void EventChageScene(int stateNumber)
    {
        SetScence((E_GUISCENCE_STATE)stateNumber);
    }
    public void EventExit()
    {
        Application.Quit();
    }
    public void SetScence(E_GUISCENCE_STATE state)
    {
        switch(state)
        {
            case E_GUISCENCE_STATE.TITLE:
                Time.timeScale = 0;
                break;
            case E_GUISCENCE_STATE.THEEND:
                Time.timeScale = 0;
                break;
            case E_GUISCENCE_STATE.GAMEOVER:
                if (objKillMonster)
                {
                    imgKillMonster.sprite =
                        objKillMonster.GetComponent<SpriteRenderer>().sprite;
                }
                Time.timeScale = 0;
                break;
            case E_GUISCENCE_STATE.PLAY:
                Time.timeScale = 1;
                Life = 3;
                break;
        }
        ShowGUIScenes(state);
        curGUIScene = state;
    }
    public void UpdateScene()
    {
        switch (curGUIScene)
        {
            case E_GUISCENCE_STATE.TITLE:
                break;
            case E_GUISCENCE_STATE.THEEND:
                break;
            case E_GUISCENCE_STATE.GAMEOVER:
                break;
            case E_GUISCENCE_STATE.PLAY:
                {
                    if (Life <= 0)
                        SetScence(E_GUISCENCE_STATE.GAMEOVER);
                    if (responnerPlayer.objPlayer)
                    {
                        Player player = responnerPlayer.objPlayer.GetComponent<Player>();
                        guiPlayerHPBar.SetState(player.HP, player.MaxHP);
                    }
                }
                break;
        }
    }

    public GameObject objKillMonster;
    public Image imgKillMonster;
    public GUIStateBar guiPlayerHPBar;

    private void Start()
    {
        instance = this;
        SetScence(curGUIScene);

        guiPlayerHPBar.Init();
    }
    // Update is called once per frame
    void Update()
    {
        CameraTrackerSetting();
        EagleResponPointSetting();
        UpdateScene();
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
