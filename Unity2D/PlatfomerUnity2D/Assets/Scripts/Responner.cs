using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject objPlayer;
    public string strPrefabName;
    public float Time = 1;

    public bool isRespon = false;
   
    // Start is called before the first frame update
    void Start()
    {
        strPrefabName = objPlayer.name;
        //Debug.Log("Responner::Start:" + gameObject.name);
    }

    // Update is called once per frame
    void Update()
    {
        //Debug.Log("Update::Update:" + gameObject.name);
        if (objPlayer == null && isRespon == false)
        {
            StartCoroutine(ProcessTimmer());
        }
    }

    IEnumerator ProcessTimmer()
    {
        Debug.Log("ProcessTimmer Start!");
        isRespon = true;
        //에셋폴더에서 프리팹읽어보기
        GameObject prefabObject =  Resources.Load("Prefabs/" + strPrefabName) as GameObject;
        yield return new WaitForSeconds(Time);
        objPlayer = Instantiate(prefabObject);
        objPlayer.transform.position = this.gameObject.transform.position;
        objPlayer.name = strPrefabName;
        isRespon = false;
        Debug.Log("ProcessTimmer End!");
    }
}
