#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

struct SNode
{
	char cData;
	bool bVisit = false;
	list<SNode*>::iterator itChild; //
	list<SNode*> listNext;
};

bool MakeChild(SNode* pParent, SNode* pChild)
{
	if (pParent != NULL)
	{
		pParent->listNext.push_back(pChild);
		if (pParent->listNext.size() == 1)
		{
			pParent->itChild = pParent->listNext.begin();
			cout << pParent->cData << " itChild:" << (*pParent->itChild)->cData << endl;
		}
	}
	return false;
}

void TraverseDFSRecursion(SNode* pNode)
{
	if (pNode->bVisit) return;
	cout << pNode->cData << endl;
	pNode->bVisit = true;
	list<SNode*>::iterator it = pNode->listNext.begin();
	for (; it != pNode->listNext.end(); it++)
	{
		SNode* pNode = *it;
		TraverseDFSRecursion(pNode);
	}
}


SNode* VisitDFS(SNode* pNode, stack<SNode*>& visit)
{
	SNode* pNext = NULL;
	if (pNode)
	{
		if (pNode->bVisit == false)
		{
			//cout << "Visit:" << pNode->cData << endl;
			cout << pNode->cData << endl;
			visit.push(pNode);
			pNode->bVisit = true;
		}
		else
		{
			//cout << "Revisit:" << pNode->cData << endl;
		}
		//list<SNode*>::iterator it = pNode->itChild;
		if (pNode->listNext.size() > 0)
		{
			if (pNode->itChild != pNode->listNext.end())
			{
				pNext = *pNode->itChild;
				while (pNext != NULL && pNext->bVisit == true)
				{
					if (pNode->itChild != pNode->listNext.end())
					{
						//cout << "Revisit!" << (*pNode->itChild)->cData << endl;
						pNext = *pNode->itChild;
						pNode->itChild++;
					}
					else
					{
						//cout << "Visit Complete!" << pNode->cData << endl;
						pNext = NULL;
					}
				}
			}
		}
	}
	else
	{
		//cout << "Visit Complete! " << visit.top()->cData << endl;
		visit.pop();
		if(!visit.empty())
			pNext = visit.top();
	}
	return pNext;
}

void TraverDFSStack(SNode* pNode)
{
	stack<SNode*> visit;
	do
	{
		pNode = VisitDFS(pNode,visit);
	} 	
	while (!visit.empty());
}

void TraverseReset(vector<SNode*>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i]->bVisit = false;
		vec[i]->itChild = vec[i]->listNext.begin();
	}
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

	//TraverseDFSRecursion(vecNodes[A]);
	TraverDFSStack(vecNodes[A]);
	TraverseReset(vecNodes);

	for (int i = 0; i < vecNodes.size(); i++)
		delete vecNodes[i];
	vecNodes.clear();
}