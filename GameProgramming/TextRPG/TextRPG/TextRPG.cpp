#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Status {
	int nHP;
	int nMP;
	int nStr;
	int nInt;
	int nDef;

	Status(int _hp = 0, int _mp = 0, int _str = 0, int _int = 0, int _def = 0)
	{
		nHP = _hp;
		nMP = _mp;
		nStr = _str;
		nInt = _int;
		nDef = _def;
	}
	void operator+=(const int value)
	{
		this->nHP += value;
		this->nMP += value;
		this->nStr += value;
		this->nDef += value;
		this->nInt += value;
	}
	Status operator+(const Status& status)
	{
		Status sResult;
		sResult.nHP = nHP + status.nHP;
		sResult.nMP = nMP + status.nMP;
		sResult.nStr = nStr + status.nStr;
		sResult.nDef = nDef + status.nDef;
		sResult.nInt = nInt + status.nInt;
		return sResult;
	}
	Status operator-(const Status& status)
	{
		Status sResult;
		sResult.nHP = nHP - status.nHP;
		sResult.nMP = nMP - status.nMP;
		sResult.nStr = nStr - status.nStr;
		sResult.nDef = nDef - status.nDef;
		sResult.nInt = nInt - status.nInt;
		return sResult;
	}
	void Show()
	{
		cout << "HP:" << nHP << endl;
		cout << "MP:" << nMP << endl;
		cout << "STR:" << nStr << endl;
		cout << "INT:" << nInt << endl;
		cout << "DEF:" << nDef << endl;
	}
};

class Item {
public:
	enum E_ITEM_KIND { WEAPON, ARMOR, ACC, ETC };
	E_ITEM_KIND eItemKind;
	string strName;
	string strComment;
	Status sFuction;
	int nGold;
	Item(E_ITEM_KIND kind = ETC, string name = "none", string comment = "none", Status status = Status(), int gold = 0)
	{
		Set(kind, name, comment, status, gold);
	}
	void Set(E_ITEM_KIND kind, string name, string comment, Status status, int gold)
	{
		eItemKind = kind;
		strName = name;
		strComment = comment;
		sFuction = status;
		nGold = gold;
	}
};

class ItemManager {
	vector<Item> m_listItems;
public:
	enum E_ITEM_LIST { WOOD_SOWRD, BONE_SOWRD, WOOD_ARMOR, BONE_AMROR, WOOD_RING, BONE_RING, HP_POTION, MP_POTION, STONE, BOOM };
	ItemManager()
	{
		m_listItems.resize(10);
		m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, "���", "������ ����", Status(0, 0, 10), 100);
		m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, "���ҵ�", "������ ����", Status(0, 0, 20), 100);
		m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, "��������", "���� ����", Status(0, 0, 0, 10), 100);
		m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, "���Ƹ�", "���� ����", Status(0, 0, 20), 100);
		m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, "��������", "ü�� ����", Status(10), 100);
		m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, "�ذ����", "ü�� ����", Status(20), 100);
		m_listItems[6] = Item(Item::E_ITEM_KIND::ETC, "��������", "HPȸ��", Status(100), 100);
		m_listItems[7] = Item(Item::E_ITEM_KIND::ETC, "��������", "MPȸ��", Status(0, 100), 100);
		m_listItems[8] = Item(Item::E_ITEM_KIND::ETC, "¯��", "���� �� �����", Status(0, 0, 50), 100);
		m_listItems[9] = Item(Item::E_ITEM_KIND::ETC, "���", "�ټ� �� �����", Status(0, 0, 50), 100);
	}
	Item GetItem(int idx)
	{
		return m_listItems[idx];
	}
};

class Player {
	string m_strName;
	Status m_sStatus;
	int m_nLv;
	int m_nExp;

	vector<Item> m_listIventory;
public:
	void SetIventory(Item item)
	{
		m_listIventory.push_back(item);
	}
	Item GetIventoryIdx(int idx)
	{
		return m_listIventory[idx];
	}
	void DeleteIventory(int idx)
	{
		m_listIventory.erase(m_listIventory.begin() + idx);
	}

