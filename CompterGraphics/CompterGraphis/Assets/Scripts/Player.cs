﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    [SerializeField]
    float m_fSpeed = 1;
    [SerializeField]
    float m_fAngleSpeed = 1;
    [SerializeField]
    Gun m_cGun;

    public Gun GetGun()
    {
        return m_cGun;
    }

    public void Shot()
    {
        m_cGun.Shot();
    }

    public float Speed
    {
        get { return m_fSpeed; }
        //set { m_fSpeed = value; }
    }

    public float AngleSpeed
    {
        get { return m_fAngleSpeed; }
        //set { m_fSpeed = value; }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //transform.position += Vector3.forward;
        //transform.position += Vector3.back;

        //1,3인칭에서는 회전한 케릭터가 바라보는 방향으로 이동한다.
        ////그러므로, 로컬좌표를 이용하여 이동한다.
        //if(Input.GetKey(KeyCode.UpArrow))
        //{
        //    transform.Translate(Vector3.forward * Time.deltaTime);
        //    //transform.position = transform.position + Vector3.forward * Time.deltaTime;
        //    //transform.position += Vector3.forward * Time.deltaTime;
        //}
        //if (Input.GetKey(KeyCode.DownArrow))
        //{
        //    transform.Translate(Vector3.forward * Time.deltaTime);
        //    //transform.position += Vector3.back * Time.deltaTime;
        //}
        //if (Input.GetKey(KeyCode.RightArrow))
        //{
        //    transform.Rotate(Vector3.up);
        //}
        //if (Input.GetKey(KeyCode.LeftArrow))
        //{
        //    transform.Rotate(Vector3.down);
        //}
    }

  
}