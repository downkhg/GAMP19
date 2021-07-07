using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIManager : MonoBehaviour
{
    public enum E_GUISCENCE_STATE { TITLE, THEEND, GAMEOVER, PLAY }
    public E_GUISCENCE_STATE curGUIScene;
    public List<GameObject> listGUIScenes;
    void ShowGUIScenes(E_GUISCENCE_STATE state)
    {
        for (int i = 0; i < listGUIScenes.Count; i++)
        {
            if (i == (int)state)
                listGUIScenes[i].SetActive(true);
            else
                listGUIScenes[i].SetActive(false);
        }
    }
    
    public void SetScence(E_GUISCENCE_STATE state)
    {
        switch (state)
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
                GameManager.GetInstance().Life = 3;
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
                    GameManager gameManager = GameManager.GetInstance();

                    if (gameManager.Life <= 0)
                        SetScence(E_GUISCENCE_STATE.GAMEOVER);
                    if (gameManager.responnerPlayer.objPlayer)
                    {
                        Player player = gameManager.responnerPlayer.objPlayer.GetComponent<Player>();
                        guiPlayerHPBar.SetState(player.HP, player.MaxHP);
                    }

                    if(Input.GetKeyDown(KeyCode.I))
                    {
                        if (objPopupLayer.activeSelf)
                        {
                            objPopupLayer.SetActive(false);
                            guiInventory.DeleteIventory();
                        }
                        else
                        {
                            guiInventory.SetIventory(gUIMonsterInfo);
                            objPopupLayer.SetActive(true);
                            
                        }
                    }
                }
                break;
        }
    }

    public GameObject objPopupLayer;
    public GameObject objKillMonster;
    public Image imgKillMonster;
    public GUIStateBar guiPlayerHPBar;
    public GUIInventory guiInventory;
    public GUIMonsterInfo gUIMonsterInfo;

    public void Initialize()
    {
        SetScence(curGUIScene);
        guiPlayerHPBar.Init();
        objPopupLayer.SetActive(false);
    }
}
