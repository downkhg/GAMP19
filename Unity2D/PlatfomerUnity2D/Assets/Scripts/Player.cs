using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public int HP = 100;
    public int Atk = 10;
    public int MP = 100;

    public int Lv = 10;
    public int Exp = 0;

    public int idxDegugGUI = 0;
    private void OnGUI()
    {
        int nWidth = 100;
        int nHeight = 20;
        int nV = 0;
        GUI.Box(new Rect(nWidth * idxDegugGUI, nHeight * nV, nWidth, nHeight), string.Format("{0}", gameObject.name)); nV++;
        GUI.Box(new Rect(nWidth * idxDegugGUI, nHeight * nV, nWidth, nHeight),string.Format("HP:{0}", HP)); nV++;
        GUI.Box(new Rect(nWidth * idxDegugGUI, nHeight * nV, nWidth, nHeight), string.Format("ATK:{0}", Atk)); nV++;
        GUI.Box(new Rect(nWidth * idxDegugGUI, nHeight * nV, nWidth, nHeight), string.Format("MP:{0}", MP)); nV++;
        GUI.Box(new Rect(nWidth * idxDegugGUI, nHeight * nV, nWidth, nHeight), string.Format("Lv/Exp:{0}/{1}", Lv, Exp)); nV++;
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
