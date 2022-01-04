using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : Controller
{
    [SerializeField]
    float m_fCurTime = -1;
    [SerializeField]
    float m_fMaxTime = 1;

    public bool UpdateTimmer(float maxtime)
    {
        if(m_fCurTime >= 0)
        {
            if(m_fCurTime <= maxtime)
            {
                m_fCurTime += Time.deltaTime;
                return false;
            }
        }
        m_fCurTime = -1;
        return true;
    }


    Vector3 vPos;
    Vector3 vTargetPos;
    public float fAngle;
    void UpdateRotationTargetProcess(Vector3 vTargetPos)
    {
        vPos = transform.position;
        Vector3 vToTarget = vTargetPos - vPos;
        Vector3 vToTargetDir = vToTarget.normalized;
        float fDist = vToTarget.magnitude;
        Vector3 vForword = Vector3.forward;
        //fAngle = Vector3.Dot(vForword, vToTarget) * Mathf.Rad2Deg;
        fAngle = Vector3.Angle(vForword, vToTargetDir);
        Vector3 vAsix = Vector3.Cross(vForword, vToTargetDir);
        //if(vAsix.y > 0)
        //    transform.localRotation = Quaternion.Euler(Vector3.up * fAngle);
        //else
        //    transform.localRotation = Quaternion.Euler(Vector3.down * fAngle);

        transform.localRotation = Quaternion.Euler(vAsix * fAngle);
        Debug.DrawLine(vPos, vPos+vForword * fDist, Color.blue);
        Debug.DrawLine(vPos, vPos+ vToTargetDir * fDist, Color.cyan);
        Debug.DrawLine(vPos, vPos + vAsix * fDist, Color.green);
    }

    public GameObject m_objTarget;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (m_objTarget)
        {
            vTargetPos = m_objTarget.transform.position;
            UpdateRotationTargetProcess(vTargetPos);
            //Debug.DrawLine(vPos, vTargetPos, Color.red);
        }

        if (Input.GetKey(KeyCode.UpArrow))
        {
            MoveProcess(Vector3.forward, m_cPlayer.Speed);
        }
        if (Input.GetKey(KeyCode.DownArrow))
        {
            MoveProcess(Vector3.back, m_cPlayer.Speed);
        }
        if (Input.GetKey(KeyCode.RightArrow))
        {
           RotateProcess(Vector3.up, m_cPlayer.AngleSpeed);
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
           RotateProcess(Vector3.down, m_cPlayer.AngleSpeed);
        }

        if (UpdateTimmer(m_fMaxTime))
        {
            if (Input.GetKeyDown(KeyCode.Space))
            {

                m_cPlayer.Shot();
                m_fCurTime = 0;

            }
        }
    }
}
