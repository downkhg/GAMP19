using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    [SerializeField]
    float m_fSpeed = 1;
    [SerializeField]
    float m_fAngleSpeed = 1;
    [SerializeField]
    Gun m_cGun;
    [SerializeField]
    ItemIeventory m_cItemInventory;

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
        m_cGun.Shot(target);
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
