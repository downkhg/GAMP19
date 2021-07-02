using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIStateBar : MonoBehaviour
{
    public RectTransform recttrStateBar;
    public RectTransform recttrBackGourndBar;
    public Text textName;
    public Vector2 vMaxBarSize;

    public void Init()
    {
        vMaxBarSize = recttrStateBar.sizeDelta;
        textName.text = gameObject.name;
    }

    public void SetState(float cur, float max)
    {
        float rat = cur / max; //0.5
        Vector2 vSize = recttrStateBar.sizeDelta; //100 //50
        vSize.x = recttrBackGourndBar.sizeDelta.x * rat;
        recttrStateBar.sizeDelta = vSize; //50 //25
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
