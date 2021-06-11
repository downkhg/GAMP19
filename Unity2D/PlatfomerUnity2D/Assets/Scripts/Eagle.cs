using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Eagle : MonoBehaviour
{
    public GameObject objTarget;
    public float Speed;

    public float Site = 0.5f;

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
        if (objTarget != null)
        {
            Vector3 vPos = this.transform.position;
            Vector3 vTargetPos = objTarget.transform.position;
            Vector3 vDist = vTargetPos - vPos;
            Vector3 vDir = vDist.normalized;
            float fDist = vDist.magnitude;

            //틱당 이동량만큼 이동을 덜한경우는 도달한것 으로 처리한다.
            if (fDist > Speed * Time.deltaTime)
                transform.position += vDir * Speed * Time.deltaTime;
        }
    }
    private void OnTriggerEnter2D(Collider2D collision)
    {
        Destroy(collision.gameObject);
    }
}
