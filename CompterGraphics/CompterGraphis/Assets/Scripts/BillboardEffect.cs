using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BillboardEffect : MonoBehaviour
{
    // Start is called before the first frame update
    public Camera m_camera;
    void Start()
    {
        Debug.Log("BillboardEffect:"+gameObject.name);
    }

    // Update is called once per frame
    void Update()
    {
        if(m_camera)
            transform.LookAt(m_camera.transform);
    }
}
