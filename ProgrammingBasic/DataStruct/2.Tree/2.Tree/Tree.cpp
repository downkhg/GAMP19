/*##################################
이진트리(C언어 수업용)
파일명: BinaryTree.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2018.04.03
버전 : 1.00
###################################*/
#include <stdio.h>

using namespace std;

struct SNode {
	int nData;
	SNode* pLeft;
	SNode* pRight;
};

SNode* CreateNode(int data)
{
	SNode* pTemp = new SNode;
	pTemp->nData = data;
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;
	return pTemp;
};
bool MakeLeft(SNode* pPerant, SNode* pChilde)
{
	if (pPerant == NULL)
		return false;
	pPerant->pLeft = pChilde;
	return true;
};
bool MakeRight(SNode* pPerant, SNode* pChilde)
{
	if (pPerant == NULL)
		return false;
	pPerant->pRight = pChilde;
	return true;
};

void Traverse(SNode* pNode)
{
	if (!pNode) return;
	//printf("%d\n", pNode->nData); //전위
	Traverse(pNode->pLeft);
	printf("%d\n", pNode->nData); //중위
	Traverse(pNode->pRight);
	//printf("%d\n", pNode->nData); //후위
}

void Print(SNode* pSeed)
{
	Traverse(pSeed);
}

void Swap(int& a, int& b)
{
	printf("Swap[%d <->%d]\n",a,b);
	int temp = a;
	a = b;
	b = temp;
}

void MinHipTreeInsert(SNode* pParent, SNode* pInsert)
{
	if (pParent == NULL) return;
	if (pParent->nData > pInsert->nData)
	{
		printf("Swap Parent\n");
		Swap(pParent->nData ,pInsert->nData);

		MinHipTreeInsert(pParent, pInsert);
	}
	else
	{
		if (pParent->pLeft == NULL)
		{
			pParent->pLeft = pInsert;
			printf("MinHipTreeInsert_Left:%d\n", pInsert->nData);
			return;
		}
		else if (pParent->pRight == NULL)
		{
			pParent->pRight = pInsert;
			printf("MinHipTreeInsert_Right:%d\n", pInsert->nData);
			return;
		}
		else
			MinHipTreeInsert(pParent->pLeft, pInsert);
	}
}

void TreeMain()
{
	SNode* pSeed = NULL;

	SNode* pPrant = CreateNode(10);
	SNode* pLeft = CreateNode(20);
	SNode* pRight = CreateNode(30);
	SNode* pD = CreateNode(40);
	SNode* pE = CreateNode(50);

	MakeLeft(pPrant, pLeft);
	MakeRight(pPrant, pRight);

	MakeLeft(pLeft, pD);
	MakeRight(pLeft, pE);

	pSeed = pPrant;

	Print(pSeed);
}


void MinHipTreeMain()
{
	////최상위 부모가 가장작은 노드를 가진다.
	//SNode* pNode = CreateNode(1);
	//pNode->pLeft = CreateNode(2);
	//pNode->pRight = CreateNode(3);

	//SNode* pRootLeft = pNode->pLeft;
	//pRootLeft->pLeft = CreateNode(4);
	//pRootLeft->pRight = CreateNode(5);

	//SNode* pRootRighit = pNode->pRight;
	//pRootRighit->pLeft = CreateNode(6);
	//pRootRighit->pRight = CreateNode(7);

	//SNode* pLeftLeft = pNode->pLeft;
	//pRootLeft->pLeft = CreateNode(8);
	//pRootLeft->pRight = CreateNode(9);
	const int nSize = 5;
	SNode* pArrayNode[nSize];
	for (int i = 0; i < nSize; i++)
	{
		pArrayNode[i] = CreateNode(i);
	}

	//SNode* pRoot = pArrayNode[0];
	/*for (int i = 1; i < nSize; i++)
	{
		MinHipTreeInsert(pRoot, pArrayNode[1]);
	}*/
	SNode* pRoot = pArrayNode[nSize - 1];
	for (int i = nSize-2; i >= 0; i--)
	{
		MinHipTreeInsert(pRoot, pArrayNode[i]);
	}

	Print(pRoot);
}

void SetTestMain()
{
	const int SIZE = 7;
	SNode* arrNode[SIZE];
	for (int i = 0; i < SIZE; i++)
		arrNode[i] = CreateNode(i * 10);

	SNode* pSeed = arrNode[3];

	MakeLeft(arrNode[3], arrNode[1]);
	MakeRight(arrNode[3], arrNode[5]);

	MakeLeft(arrNode[1], arrNode[0]);
	MakeRight(arrNode[1], arrNode[2]);

	MakeLeft(arrNode[5], arrNode[4]);
	MakeRight(arrNode[5], arrNode[6]);

	Print(pSeed);
}

void main()
{
	//MinHipTreeMain();
	SetTestMain();
}