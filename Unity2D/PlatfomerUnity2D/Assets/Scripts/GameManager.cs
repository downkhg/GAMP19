using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public TrackerCamera trackerCamera;
    public Responner responnerPlayer;
    public Responner responnerEagle;

    // Update is called once per frame
    void Update()
    {
        if (responnerPlayer.objPlayer)
        {
            trackerCamera.objTarget = responnerPlayer.objPlayer;
        }

        if (responnerEagle.objPlayer)
        {
            Eagle eagle = responnerEagle.objPlayer.GetComponent<Eagle>();

            if(eagle.objResponPoint == null)
                eagle.objResponPoint = responnerEagle.gameObject;
        }
    }
}
