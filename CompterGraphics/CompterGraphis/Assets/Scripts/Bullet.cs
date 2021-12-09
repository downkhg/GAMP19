using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    [SerializeField]
    float m_fSpeed = 1;
    [SerializeField]
    float m_fDestroyTime;
    [SerializeField]
    bool m_bMove = false;

    IEnumerator ProcessTimmer(float time)
    {
        m_bMove = true;
        yield return new WaitForSeconds(time);
        Destroy(this.gameObject);
        m_bMove = false;
    }

    public void Initialize(float speed, float dist)
    {
        m_fDestroyTime = dist / speed;
        StartCoroutine(ProcessTimmer(m_fDestroyTime));
        //Destroy(this.gameObject);
    }

    // Update is called once per frame
    void Update()
    {
        if (m_bMove)
        {
            //transform.position += Vector3.forward * m_fSpeed * Time.deltaTime;
            transform.Translate(Vector3.forward * m_fSpeed * Time.deltaTime);
        }
    }
}
