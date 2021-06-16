using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TrackerCamera : MonoBehaviour
{
    public GameObject objTarget;
    public float Speed = 1;

    // Update is called once per frame
    void Update()
    {
        if (objTarget != null)
        {
            Vector3 vCamPos = this.transform.position;
            Vector3 vTargetPos = objTarget.transform.position;
            vTargetPos.z = vCamPos.z;
            Vector3 vDist = vTargetPos - vCamPos;
            Vector3 vDir = vDist.normalized;
            float fDist = vDist.magnitude;

            //틱당 이동량만큼 이동을 덜한경우는 도달한것 으로 처리한다.
            if (fDist > Speed * Time.deltaTime)
                transform.position += vDir * Speed * Time.deltaTime;
        }
    }
}
