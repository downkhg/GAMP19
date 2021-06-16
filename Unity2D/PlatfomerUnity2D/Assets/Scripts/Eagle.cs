using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Eagle : MonoBehaviour
{
    public GameObject objTarget;
    public float Speed;

    public float Site = 0.5f;

    public GameObject objResponPoint;
    public GameObject objPatrolPoint;

    public bool isMove = false;


    public enum E_AI_STATE { NONE = -1, ATTACK, RETRUN, POTROL }
    public E_AI_STATE eAIState;
    public void SetAIState(E_AI_STATE state)
    {
        Debug.Log("SetAIState:" + state);
        switch(state)
        {
            case E_AI_STATE.ATTACK:
                break;
            case E_AI_STATE.RETRUN:
                objTarget = objResponPoint;
                break;
            case E_AI_STATE.POTROL:
                break;
        }
        eAIState = state;
    }

    public void UpdateState()
    {
        switch (eAIState)
        {
            case E_AI_STATE.ATTACK:
                if (!objTarget)
                    SetAIState(E_AI_STATE.RETRUN);
                break;
            case E_AI_STATE.RETRUN:
                if (isMove == false)
                    SetAIState(E_AI_STATE.POTROL);
                break;
            case E_AI_STATE.POTROL:
                ProcessPatrol(objResponPoint, objPatrolPoint);
                break;
        }
    }

    private void FixedUpdate()
    {
        ProcessFindTarget("Player");
        //ProcessFindTargetAll();
    }
    void ProcessFindTarget(string layername)
    {
        int nLayer = 1 << LayerMask.NameToLayer(layername);
        Collider2D collider = Physics2D.OverlapCircle(transform.position, Site, nLayer);
        //Collider2D collider = Physics2D.OverlapCircle(transform.position, Site);//, nLayer);
        if (collider)
        {
            objTarget = collider.gameObject;
            SetAIState(E_AI_STATE.ATTACK);
        }
    }
    void ProcessFindTargetAll()
    {
        Collider2D[] colliders = Physics2D.OverlapCircleAll(transform.position, Site);
        if (colliders.Length > 0)
        {
            for (int i = 0; i < colliders.Length; i++)
            {
                Collider2D collider = colliders[i];
                if (collider.tag == "Player")
                {
                    objTarget = collider.gameObject;
                    break;
                }
                else
                    Debug.Log("Collider:" + collider.name);
            }
        }
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(transform.position, Site);   
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        bool bCheckTarget = ProcessMoveTarget();

        UpdateState();
    }

    bool ProcessMoveTarget()//타겟이 없다면 false를 반환한다.
    {
        if (objTarget != null)
        {
            Vector3 vPos = this.transform.position;
            Vector3 vTargetPos = objTarget.transform.position;
            Vector3 vDist = vTargetPos - vPos;
            Vector3 vDir = vDist.normalized;
            float fDist = vDist.magnitude;

            //틱당 이동량만큼 이동을 덜한경우는 도달한것 으로 처리한다.
            if (fDist > Speed * Time.deltaTime)
            {
                transform.position += vDir * Speed * Time.deltaTime;
                isMove = true;
            }
            else
                isMove = false;

            return true;
        }
        return false;
    }

    void ProcessPatrol(GameObject objA, GameObject objB)
    {
        if(objA.name == objTarget.name)
        {
            if (isMove == false)
                objTarget = objB;
        }
        else if (objB.name == objTarget.name)
        {
            if (isMove == false)
                objTarget = objA;
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Destroy(collision.gameObject);
    }
}
