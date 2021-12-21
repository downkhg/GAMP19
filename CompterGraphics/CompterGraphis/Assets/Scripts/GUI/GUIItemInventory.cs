using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemInventory : MonoBehaviour
{
    [SerializeField]
    List<GUIItemButton> m_listGuiItemButton;
    [SerializeField]
    GridLayoutGroup m_gridLayoutGroup;

    public void Initialize(int count)
    {
        m_listGuiItemButton = new List<GUIItemButton>(count);
    }

    public void SetItems(ItemIeventory itemIeventory)
    {
        GameObject prefabButton = Resources.Load("Prefabs/GUI/GUIItemButton") as GameObject;
        List<Item> items = itemIeventory.ItemList;

        for(int i =0; i < items.Count; i++)
        {
            GameObject objButton = Instantiate(prefabButton, m_gridLayoutGroup.transform);
            GUIItemButton guiItemButton = objButton.GetComponent<GUIItemButton>();
            guiItemButton.Initialize(items[i]);
            m_listGuiItemButton.Add(guiItemButton);
            //objButton.transform.SetParent(m_gridLayoutGroup.gameObject.transform);
        }
        ResizeContent();
    }

    public void ResizeContent()
    {
        RectTransform rectContent = m_gridLayoutGroup.gameObject.GetComponent<RectTransform>();
        int nCol = (int)(rectContent.sizeDelta.x / m_gridLayoutGroup.cellSize.x);
        int nRow = m_listGuiItemButton.Count / nCol;
        if (m_listGuiItemButton.Count % nCol > 0) nRow++;
        float fHeight = nRow * m_gridLayoutGroup.cellSize.y;
        rectContent.sizeDelta = new Vector2(rectContent.sizeDelta.x, fHeight);
    }
}
