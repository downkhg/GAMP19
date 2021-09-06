#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct SNode
{
	char cData;
	bool bVisit = false;
	list<SNode*> listNext;
};

bool MakeChild(SNode* pParent, SNode* pChild)
{
	if (pParent != NULL)
		pParent->listNext.push_back(pChild);
	return false;
}

void TraverseDFS(SNode* pNode)
{
	if (pNode->bVisit) return;
	cout << pNode->cData << endl;
	pNode->bVisit = true;
	list<SNode*>::iterator it = pNode->listNext.begin();
	for (; it != pNode->listNext.end(); it++)
	{
		SNode* pNode = *it;
		TraverseDFS(pNode);
	}
}

void TraverseReset(vector<SNode*>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		vec[i]->bVisit = false;
}

enum E_NODE { A, B, C, D, E, F, G,H, MAX};

void main()
{
	vector<SNode*> vecNodes(MAX);
	for (int i = 0; i < vecNodes.size(); i++)
	{
		vecNodes[i] = new SNode();
		vecNodes[i]->cData = 'A' + i;
	}

	MakeChild(vecNodes[A], vecNodes[B]);
	//MakeChild(vecNodes[A], NULL);

	MakeChild(vecNodes[B], vecNodes[D]);
	MakeChild(vecNodes[B], vecNodes[F]);
	//MakeChild(vecNodes[B], NULL);

	MakeChild(vecNodes[C], vecNodes[B]);
	//MakeChild(vecNodes[C], NULL);

	MakeChild(vecNodes[D], vecNodes[H]);
	//MakeChild(vecNodes[D], NULL);

	MakeChild(vecNodes[E], vecNodes[C]);
	MakeChild(vecNodes[E], vecNodes[H]);
	//MakeChild(vecNodes[E], NULL);

	MakeChild(vecNodes[F], vecNodes[D]);
	MakeChild(vecNodes[F], vecNodes[G]);
	MakeChild(vecNodes[F], vecNodes[H]);
	//MakeChild(vecNodes[F], NULL);

	MakeChild(vecNodes[G], vecNodes[E]);
	MakeChild(vecNodes[G], vecNodes[F]);
	MakeChild(vecNodes[G], vecNodes[H]);
	//MakeChild(vecNodes[G], NULL);

	//MakeChild(vecNodes[H], NULL);

	TraverseDFS(vecNodes[A]);
	TraverseReset(vecNodes);

	for (int i = 0; i < vecNodes.size(); i++)
		delete vecNodes[i];
	vecNodes.clear();
}