using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIPlayerInfo : MonoBehaviour
{
    [SerializeField]
    Text m_textPlayerName;
    [SerializeField]
    Text m_textLv;
    [SerializeField]
    GUIStatusBar m_guiHpBar;
    [SerializeField]
    GUIStatusBar m_guiMpBar;

    public void UpdatePlayerInfo(Controller controller)
    {
        Player player = controller.Player;
        m_textPlayerName.text = player.gameObject.name;
        m_textLv.text = string.Format("Lv:{0}", player.Lv);
        m_guiHpBar.UpdateStatus(player.Status.nHP, player.MaxHP);
        m_guiMpBar.UpdateStatus(player.Status.nMP, player.MaxMP);
    }

    // Start is called before the first frame update
    void Start()
    {
        m_guiHpBar.Initialize("HP", Color.red);
        m_guiMpBar.Initialize("MP", Color.blue);
    }
}
