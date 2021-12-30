using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : Controller
{
    [SerializeField]
    float m_fCurTime = -1;
    [SerializeField]
    float m_fMaxTime = 1;

    public bool UpdateTimmer(float maxtime)
    {
        if(m_fCurTime >= 0)
        {
            if(m_fCurTime <= maxtime)
            {
                m_fCurTime += Time.deltaTime;
                return false;
            }
        }
        m_fCurTime = -1;
        return true;
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.UpArrow))
        {
            MoveProcess(Vector3.forward, m_cPlayer.Speed);
        }
        if (Input.GetKey(KeyCode.DownArrow))
        {
            MoveProcess(Vector3.back, m_cPlayer.Speed);
        }
        if (Input.GetKey(KeyCode.RightArrow))
        {
           RotateProcess(Vector3.up, m_cPlayer.AngleSpeed);
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
           RotateProcess(Vector3.down, m_cPlayer.AngleSpeed);
        }

        if (UpdateTimmer(m_fMaxTime))
        {
            if (Input.GetKeyDown(KeyCode.Space))
            {

                m_cPlayer.Shot();
                m_fCurTime = 0;

            }
        }
    }
}
