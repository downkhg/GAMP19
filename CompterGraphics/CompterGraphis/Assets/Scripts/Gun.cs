using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    [SerializeField]
    GameObject m_objBullet;
    [SerializeField]
    Transform m_transMozzle;
    [SerializeField]
    float m_fShotSpeeed = 1;
    [SerializeField]
    float m_fShotDist = 1;

    public void Shot(Player master, GameObject target)
    {
        GameObject objBullet = Instantiate(m_objBullet, m_transMozzle.position, Quaternion.identity);
        Bullet bullet = objBullet.GetComponent<Bullet>();
        bullet.Initialize(master, m_fShotSpeeed, m_fShotDist);
        if (target) objBullet.transform.LookAt(target.transform);
        else objBullet.transform.LookAt(m_transMozzle.position + m_transMozzle.forward);
    }
}
