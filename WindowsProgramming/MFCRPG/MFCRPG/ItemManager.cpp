#include "pch.h"
#include <stdio.h>
#include <vector>
#include <iostream>


using namespace std;

ItemManager::ItemManager()
{
	m_listItems.resize(10);
	m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, _T("���"), _T("����������"), Status(0, 0, 10, 0, 0), 100);
	m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, _T("���ҵ�"), _T("����������"), Status(0, 0, 20, 0, 0), 100);
	m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, _T("��������"), _T("��������"), Status(0, 0, 0, 10, 0), 100);
	m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, _T("���Ƹ�"), _T("��������"), Status(0, 0, 0, 20, 0), 100);
	m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, _T("��������"), _T("ü������"), Status(10,0,0,0,0), 100);
	m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, _T("�ذ����"), _T("ü������"), Status(20, 0, 0, 0, 0), 100);
	m_listItems[6] = Item(Item::E_ITEM_KIND::POTION, _T("��������"), _T("HPȸ��"), Status(100, 0, 0, 0, 0), 100);
	m_listItems[7] = Item(Item::E_ITEM_KIND::POTION, _T("��������"), _T("MPȸ��"), Status(0,100, 0, 0, 0), 100);
	m_listItems[8] = Item(Item::E_ITEM_KIND::THROW, _T("¯��"), _T("�����������"), Status(0, 0, 50, 0, 0), 100);
	m_listItems[9] = Item(Item::E_ITEM_KIND::THROW, _T("���"), _T("�ټ��������"), Status(0, 0, 50, 0, 0), 100);
	//SaveFile();
	//LoadFile();
}

//void ItemManager::SaveFile()
//{
//	FILE* pFile = fopen("itemdatabase.csv", "wt");
//	if (pFile)
//	{
//		fprintf(pFile, "%d\n", m_listItems.size());
//		vector<Item>::iterator it = m_listItems.begin();
//		for (; it != m_listItems.end(); it++)
//		{
//			Item sItem = *(it);
//			fprintf(pFile, "%d,%s,%s,%d,%d,%d,%d,%d\n", sItem.eItemKind, sItem.strName.c_str(), sItem.strComment.c_str(), sItem.nGold,
//				sItem.sFuction.nHP, sItem.sFuction.nMP, sItem.sFuction.nStr, sItem.sFuction.nInt, sItem.sFuction.nDef);
//		}
//		fclose(pFile);
//	}
//	else
//		cout << " Save Failed!" << endl;
//}
//
//void ItemManager::LoadFile()
//{
//	FILE* pFile = fopen("itemdatabase.csv", "rt");
//	if (pFile)
//	{
//		int nSize;
//		fscanf(pFile, "%d", &nSize);
//
//		for (int i = 0; i < nSize; i++)
//		{
//			char strTemp[1024];
//			fscanf(pFile, "%s\n", strTemp);
//			cout << strTemp << endl;
//			char  arrStrs[8][128];
//			char* strTemps = strtok(strTemp, ",");
//			int idx = 0;
//			while (strTemps != NULL)
//			{
//				memcpy(arrStrs[idx], strTemps, 128);
//				strcpy(arrStrs[idx], strTemps);
//				cout << arrStrs[idx] << ",";
//				cout << strTemps << ",";
//				strTemps = strtok(NULL, ",");
//				idx++;
//			}
//			cout << endl;
//			CString name = arrStrs[1];
//			CString info = arrStrs[2];
//			Item sItem((Item::E_ITEM_KIND)atoi(arrStrs[0]), name, info,
//				Status(atoi(arrStrs[4]), atoi(arrStrs[5]), atoi(arrStrs[6]), atoi(arrStrs[7])),
//				atoi(arrStrs[3]));
//			m_listItems.push_back(sItem);
//		}
//		fclose(pFile);
//	}
//	else
//		cout << " Save Failed!" << endl;
//}
Item* ItemManager::GetItem(int idx)
{
	return &m_listItems[idx];
}