using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIInventory : MonoBehaviour
{
    public List<GUIMonsterImage> listGUIMonsterImage;
    public RectTransform recttrGridLayoutGroup;

    public void SetIventory(GUIMonsterInfo guiMonsterInfo)
    {
        List<string> listMonsterPedia = GameManager.GetInstance().listMonsterPedia;
        Debug.Log("GUIInventory.SetIventory:" + listMonsterPedia.Count);
        GameObject prefabMonsterImage = Resources.Load("GUI/MonsterImage") as GameObject;
        foreach (string monstername in listMonsterPedia)
        {
            GameObject objMonsterImage = Instantiate(prefabMonsterImage);
            objMonsterImage.transform.SetParent(recttrGridLayoutGroup);
            GUIMonsterImage guiMonsterImage = objMonsterImage.GetComponent<GUIMonsterImage>();
            guiMonsterImage.SetMonster(monstername);
            guiMonsterImage.gulMonsterInfo = guiMonsterInfo;
            listGUIMonsterImage.Add(guiMonsterImage);
            objMonsterImage.name = monstername;
        }
        Debug.Log("GUIInventory.SetIventory:" + listGUIMonsterImage.Count);
        ResizeContent(listGUIMonsterImage.Count);
    }

    public void DeleteIventory()
    {
        Debug.Log("GUIInventory.DeleteIventory:" + listGUIMonsterImage.Count);
        foreach (var item in listGUIMonsterImage)
        {
            Destroy(item.gameObject);
        }
        listGUIMonsterImage.Clear();
        Debug.Log("GUIInventory.DeleteIventory:" + listGUIMonsterImage.Count);
    }

    public void ResizeContent(int monstersize)
    {
        Vector2 vRectSize = recttrGridLayoutGroup.sizeDelta;
        Vector2 vCellSize = recttrGridLayoutGroup.GetComponent<GridLayoutGroup>().cellSize;

        int nRowCount = (int)vRectSize.x / (int)vCellSize.x; //600/200 = 3
        int nColCount = monstersize / nRowCount;
        if (monstersize % nRowCount > 0) nColCount++;

        vRectSize.y = vCellSize.x * nColCount;
        recttrGridLayoutGroup.sizeDelta = vRectSize;
    }

    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        //if(Input.GetKeyDown(KeyCode.I))
        //    SetIventory();
    }
}