	void Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp)
	{
		m_strName = strName;
		m_sStatus.nHP = _hp;
		m_sStatus.nMP = _mp;
		m_sStatus.nStr = _str;
		m_sStatus.nInt = _int;
		m_sStatus.nDef = _def;
		m_nExp = _exp;
		m_nLv = 1;
	}

	void Attack(Player& taget)
	{
		taget.m_sStatus.nHP -= m_sStatus.nStr - m_sStatus.nDef;
	}

	void StillItem(Player& taget)
	{
		//Ÿ���� ������ �ִ� ������ �� ù��° �������� �������,
		//Ÿ���� ����ġ�� �����ͼ� �� ����ġ�� �ø���.
		this->SetIventory(taget.GetIventoryIdx(0));
		taget.DeleteIventory(0);
		this->m_nExp = taget.m_nExp;
	}

	bool LvUp()
	{
		//���� ����ġ�� 100 �̻�Ǹ�, ����+1, ��� �ɷ�ġ 10����, ����ġ �ʱ�ȭ.
		if (m_nExp >= 100)
		{
			m_sStatus += 10;
			m_nLv++;
			m_nExp -= 100;
			return true;
		}
		return false;
	}

	bool Dead()
	{
		if (m_sStatus.nHP <= 0)
			return true;
		return false;
	}

	void Show()
	{
		cout << "######### " << m_strName << "######### " << endl;
		m_sStatus.Show();
		cout << "######### Inventory ######### " << endl;
		for (int i = 0; i < m_listIventory.size(); i++)
			cout << i << ":" << m_listIventory[i].strName << endl;
	}
};

void main()
{
	enum E_STAGE { EXIT = -1, CRATE, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	const char* strStageName[] = { "CRATE", "TOWN", "FILED", "BATTLE", "GAME_OVER", "THE_END" };

	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };
	const char* strMonsterName[] = { "SILME", "SKELETON", "BOSS" };

	int eStage = E_STAGE::CRATE;

	ItemManager cItemManager;
	Player cPlayer;
	Player cMonster;

	cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
	cMonster.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
	//cMonster.SetIventory(Item(Item::E_ITEM_KIND::WEAPON, "���", "������ ����", Status(0, 0, 10), 100));

	while (eStage != E_STAGE::EXIT)
	{
		switch (eStage)
		{
		case E_STAGE::CRATE:
		{
			string name;
			cout << "�ɸ��� �̸��� �Է��ϼ���!:";
			cin >> name;
			cPlayer.Set(name, 100, 100, 20, 10, 10, 0);
		}
		break;
		case E_STAGE::TOWN:
		{
			cout << "���� �Դϴ�." << endl;
		}
		break;
		case E_STAGE::FILED:
		{
			int nSelect;
			cout << "���� ���ðڽ��ϱ�?";
			for (int i = 0; i < E_MONSTER::MON_MAX; i++)
				cout << i << ":" << strMonsterName[i] << ",";
			cin >> nSelect;
			switch (nSelect)
			{
			case E_MONSTER::SILME:
				cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
				break;
			case E_MONSTER::SKELETON:
				cMonster.Set("Skeleton", 200, 200, 30, 10, 10, 100);
				break;
			case E_MONSTER::BOSS:
				cMonster.Set("Boss", 300, 100, 50, 10, 10, 100);
				break;
			}
		}
		break;
		case E_STAGE::BATTLE:
		{
			if (cPlayer.Dead() == false)
				cPlayer.Attack(cMonster);
			else
			{
				eStage = GAME_OVER;
			}
			cMonster.Show();
			if (cMonster.Dead() == false)
				cMonster.Attack(cPlayer);
			else
			{
				cPlayer.StillItem(cMonster);
				if (cPlayer.LvUp())
					cout << "����!" << endl;
				eStage = TOWN;
			}
		}
		break;
		case E_STAGE::GAME_OVER:
			printf("GAME\OVER");
			break;
		case E_STAGE::THE_END:
			printf("THE EMD");
			break;
		default:
			break;
		}
		cout << "���� ���ðڽ��ϱ�?" << endl;
		for (int i = 0; i < E_STAGE::MAX; i++)
			cout << i << ":" << strStageName[i] << ",";
		cin >> eStage;
	}
}