using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemIeventory : MonoBehaviour
{
    [SerializeField]
    List<Item> m_listItem = null;

    public List<Item> ItemList { get { return m_listItem; } }

    public void SetIevntory(Item item)
    {
        m_listItem.Add(item);
    }

    public Item GetItem(int idx)
    {
        return m_listItem[idx];
    }

    public void Initialize(int size)
    {
        if (m_listItem != null)
        {
            m_listItem = new List<Item>(size);
        }
        else
            Debug.LogError("item list is not null !!!");
    }

    public void TestIventory(int count)
    {
        ItemManager itemManager = GameManager.GetInstance().GetItemManager();

        for(int c = 0; c < count; c++)
        {
            for(int i = 0;  i< (int)ItemManager.E_ITEM.MAX; i++)
            {
                SetIevntory(itemManager.GetItem(i));
            }
        }
    }

    //private void OnGUI()
    //{
    //    int weight = 100, height = 20;
    //    int x = 0, y = 0;

    //    for(int i = 0; i < m_listItem.Count; i++)
    //    {
    //        y = height * i;
    //        Rect rect = new Rect(x, y, weight, height);
    //        GUI.Box(rect, m_listItem[i].Name);
    //    }
    //}
}
