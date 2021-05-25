using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float Speed;
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
        if (Input.GetKey(KeyCode.UpArrow))
            transform.position += Vector3.up * Speed * Time.deltaTime;
        if (Input.GetKey(KeyCode.DownArrow))
            transform.position += Vector3.down * Speed * Time.deltaTime;
    }
}
