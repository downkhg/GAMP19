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

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            //에셋폴더에서 프리팹읽어보기
            GameObject prefab = 
                Resources.Load("Prefabs/" + collision.gameObject.name) as GameObject;

            Destroy(collision.gameObject);
            //읽은 프래팹을 복제
            Instantiate(prefab);
        }
    }
}
