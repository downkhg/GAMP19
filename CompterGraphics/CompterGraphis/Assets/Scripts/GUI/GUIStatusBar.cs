using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIStatusBar : MonoBehaviour
{
    [SerializeField]
    Text m_textStatusName;
    [SerializeField]
    Image m_imgStatusBar;
    [SerializeField]
    RectTransform m_rectStatusBarBG;

    public void Initialize(string name, Color color)
    {
        m_textStatusName.text = name;
        m_imgStatusBar.color = color;
    }

    public void UpdateStatus(float cur, float max)
    {
        RectTransform rectTransformStatusBar = m_imgStatusBar.gameObject.GetComponent<RectTransform>();
        Vector2 vSize = rectTransformStatusBar.sizeDelta;
        float fRat = cur / max;
        vSize.x = m_rectStatusBarBG.sizeDelta.x * fRat;
        rectTransformStatusBar.sizeDelta = vSize;
    }
}
