using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HingeJointController : MonoBehaviour
{
    public HingeJoint2D hingeJoint;
    public float Power = 100;

    // Start is called before the first frame update
    void Start()
    {
        hingeJoint = GetComponent<HingeJoint2D>();
    }

    // Update is called once per frame
    void Update()
    {
        if (hingeJoint == null)
        {
            Debug.LogError("HingeJoint2D is Empty!!!");
            return;
        }

        if(Input.GetKeyDown(KeyCode.Space))
        {
            Rigidbody2D rigidbody = hingeJoint.connectedBody;
            rigidbody.AddForce(Vector3.right * Power);
        }
    }
}
