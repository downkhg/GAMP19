using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public Gun gun;
    Vector3 vStartPos;
    // Start is called before the first frame update
    void Start()
    {
        //유효사거리를 활용하기에는 부족하다.
        //Destroy(gameObject, 1);
        
        vStartPos = this.transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 vCurPos = this.transform.position;
        Vector3 vDist = vCurPos - vStartPos; //두벡터의 차를 구해 방향이있는 벡터를 구함.
        //float fDist = vDist.magnitude; //벡터의 스칼라(순수이동량)을 구한다.
        float fDist = Vector3.Distance(vStartPos,vCurPos);

        if (fDist >= gun.Range)
        {
            Destroy(this.gameObject);
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.tag == "Monster")
            Destroy(collision.gameObject);
    }
}
