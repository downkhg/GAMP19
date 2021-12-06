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

    // Update is called once per frame
    void Update()
    {
        
    }
}
