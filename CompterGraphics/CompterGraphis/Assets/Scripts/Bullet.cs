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
    [SerializeField]
    Player m_cMaster;

    IEnumerator ProcessTimmer(float time)
    {
        m_bMove = true;
        yield return new WaitForSeconds(time);
        Destroy(this.gameObject);
        m_bMove = false;
    }

    public void Initialize(Player master, float speed, float dist)
    {
        m_cMaster = master;
        m_fDestroyTime = dist / speed;
        gameObject.tag = m_cMaster.gameObject.tag;
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

    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag != this.gameObject.tag)
        {
            Player target = other.gameObject.GetComponent<Player>();
            m_cMaster.Attack(target);
        }
    }
}
