using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AIController : Controller
{
    public enum E_AI_STATE{  }
    [SerializeField]
    E_AI_STATE m_eCurAIState;

    public void SetAISate(E_AI_STATE state)
    {
        m_eCurAIState = state;
    }

    public void UpdateAIState()
    {

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
