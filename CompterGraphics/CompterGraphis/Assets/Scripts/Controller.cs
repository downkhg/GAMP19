using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Controller : MonoBehaviour
{
    [SerializeField]
    protected Dynamic m_cDynmaic;

    public void MoveProcess(Vector3 dir, float speed)
    {
        transform.Translate(dir * speed * Time.deltaTime);
    }

    public void RotateProcess(Vector3 axis, float angle)
    {
        transform.Rotate(axis * angle);
    }
}
