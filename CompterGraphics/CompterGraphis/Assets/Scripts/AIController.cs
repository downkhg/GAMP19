using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AIController : Controller
{
    public enum E_AI_STATE{ FIND, TRACKING, ATTACK, RETURN  }
    [SerializeField]
    E_AI_STATE m_eCurAIState;

    public void SetAISate(E_AI_STATE state)
    {
        //Debug.Log("SetAISate:"+state);
        switch (state)
        {
            case E_AI_STATE.FIND:
                m_objTarget = null;
                break;
            case E_AI_STATE.TRACKING:
                if(m_objTarget.transform.parent)
                    transform.LookAt(m_objTarget.transform.parent);
                break;
            case E_AI_STATE.ATTACK:

                break;
            case E_AI_STATE.RETURN:
                transform.LookAt(m_objResponPoint.transform);
                break;
        }
        m_eCurAIState = state;
    }
    public void UpdateAIState()
    {
        switch (m_eCurAIState)
        {
            case E_AI_STATE.FIND:
                if(m_objTarget == null)
                    SetAISate(E_AI_STATE.RETURN);
                break;
            case E_AI_STATE.TRACKING:
                if (m_objTarget)
                    TrackingProcess(m_objTarget);
                break;
            case E_AI_STATE.ATTACK:

                break;
            case E_AI_STATE.RETURN:
                if (TrackingProcess(m_objResponPoint) == false)
                    SetAISate(E_AI_STATE.FIND);
                break;
        }
    }
    [SerializeField]
    GameObject m_objResponPoint;
    [SerializeField]
    GameObject m_objTarget;
    [SerializeField]
    float m_fSite = 3;

    public bool FindProcess()
    {
        int nLayer = 1 << LayerMask.NameToLayer("Player");
        Collider[] colliders = Physics.OverlapSphere(transform.position, m_fSite, nLayer);

        if (colliders.Length > 0)
        {
            foreach (Collider collider in colliders)
            {
                if (ArcColCheck(collider, 120, transform.forward))
                {
                    if (RaycastWall(collider) == false)
                    {
                        m_objTarget = collider.gameObject;
                        return true;
                    }
                }
            }
        }

        m_objTarget = null;
        return false;
    }

    public bool ArcColCheck(Collider collider, float angle, Vector3 forword)
    {
        Vector3 vTargetPos = collider.transform.position;
        Vector3 vPos = this.transform.position;

        Vector3 vTargetToDist = vTargetPos - vPos;
        float fAngle = Vector3.Angle(forword, vTargetToDist);
        float fHalfAngle = angle * 0.5f;

        Debug.DrawLine(vPos, vPos + forword * m_fSite, Color.blue);
        Quaternion qRotRight = Quaternion.Euler(Vector3.up * fHalfAngle);
        Vector3 vRightDir = qRotRight * forword;
        Debug.DrawLine(vPos, vPos + vRightDir * m_fSite, Color.red);
        Quaternion qRotLeft = Quaternion.Euler(Vector3.down * fHalfAngle);
        Vector3 vLeftDir = qRotLeft * forword;
        Debug.DrawLine(vPos, vPos + vLeftDir * m_fSite, Color.red);

        if (fAngle < fHalfAngle)
        {
            Debug.DrawLine(vPos, vTargetPos, Color.green);
            return true;
        }
        Debug.DrawLine(vPos, vTargetPos, Color.gray);
        return false;
    }

    public bool RaycastWall(Collider collider)
    {
        Vector3 vTargetPos = collider.transform.position;
        Vector3 vPos = this.transform.position;

        Vector3 vTargetToDist = vTargetPos - vPos;
        RaycastHit raycastHit;
        if(Physics.Raycast(transform.position, vTargetToDist.normalized, out raycastHit, m_fSite))
        {
            if (raycastHit.transform.tag == "Wall")
            {
                Debug.Log("RaycastWall:" + raycastHit.transform.gameObject.name);
                return true;
            }
        }
        return false;
    }

    public bool TrackingProcess(GameObject objTarget)
    {
        if (Vector3.Distance(objTarget.transform.position, this.transform.position) > Time.deltaTime)
        {
            MoveProcess(Vector3.forward, m_cPlayer.Speed);
            return true;
        }
        return false;
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(transform.position, m_fSite);
    }


    private void FixedUpdate()
    {
        if (FindProcess())
            SetAISate(E_AI_STATE.TRACKING);
        //else
        //    SetAISate(E_AI_STATE.FIND);
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        UpdateAIState();
    }
}