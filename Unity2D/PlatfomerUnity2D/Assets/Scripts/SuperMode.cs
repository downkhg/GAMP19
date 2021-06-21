using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SuperMode : MonoBehaviour
{
    public float Time;
    public bool isOn;
    // Start is called before the first frame update
    void Start()
    {
        if(isOn)
            SetMode();
    }

    public void Update()
    {
        if(isOn)
        {
            Color color = GetComponent<SpriteRenderer>().color;
            if (color.a == 0)
                color.a = 1;
            else
                color.a = 0;
            GetComponent<SpriteRenderer>().color = color;
        }
    }

    public void SetMode()
    {
        StartCoroutine(ProcessTimmer());
    }

    IEnumerator ProcessTimmer()
    {
        Debug.Log("ProcessTimmer Start!");
        isOn = true;
        yield return new WaitForSeconds(Time);
        GetComponent<SpriteRenderer>().color = Color.white;
        isOn = false;
        Debug.Log("ProcessTimmer End!");
    }
}
