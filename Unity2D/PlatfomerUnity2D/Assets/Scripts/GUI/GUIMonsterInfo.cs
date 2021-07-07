using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class GUIMonsterInfo : MonoBehaviour
{
    public Text textMonsterInfo;

    public void SetMonsterInfo(string name)
    {
        MonsterInfo monsterInfo = GameManager.GetInstance().monsterManager.GetMonster(name);
        if (monsterInfo != null)
            textMonsterInfo.text = monsterInfo.comment;
    }

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (gameObject.activeSelf)
        {
            Vector3 vMousePos = Input.mousePosition;
            transform.position = vMousePos;
        }
    }
}
