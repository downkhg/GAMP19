using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    [SerializeField]
    Status m_sStatus;
    [SerializeField]
    int m_nMaxHP;
    [SerializeField]
    int m_nMaxMP;
    [SerializeField]
    int m_nMaxExp;
    [SerializeField]
    int m_nExp;
    [SerializeField]
    int m_nLv;

    [SerializeField]
    float m_fSpeed = 1;
    [SerializeField]
    float m_fAngleSpeed = 1;
    [SerializeField]
    Gun m_cGun;
    [SerializeField]
    ItemIeventory m_cItemInventory;
   
    public Status Status { set { m_sStatus = value; } get { return m_sStatus; } }
    public int MaxHP { get { return m_nMaxHP; } }
    public int MaxMP { get { return m_nMaxMP; } }
    public int MaxExp { get { return m_nMaxExp; } }
    public int Exp { get { return m_nExp; } }
    public int Lv { get { return m_nLv; } }

    public void Attack(Player taget)
    {
        taget.m_sStatus.nHP -= m_sStatus.nStr - m_sStatus.nDef;
    }

    public ItemIeventory GetItemIventory()
    {
        return m_cItemInventory;
    }

    public Gun GetGun()
    {
        return m_cGun;
    }

    public void Shot(GameObject target = null)
    {
        m_cGun.Shot(this,target);
    }

    public float Speed
    {
        get { return m_fSpeed; }
        //set { m_fSpeed = value; }
    }

    public float AngleSpeed
    {
        get { return m_fAngleSpeed; }
        //set { m_fSpeed = value; }
    }

    private void Awake()
    {
        m_cItemInventory = GetComponent<ItemIeventory>();
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //transform.position += Vector3.forward;
        //transform.position += Vector3.back;

        //1,3인칭에서는 회전한 케릭터가 바라보는 방향으로 이동한다.
        ////그러므로, 로컬좌표를 이용하여 이동한다.
        //if(Input.GetKey(KeyCode.UpArrow))
        //{
        //    transform.Translate(Vector3.forward * Time.deltaTime);
        //    //transform.position = transform.position + Vector3.forward * Time.deltaTime;
        //    //transform.position += Vector3.forward * Time.deltaTime;
        //}
        //if (Input.GetKey(KeyCode.DownArrow))
        //{
        //    transform.Translate(Vector3.forward * Time.deltaTime);
        //    //transform.position += Vector3.back * Time.deltaTime;
        //}
        //if (Input.GetKey(KeyCode.RightArrow))
        //{
        //    transform.Rotate(Vector3.up);
        //}
        //if (Input.GetKey(KeyCode.LeftArrow))
        //{
        //    transform.Rotate(Vector3.down);
        //}
    }
    [SerializeField]
    float m_nGUIIdx = 0;
    private void OnGUI()
    {
        float w = 100;
        float h = 50;
        GUI.Box(new Rect(0, h * m_nGUIIdx, w, h), m_sStatus.ToString());
    }

    //private void OnCollisionEnter(Collision collision)
    //{
    //    Debug.Log(this.gameObject.name + ".OnCollisionEnter:"+ collision.gameObject.name);
    //    ItemObejct itemObejct = collision.gameObject.GetComponent<ItemObejct>();

    //    if(itemObejct)
    //    {
    //        itemObejct.EatItem(m_cItemInventory);
    //    }
    //}

    private void OnTriggerEnter(Collider other)
    {
        
    }
}
