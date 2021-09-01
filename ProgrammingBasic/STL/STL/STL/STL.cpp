#include <iostream>
#include <vector>
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
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
}

void main()
{
	VectorMain();
}