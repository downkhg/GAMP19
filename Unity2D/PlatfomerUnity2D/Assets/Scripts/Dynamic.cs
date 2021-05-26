using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float Speed;
    public float JumpPower;
    public bool isJump = false;
    // Start is called before the first frame update
    void Start()
    {
        //transform.position += Vector3.right;
    }

    // Update is called once per frame
    void Update()
    {
        //왼쪽, 위,아래 모두 추가하기
        if (Input.GetKey(KeyCode.RightArrow))
            transform.position += Vector3.right * Speed * Time.deltaTime;
        if (Input.GetKey(KeyCode.LeftArrow))
            transform.position += Vector3.left * Speed * Time.deltaTime;
        
        if (Input.GetKeyDown(KeyCode.UpArrow))
        {
            if (isJump == false)
            {
                Rigidbody2D rigidbody = GetComponent<Rigidbody2D>();
                rigidbody.AddForce(Vector3.up * JumpPower);
                isJump = true;
                //transform.position += Vector3.up * JumpPower * Time.deltaTime;
            }
        }
        
        if (Input.GetKey(KeyCode.DownArrow))
            transform.position += Vector3.down * Speed * Time.deltaTime;
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        isJump = false;
        Debug.Log("OnCollisionEnter2D:" + collision.gameObject.name);
    }

    private void OnCollisionExit2D(Collision2D collision)
    {
        //isJump = true; //땅에서 나갔다고 해서 점프인가?
        Debug.Log("OnCollisionExit2D:" + collision.gameObject.name);
    }
}
