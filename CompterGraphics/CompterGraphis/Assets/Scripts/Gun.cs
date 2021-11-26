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
    float m_fShotPower = 300;

    public void Shot()
    {
        GameObject objBullet = Instantiate(m_objBullet, m_transMozzle.position, Quaternion.identity);
        Rigidbody rigidbody = objBullet.GetComponent<Rigidbody>();
        rigidbody.AddForce(transform.forward * m_fShotPower);
    }
}
