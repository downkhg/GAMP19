#include <iostream>
#include <vector>
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
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
}

void main()
{
	VectorMain();
}