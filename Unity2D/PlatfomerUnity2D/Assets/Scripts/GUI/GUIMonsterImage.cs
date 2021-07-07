using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class GUIMonsterImage : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
{
    public Image imgMonster;
    public GUIMonsterInfo gulMonsterInfo;

    public void SetMonster(string _imagename)
    {
        Debug.Log("SetMonster:"+_imagename);
        Sprite spriteMonster = Resources.Load<Sprite>("MonsterImage/" + _imagename);
        imgMonster.sprite = spriteMonster;
    }

    // Start is called before the first frame update
    void Start()
    {
        //imgMonster = GetComponent<Image>();
        //SetMonster("frog"); //작은기능단위에서 테스트가 끝나고 사용할것!
        //SetMonster("eagle"); //작은기능단위에서 테스트가 끝나고 사용할것
        //SetMonster("opossum"); //작은기능단위에서 테스트가 끝나고 사용할것
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        Debug.Log("OnPointerDown");
        gulMonsterInfo.gameObject.SetActive(true);
        gulMonsterInfo.SetMonsterInfo(gameObject.name);
        //SetMonsterInfo(gameObject.name);

        //throw new System.NotImplementedException();
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        Debug.Log("OnPointerUp");
        gulMonsterInfo.gameObject.SetActive(false);
        //throw new System.NotImplementedException();
    }
}
