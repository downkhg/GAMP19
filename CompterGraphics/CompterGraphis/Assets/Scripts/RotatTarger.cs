using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RotatTarger : MonoBehaviour
{
    public GameObject objTarget;
    public float fDist;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 vTargetPos = objTarget.transform.position;
        Vector3 vCamPos = this.transform.position;

        Vector3 vDist = vCamPos - vTargetPos;
        Vector3 vDir = vDist.normalized;
        Quaternion qRot = Quaternion.Euler(Vector3.up);
        Vector3 vRotDir = qRot * vDir;
        vCamPos = vTargetPos + vRotDir * fDist;
        //vCamPos = vTargetPos + vDir * fDist;

        transform.LookAt(objTarget.transform);
        this.transform.position = vCamPos;
    }
}
