#include <iostream>
//선형자료구조
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
//트리자료구조
#include <set>
#include <map>
//해시테이블
#include <unordered_map>

using namespace std;
//백터: 동적배열 -> 크기를 변경 가능한 배열.
//알고리즘
//1.배열의 크기를 1로 만들고, 값을 10으로 초기화한다.
//2.배열을 모두 출력한다.
//3.배열의 크기를 3으로 변경하고, 배열을 모두 출력한다.
//4.추가,삽입,삭제,모두삭제 각각 테스트하고 출력해보기.
//5.삽입을 할때 이터레이터를 요구하므로 무엇인지 테스트해본다.
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
	it = container.begin() + 3; //랜덤액세스
	if (it != container.end())
		container.erase(it);
	else
		cout << "erase fail!" << endl;
	container.pop_back(); //마지막원소삭제
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
}
//데크: 앞뒤로 데이터를 추가 가능한 자료구조.
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
	it = container.begin() + 3; //랜덤액세스
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
//이중연결리스트
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
	it = container.end(); //랜덤액세스
	it--; it--; it--;
	if (it != container.end())
		container.erase(it);
	else
		cout << "erase fail!" << endl;
	container.pop_back(); //마지막원소삭제
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
//집합: 레드블랙이진트리
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
//맵: 키값이 있는 레드블랙이진트리
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
//해쉬맵(해시테이블)
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