using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    [SerializeField]
    GameObject m_objTarget;
    [SerializeField]
    float m_fTime = 1;
    [SerializeField]
    bool m_bRespon = false;

    IEnumerator ProcessTimmer(float time)
    {
        Hide();
        yield return new WaitForSeconds(time);
        Show();
    }

    void Show()
    {
        Debug.Log(gameObject.name+".Show:"+m_objTarget.name);
        m_objTarget.transform.position = this.transform.position;
        m_objTarget.SetActive(true);
        m_bRespon = false;
    }

    void Hide()
    {
        Debug.Log(gameObject.name + ".Hide:" + m_objTarget.name);
        m_objTarget.SetActive(false);
        //C# 클래스는 참조되고 구조체는 복사된다.
        //m_objTarget.transform.z -= 1000; //임시객체의 z값을 변경해도 원본은 변경되지않음.
        m_objTarget.transform.position += Vector3.down * 1000; //transfrom이 가진 position에 Vector임시벡터 값을 할당한다.
        m_bRespon = true;
    }

    void Update()
    {
        if(m_objTarget.activeSelf == false && m_bRespon == false)
        {
            StartCoroutine(ProcessTimmer(m_fTime));
        }
    }
}
