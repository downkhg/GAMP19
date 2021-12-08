using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    [SerializeField]
    List<ItemObejct> m_listItemObejct;
    [SerializeField]
    ItemManager m_cItemManager;

    public ItemManager GetItemManager() { return m_cItemManager; }
    public List<ItemObejct> GetItemObejcts() { return m_listItemObejct; }
    //싱글톤패턴: 엄격한 싱글톤이라 말할수 없지만, 접근의 용이함을 활용하기위해 싱글톤화함.
    //디자인패턴은 무조건 엄격하게적용할것이 아니라 사용성에 맞게 적절히 방법이 변경되는 경우가 많음.
    static GameManager m_cInstance;

    static public GameManager GetInstance()
    {
        return m_cInstance;
    }

    private void Awake()
    {
        m_cInstance = this;
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
        Debug.Log("GameManager.Start() 2");
    }
}
