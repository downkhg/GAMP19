using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public TrackerCamera trackerCamera;

    public Responner responnerPlayer;
    public Responner responnerEagle;
    public Responner responnerOpossum;

    // Update is called once per frame
    void Update()
    {
        CameraTrackerSetting();
        EagleResponPointSetting();
    }

    void CameraTrackerSetting()
    {
        if (responnerPlayer.objPlayer)
        {
            trackerCamera.objTarget = responnerPlayer.objPlayer;
        }
    }

    void EagleResponPointSetting()
    {
        if (responnerEagle.objPlayer)
        {
            Eagle eagle = responnerEagle.objPlayer.GetComponent<Eagle>();

            if (eagle.objResponPoint == null)
                eagle.objResponPoint = responnerEagle.gameObject;

            if (eagle.objPatrolPoint == null)
                eagle.objPatrolPoint = responnerOpossum.gameObject;
        }
    }
}
