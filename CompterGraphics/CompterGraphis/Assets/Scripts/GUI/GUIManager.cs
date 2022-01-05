using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIManager : MonoBehaviour
{
    [SerializeField]
    GameManager m_cGameManagerInstance;
    [SerializeField]
    GUIItemInventory m_guiItemInventory;
    [SerializeField]
    bool m_bPopup;
    [SerializeField]
    GameObject m_objPopupLayer;

    public void ShowPopupLayer()
    {
        Time.timeScale = 0;
        m_objPopupLayer.SetActive(true);
        m_guiItemInventory.gameObject.SetActive(true);
        m_bPopup = true;
    }

    public void ClosePopupLayer()
    {
        Time.timeScale = 1;
        m_objPopupLayer.SetActive(false);
        m_guiItemInventory.gameObject.SetActive(false);
        m_bPopup = false;
    }

    public enum E_GUI_STATE { NONE = -1, TITLE, THEEND, GAMEOVER, PLAY }
    [SerializeField]
    List<GameObject> m_listGUIScenes;
    [SerializeField]
    E_GUI_STATE m_eCurState;

    public void ShowGUIScenece(int idx)
    {
        for (int i = 0; i < m_listGUIScenes.Count; i++)
        {
            if (idx == i)
                m_listGUIScenes[i].SetActive(true);
            else
                m_listGUIScenes[i].SetActive(false);
        }
    }
    public void SetGUIScene(E_GUI_STATE state)
    {
        switch (state)
        {
            case E_GUI_STATE.TITLE:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.THEEND:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.GAMEOVER:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.PLAY:
                Time.timeScale = 1;
                break;
        }
        ShowGUIScenece((int)state);
        m_eCurState = state;
    }

    public void UpdateGUIScene()
    {
        switch (m_eCurState)
        {
            case E_GUI_STATE.NONE:
                break;
            case E_GUI_STATE.TITLE:
                break;
            case E_GUI_STATE.THEEND:
                break;
            case E_GUI_STATE.PLAY:
                {
                    if (Input.GetKeyDown(KeyCode.I))
                    {
                        if (m_bPopup)
                            ClosePopupLayer();
                        else
                            ShowPopupLayer();
                    }

                    m_cGameManagerInstance.EventPlayrControllerTo2DStatusInforUpdate(m_guiPlayerInfo);
                }
                break;
        }
    }

    [SerializeField]
    GUIPlayerInfo m_guiPlayerInfo;


    public void Initialize(GameManager gameManager)
    {
        m_cGameManagerInstance = gameManager;
        SetGUIScene(m_eCurState);
    }

    public void SetItemIventory(ItemIeventory itemIeventory)
    {
        m_guiItemInventory.SetItems(itemIeventory);
    }

    // Update is called once per frame
    void Update()
    {
        UpdateGUIScene();
    }
}
