using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemObejct : MonoBehaviour
{
    [SerializeField]
    Item m_cItem;
    public Item Item { get { return m_cItem; } set { m_cItem = value; } }

    ////싱글톤 객체에 접근할때는 업데이트를 이용하면 객체가 없어서 접근하지 못하는 경우는 없다.
    ////물론 연산량이 많아 질수있으나 단순 테스트용 코드이므로 실사용되서는 안된다.
    //void Update()
    //{
    //    m_cItem = GameManager.GetInstance().GetItemManager().GetItem(1);
    //}

    public void EatItem(ItemIeventory itemIeventory)
    {
        itemIeventory.SetIevntory(m_cItem);
        Destroy(this.gameObject);
    }

    private void OnCollisionEnter(Collision collision)
    {
        Debug.Log(this.gameObject.name + ".OnCollisionEnter:" + collision.gameObject.name);
        Player player = collision.gameObject.GetComponent<Player>();

        if(player)
        {
            EatItem(player.GetItemIventory());
        }
    }

    private void OnTriggerEnter(Collider other)
    {

    }
}
