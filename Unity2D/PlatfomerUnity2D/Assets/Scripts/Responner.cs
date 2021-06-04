using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject objPlayer;
    public string strPrefabName;

    // Start is called before the first frame update
    void Start()
    {
        strPrefabName = objPlayer.name;
    }

    // Update is called once per frame
    void Update()
    {
        if(objPlayer == null)
        {
            //에셋폴더에서 프리팹읽어보기
            GameObject prefab =
                Resources.Load("Prefabs/" + strPrefabName) as GameObject;
            //읽은 프래팹을 복제
            Instantiate(prefab);
        }
    }
}
