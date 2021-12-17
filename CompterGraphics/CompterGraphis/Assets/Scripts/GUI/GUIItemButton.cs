using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemButton : MonoBehaviour
{
    [SerializeField]
    Text m_textName;

    public void Initialize(Item item)
    {
        m_textName.text = item.Name;
    }

    //// Update is called once per frame
    //void Update()
    //{
    //    Item item = GameManager.GetInstance().GetItemManager().GetItem(0);
    //    Initialize(item);
    //}
}
