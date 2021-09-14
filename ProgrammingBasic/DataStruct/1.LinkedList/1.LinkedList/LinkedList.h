#pragma once
#include <stdio.h>
#define NULL 0

struct SNode {
	int nData;
	SNode* pNext;
};

class CLinkedList
{
	SNode* pBegin = NULL;
	SNode* pEnd = NULL;
public:
	SNode* CreateNode(int data)
	{
		SNode* pTemp = NULL;

		pTemp = new SNode();
		pTemp->nData = data;
		pTemp->pNext = NULL;
		if (pEnd != NULL)//0x04 != N -> T
			pEnd->pNext = pTemp; //�۵����������� �������� �ڵ�
		//pTemp->pNext = pNode; //�۵������� �������������� �ڵ�
		pEnd = pTemp;
		if (pBegin == NULL) pBegin = pTemp;
		return  pTemp;
	}
	SNode* FindNodeData(int data)
	{
		SNode* pNode = pBegin;

		//if (pStart->nData != data) //10!=40 ->T
		//	pNode = pStart->pNext;
		//while (true)
		//while(pNode->nData != data) //������ ��尡�ִٸ� ������ �߻���
		while (pNode)//0x04 != N -> F //�������� ���� �ִٸ� T
		{
			if (pNode->nData != data) //40!=40 ->F
				pNode = pNode->pNext;
			else //40==40 ->T
				break;
		}

		return pNode;//0x04
	}
	SNode* InsertNodeData(int data, int insert)
	{
		SNode* pNode = pBegin;
		SNode* pInsert = NULL;

		pNode = FindNodeData(data);

		if (pNode)
		{
			pInsert = new SNode();
			pInsert->nData = insert;
			//pNode->pNext = pInsert;
			pInsert->pNext = pNode->pNext;
			pNode->pNext = pInsert;
		}

		return pNode;
	}
	void DeleteNodeData(int del)
	{
		SNode* pPre = NULL;
		SNode* pNode = pBegin;
		//������带 ã�����ִ� ��Ģ�� ����.
		//pNode = FindNodeData(pStart, del);
		//pPre = FindNodeData(pStart, ? );
		while (pNode)//0x04 != N -> F //�������� ���� �ִٸ� T
		{
			if (pNode->nData == del) //60 == 60 ->T
			{
				pPre->pNext = pNode->pNext;
				delete pNode;
				break;
			}
			else
			{
				pPre = pNode;
				pNode = pNode->pNext;
			}
		}
	}
	void PrintLinkedList()
	{
		SNode* pNode = pBegin;
		printf("data:");
		while (pNode)
		{
			printf("%d", pNode->nData);
			pNode = pNode->pNext;

			if (pNode != NULL)
				printf(",");
		}
		printf("\n");
	}
	void DeleteLinkedList()
	{
		SNode* pNode = pBegin;
		SNode* pDel = NULL;

		while (pNode)
		{
			pDel = pNode;
			pNode = pNode->pNext;
			//pDel = pStart;
			delete pDel;
		}
		pBegin = NULL;
	}
};

void LinkedListTestMain()
{
	CLinkedList cLinkedList;

	cLinkedList.CreateNode(10);
	cLinkedList.CreateNode(20);
	cLinkedList.CreateNode(30);
	cLinkedList.CreateNode(40);
	cLinkedList.CreateNode(50);
	cLinkedList.PrintLinkedList();

	SNode* pFind = cLinkedList.FindNodeData(40);
	if (pFind)//0���� 
		printf("Find:%d\n", pFind->nData);

	
	SNode* pInser = cLinkedList.InsertNodeData(30,60);
	cLinkedList.PrintLinkedList();

	cLinkedList.DeleteNodeData(60);
	cLinkedList.PrintLinkedList();

	cLinkedList.DeleteLinkedList();
	cLinkedList.PrintLinkedList();
}