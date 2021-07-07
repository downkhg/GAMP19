using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    public GameObject objBullet;
    public float ShotPower;
    public float Range;

    public void Shot(Vector3 dir, Player player)
    {
        GameObject copyBullet = Instantiate(objBullet);
        copyBullet.transform.position = this.transform.position;
        Rigidbody2D rigidbody = copyBullet.GetComponent <Rigidbody2D>();
        rigidbody.AddForce(dir * ShotPower);
        Bullet bullet = copyBullet.GetComponent<Bullet>();
        bullet.gun = this;
        bullet.master = player;
    }

    public void LaserShot(Player player, Vector3 dir, float dist)
    {
        Vector3 vPos = this.transform.position;

        RaycastHit2D raycastHit =
            Physics2D.Raycast(vPos, dir, dist, 1 << LayerMask.NameToLayer("Monster"));

        LineRenderer lineRenderer = GetComponent<LineRenderer>();
        lineRenderer.SetPosition(0, vPos);

        //Debug.DrawLine(vPos, vPos + dir * dist, Color.red);
        if (raycastHit.collider)
        {
            lineRenderer.endColor = Color.red;
            lineRenderer.SetPosition(1, raycastHit.point);

            Debug.DrawLine(vPos, raycastHit.point, Color.green);
            Player monster = raycastHit.collider.gameObject.GetComponent<Player>();

            SuperMode superMode = monster.GetComponent<SuperMode>();
            if (superMode && !superMode.isOn)
            {
                player.Attack(monster);
                superMode.SetMode();
            }
        }
        else
        {
            lineRenderer.endColor = Color.green;

            lineRenderer.SetPosition(1, vPos + dir * dist);
            Debug.DrawLine(vPos, vPos + dir * dist, Color.red);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
      
    }
}
