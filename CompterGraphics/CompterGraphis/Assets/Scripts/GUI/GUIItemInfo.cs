using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemInfo : MonoBehaviour
{
    [SerializeField]
    Image m_imgSprite;
    [SerializeField]
    Text m_textStatus;
    [SerializeField]
    Text m_textInfo;

    public void Initialize(Item item)
    {
        m_textStatus.text = item.Status.ToString();// ToStatusText() ;
        m_textInfo.text = item.Info;
        m_imgSprite.sprite = item.Sprite;
    }

    // Update is called once per frame
    //void Update()
    //{
    //    Item item = GameManager.GetInstance().GetItemManager().GetItem(0);
    //    Initialize(item);
    //}
}
