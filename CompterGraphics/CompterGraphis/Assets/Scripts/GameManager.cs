using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    [SerializeField]
    GUIItemInventory m_guiItemInventory;

    [SerializeField]
    List<ItemObejct> m_listItemObejct;
    [SerializeField]
    ItemManager m_cItemManager;

    public ItemManager GetItemManager() { return m_cItemManager; }
    public List<ItemObejct> GetItemObejcts() { return m_listItemObejct; }
    //싱글톤패턴: 엄격한 싱글톤이라 말할수 없지만, 접근의 용이함을 활용하기위해 싱글톤화함.
    //디자인패턴은 무조건 엄격하게 적용할것이 아니라 사용성에 맞게 적절히 방법이 변경되는 경우가 많음.

    [SerializeField]
    Dictionary<string, PlayerController> m_dicPlayerController;
    [SerializeField]
    string m_strID;

    public PlayerController GetPlayerContorl(string id)
    {
        return m_dicPlayerController[id];
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
                break;
        }
    }

    public void EventGUIScenese(int idx)
    {
        SetGUIScene((E_GUI_STATE)idx);
    }

    public void EventShowMeTheItem()
    {
        Controller controller = GetPlayerContorl(m_strID);
        Player player = controller.Player;
        ItemIeventory itemIeventory = player.GetComponent<ItemIeventory>();
        
    }

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("GameManager.Start() 1");
        m_cItemManager.InitItemData();
        for(int i = 0;  i< m_listItemObejct.Count; i++)
        {
            m_listItemObejct[i].Item = m_cItemManager.GetItem(0);
        }
        SetGUIScene(m_eCurState);
        Debug.Log("GameManager.Start() 2");
    }

    private void Update()
    {
        UpdateGUIScene();
    }
}