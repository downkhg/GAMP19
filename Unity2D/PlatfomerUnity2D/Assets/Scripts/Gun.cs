using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    public GameObject objBullet;
    public float ShotPower;
    public float Range;

    public void Shot(Vector3 dir)
    {
        GameObject copyBullet = Instantiate(objBullet);
        copyBullet.transform.position = this.transform.position;
        Rigidbody2D rigidbody = copyBullet.GetComponent <Rigidbody2D>();
        rigidbody.AddForce(dir * ShotPower);
        Bullet bullet = copyBullet.GetComponent<Bullet>();
        bullet.gun = this;
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
