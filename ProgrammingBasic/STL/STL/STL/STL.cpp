#include <iostream>
//�����ڷᱸ��
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
//Ʈ���ڷᱸ��
#include <set>
#include <map>
//�ؽ����̺�
#include <unordered_map>

using namespace std;
//����: �����迭 -> ũ�⸦ ���� ������ �迭.
//�˰���
//1.�迭�� ũ�⸦ 1�� �����, ���� 10���� �ʱ�ȭ�Ѵ�.
//2.�迭�� ��� ����Ѵ�.
//3.�迭�� ũ�⸦ 3���� �����ϰ�, �迭�� ��� ����Ѵ�.
//4.�߰�,����,����,��λ��� ���� �׽�Ʈ�ϰ� ����غ���.
//5.������ �Ҷ� ���ͷ����͸� �䱸�ϹǷ� �������� �׽�Ʈ�غ���.
void VectorMain()
{
	vector<int> container(1);
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.resize(3);
	container[1] = 20;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.push_back(99);
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	vector<int>::iterator it = container.begin();
	container.insert(it,77);
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	//it = --container.end();
	it = container.begin() + 3; //�����׼���
	if (it != container.end())
		container.erase(it);
	else
		cout << "erase fail!" << endl;
	container.pop_back(); //���������һ���
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
}
//��ũ: �յڷ� �����͸� �߰� ������ �ڷᱸ��.
void DequeMain()
{
	deque<int> container(1);
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.resize(3);
	container[1] = 20;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.push_front(11);
	container.push_back(99);
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	deque<int>::iterator it = container.begin();
	container.insert(it, 77);
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	//it = --container.end();
	it = container.begin() + 3; //�����׼���
	if (it != container.end())
		container.erase(it);
	else
		cout << "erase fail!" << endl;
	container.pop_front();
	container.pop_back();
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
}
//���߿��Ḯ��Ʈ
void ListMain()
{
	list<int> container(1);
	list<int>::iterator it = container.begin();
	*it = 10;
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	container.resize(3);
	it = container.begin();
	it++;
	*it = 20;
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	container.push_back(99);
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	
	container.insert(it, 77);
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	//it = --container.end();
	it = container.end(); //�����׼���
	it--; it--; it--;
	if (it != container.end())
		container.erase(it);
	else
		cout << "erase fail!" << endl;
	container.pop_back(); //���������һ���
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
}

void QueueMain()
{
	queue<int> container;
	container.push(30);
	container.push(20);
	container.push(40);
	container.push(10);
	container.push(50);

	while (container.empty() == false)
	{
		cout << container.front() << endl;
		container.pop();
	}
}

void StackMain()
{
	stack<int> container;
	container.push(30);
	container.push(20);
	container.push(40);
	container.push(10);
	container.push(50);

	while (container.empty() == false)
	{
		cout << container.top() << endl;
		container.pop();
	}
}

void PriorityQueueMain()
{
	priority_queue<int> container;
	container.push(30);
	container.push(20);
	container.push(40);
	container.push(10);
	container.push(50);

	while (container.empty() == false)
	{
		cout << container.top() << endl;
		container.pop();
	}
}
//����: ���������Ʈ��
void SetMain()
{
	int nSize = 7;
	set<int> container;
	for (int i = 0; i < nSize; i++)
		container.insert(i * 10);

	set<int>::iterator it;
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//��: Ű���� �ִ� ���������Ʈ��
void MapMain()
{
	int nSize = 7;
	map<int,int> container;
	for (int i = 0; i < nSize; i++)
		container[i] = i * 10;

	map<int, int>::iterator it;
	for (it = container.begin(); it != container.end(); it++)
		cout << it->first << ":"<< it->second << ",";
	cout << endl;

	for (int i = 0; i < nSize; i++)
		cout << container[i] << ",";
	cout << endl;
}
//�ؽ���(�ؽ����̺�)
void HashMapMain()
{
	int nSize = 7;
	unordered_map<int, int> container;
	for (int i = 0; i < nSize; i++)
		container[i] = i * 10;

	unordered_map<int, int>::iterator it;
	for (it = container.begin(); it != container.end(); it++)
		cout << it->first << ":" << it->second << ",";
	cout << endl;

	for (int i = 0; i < nSize; i++)
		cout << container[i] << ",";
	cout << endl;
}

void main()
{
	//VectorMain();
	//DequeMain();
	//ListMain();
	//QueueMain();
	//StackMain();
	//SetMain();
	//MapMain();
	HashMapMain();
}