using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    [SerializeField]
    List<ItemObejct> m_listItemObejct;
    [SerializeField]
    ItemManager m_cItemManager;
    [SerializeField]
    Transform m_transResponPlayer;

    [SerializeField]
    Camera m_cMainCamera;


    public Camera MainCamera { get => m_cMainCamera; set => m_cMainCamera = value; }

    public ItemManager GetItemManager() { return m_cItemManager; }
    public List<ItemObejct> GetItemObejcts() { return m_listItemObejct; }
    //싱글톤패턴: 엄격한 싱글톤이라 말할수 없지만, 접근의 용이함을 활용하기위해 싱글톤화함.
    //디자인패턴은 무조건 엄격하게 적용할것이 아니라 사용성에 맞게 적절히 방법이 변경되는 경우가 많음.

    //[SerializeField] //딕셔너리는 인스펙터를 사용할수없다.
    Dictionary<string, PlayerController> m_dicPlayerController = new Dictionary<string,PlayerController>();
    [SerializeField]
    string m_strID;

    public PlayerController GetPlayerContorl(string id)
    {
        return m_dicPlayerController[id];
    }


    public ItemIeventory GetPlayerItemIventory(string id)
    {
        Controller controller = GetPlayerContorl(m_strID);
        ItemIeventory itemIeventory = controller.GetComponent<ItemIeventory>();
        return itemIeventory;
    }

    static GameManager m_cInstance;

    static public GameManager GetInstance()
    {
        return m_cInstance;
    }

    private void Awake()
    {
        m_cInstance = this;
    }

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

    public enum E_GUI_STATE { NONE = -1, TITLE, THEEND, GAMEOVER , PLAY }
    [SerializeField]
    List<GameObject> m_listGUIScenes;
    [SerializeField]
    E_GUI_STATE m_eCurState;

    public void ShowGUIScenece(int idx)
    {
        for(int i = 0; i < m_listGUIScenes.Count; i++ )
        {
            if(idx == i)
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
        switch(m_eCurState)
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

                    PlayerController playerController = GetPlayerContorl(m_strID);
                    Vector3 vScreenPos = m_cMainCamera.WorldToScreenPoint(playerController.transform.position);
                    m_guiPlayerInfo.transform.position = vScreenPos;
                    m_guiPlayerInfo.UpdatePlayerInfo(playerController);
                }
                break;
        }
    }

    [SerializeField]
    GUIPlayerInfo m_guiPlayerInfo;


    public void EventGUIScenese(int idx)
    {
        SetGUIScene((E_GUI_STATE)idx);
    }

    public void EventShowMeTheItem()
    {
        ItemIeventory itemIeventory = GetPlayerItemIventory(m_strID);
        itemIeventory.TestIventory(10);
    }

    public bool EventCreatePlayer(string id)
    {
        GameObject prefabPlayer = Resources.Load("Prefabs/PlayerController") as GameObject;

        if(prefabPlayer)
        {
            GameObject objPlayer = Instantiate(prefabPlayer, m_transResponPlayer.transform.position, Quaternion.identity);
            objPlayer.name = id;
            m_dicPlayerController.Add(id, objPlayer.GetComponent<PlayerController>());
            return true;
        }
        return false;
    }

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("GameManager.Start() 1");
        m_cItemManager.InitItemData();
        EventCreatePlayer("player");
        for(int i = 0;  i< m_listItemObejct.Count; i++)
        {
            m_listItemObejct[i].Item = m_cItemManager.GetItem(0);
        }
        SetGUIScene(m_eCurState);
        ItemIeventory itemIeventory = GetPlayerItemIventory(m_strID);
        EventShowMeTheItem();
        m_guiItemInventory.SetItems(itemIeventory);
        Debug.Log("GameManager.Start() 2");
    }

    private void Update()
    {
        UpdateGUIScene();
    }
}