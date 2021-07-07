using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float Speed;
    public float JumpPower;
    public bool isJump = false;
    public bool isLadder = false;
    public bool isHouse = false;

    public int Score = 0;

    public Gun gun;

    public Vector3 dir;

    // Start is called before the first frame update
    void Start()
    {
        //transform.position += Vector3.right;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Z))
            gun.Shot(dir,GetComponent<Player>());

        if (Input.GetKey(KeyCode.S))
        {
            gun.LaserShot(GetComponent<Player>(), dir, 999999);
        }

        //왼쪽, 위,아래 모두 추가하기
        if (Input.GetKey(KeyCode.RightArrow))
        {
            //transform.Rotate(Vector3.up * 180);
            transform.localRotation = Quaternion.Euler(Vector3.zero);
            transform.position += Vector3.right * Speed * Time.deltaTime;
            dir = Vector3.right;
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            //transform.Rotate(Vector3.up * 180);
            transform.localRotation = Quaternion.Euler(Vector3.up * 180);
            transform.position += Vector3.left * Speed * Time.deltaTime;
            dir = Vector3.left;
        }
        
        if (Input.GetKeyDown(KeyCode.Space))
        {
            if (isHouse)
            {
                GameManager.GetInstance().guiManager.SetScence(GUIManager.E_GUISCENCE_STATE.THEEND);
            }
            else
            {
                if (isJump == false)
                {
                    Rigidbody2D rigidbody = GetComponent<Rigidbody2D>();
                    rigidbody.AddForce(Vector3.up * JumpPower);
                    isJump = true;
                    //transform.position += Vector3.up * JumpPower * Time.deltaTime;
                }
            }
        }

        if(isLadder)
        {
            if (Input.GetKey(KeyCode.UpArrow))
                transform.position += Vector3.up * Speed * Time.deltaTime;
            if (Input.GetKey(KeyCode.DownArrow))
                transform.position += Vector3.down * Speed * Time.deltaTime;
        }
        
        if (Input.GetKey(KeyCode.DownArrow))
            transform.position += Vector3.down * Speed * Time.deltaTime;
    }

    private void OnGUI()
    {
        GUI.Box(new Rect(0, 0, 100, 20), "Score:" + Score);
    }

    //private void OnTriggerEnter2D(Collider2D collision)
    //{
    //    //if (collision.gameObject.name == "cherry")
    //    if (collision.gameObject.tag == "Item")
    //    {
    //        Score++;
    //        Destroy(collision.gameObject);
    //    }
    //}
    //트리거스테이는 매프레임마다 발생하지않으므로 주의해서 사용할것!
    //private void OnTriggerStay2D(Collider2D collision)
    //{
    //    if(collision.gameObject.name == "Ladder")
    //    {
            
    //        Rigidbody2D rigidbody = GetComponent<Rigidbody2D>();
    //        rigidbody.gravityScale = 0;
    //        rigidbody.velocity = Vector2.zero;
    //    }
    //    Debug.Log("OnTriggerStay2D:" + collision.gameObject.name);
    //}

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (isJump == false)
        {
            if (collision.gameObject.name == "Ladder")
            {
                Rigidbody2D rigidbody = GetComponent<Rigidbody2D>();
                rigidbody.gravityScale = 0;
                rigidbody.velocity = Vector2.zero;
                isLadder = true;
            }
        }

        if(collision.gameObject.name == "house")
        {
            isHouse = true;
        }
        //Debug.Log("OnTriggerExit2D:" + collision.gameObject.name);
    }
    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.name == "Ladder")
        {
            Rigidbody2D rigidbody = GetComponent<Rigidbody2D>();
            rigidbody.gravityScale = 1;
            rigidbody.velocity = Vector2.zero;
            isLadder = false;
        }
        //Debug.Log("OnTriggerExit2D:" + collision.gameObject.name);
        if (collision.gameObject.name == "house")
        {
            isHouse = false;
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        isJump = false;
      
        //Debug.Log("OnCollisionEnter2D:" + collision.gameObject.name);
    }

    private void OnCollisionExit2D(Collision2D collision)
    {
        //isJump = true; //땅에서 나갔다고 해서 점프인가?
        //Debug.Log("OnCollisionExit2D:" + collision.gameObject.name);
    }
}
