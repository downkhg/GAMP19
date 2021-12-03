using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemObejct : MonoBehaviour
{
    [SerializeField]
    Item m_cItem;
    public Item Item { get { return m_cItem; } set { m_cItem = value; } }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
