using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIItemInventory : MonoBehaviour
{
    [SerializeField]
    List<GUIItemButton> m_listGuiItemButton;

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
            GameObject objButton = Instantiate(prefabButton);
            GUIItemButton guiItemButton = objButton.GetComponent<GUIItemButton>();
            guiItemButton.Initialize(items[i]);
            m_listGuiItemButton.Add(guiItemButton);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
