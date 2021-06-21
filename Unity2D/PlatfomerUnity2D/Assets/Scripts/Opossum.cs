using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Opossum : MonoBehaviour
{
    public float Speed = 2;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //if (Input.GetKey(KeyCode.LeftArrow))
        transform.position += Vector3.left * Speed * Time.deltaTime;
    }

    private void FixedUpdate()
    {
        BoxCollider2D box = GetComponent<BoxCollider2D>();
        int nLayer = 1 << LayerMask.NameToLayer("Player");
        Collider2D collider = 
            Physics2D.OverlapBox(transform.position, box.size,0, nLayer);
        if(collider)
        {
            Player monster = this.GetComponent<Player>();
            Player player = collider.gameObject.GetComponent<Player>();

            SuperMode superMode = player.GetComponent<SuperMode>();
            if (superMode != null && superMode.isOn == false)
            {
                monster.Attack(player);
                superMode.SetMode();
            }
        }
    }

    //private void OnCollisionEnter2D(Collision2D collision)
    //{
    //    if (collision.gameObject.tag == "Player")
    //    {
    //        //Destroy(collision.gameObject);
    //        Player monster = this.GetComponent<Player>();
    //        Player player = collision.gameObject.GetComponent<Player>();

    //        monster.Attack(player);
    //    }
    //}
}
