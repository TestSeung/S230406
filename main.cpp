#include<iostream>
#include "FState.h"
#include "FTransition.h"
#include <array>
#include <set>
#include <map>  //STL
#include <vector> //STL
#include <list> //STL �߰� �����Ҷ� vector�ʹٸ��� �迭�� ��ã��
#include <algorithm> 
#include <queue>
#include <stack> //Ȯ�� boost

using namespace std;
//�Լ� ������ �����ε�
//container
template<typename T> // �����Ͻ� ���� ���ø� �� class ���ڸ� ������ ������ �ִ�.

T Add(T A, T B)
{
	return A + B;
}
float Add(float A, float B)
{
	return A + B;
}
double Add(double A, double B)
{
	return A + B;
}
char Add(char A, char B)
{
	return A + B;
}

template<typename T>
class Array
{
public:
	void Save(T Value)
	{
	}
};

int main()
{
	////STL �˾ƿ���
	//map<string, int> state;
	//int A[4];
	////A["ȸ��"]

	//Array<int> IntArray;
	//Array<float> Intfloat;
	//Array<FState> StateArray;
	//
	//
	//cout << Add<char>((char)22, (char)22) << endl;
	//cout << Add<int>(22,22) << endl;
	
	// fopen 

	vector<FState*> States;

	States.push_back(new FState(1, "��ȸ"));
	States.push_back(new FState(2, "�߰�"));
	States.push_back(new FState(3, "����"));
	States.push_back(new FState(4, "����"));
	States.push_back(new FState(5, "�ʻ��")); // �ٸ������� �ҷ� �� �� �ִ�.

	//sort(States.begin(),States.end()) //���� algorithm

	// States.size() ����

	for (int i = 0; i < States.size(); ++i)
	{
		cout << States[i]->Name << endl;
	}
	for (auto iter = States.rbegin(); iter != States.rend(); ++iter) //iter �ݺ��� ������for���� ��������������.
	{
			cout << (*iter)->Name << endl;
	}
	for (auto iter : States)
	{
		cout << iter->Name << endl;
	}


	list<FTransition*> Transitions;

	Transitions.push_back(new FTransition(1,"���߰�",2));
	Transitions.push_back(new FTransition(2,"����ħ", 1));
	Transitions.push_back(new FTransition(2,"�����Ÿ�����", 3));
	Transitions.push_back(new FTransition(3,"�����Ÿ���Ż", 2));
	Transitions.push_back(new FTransition(3,"HP����", 4)); 

	//����Ÿ��
	//for (auto iter = Transitions.rbegin(); iter != Transitions.rend(); ++iter) // r reverse�ݴ����
	//{
	//	cout << (*iter)->Condition << endl;
	//}
	//������� for
	for (auto iter : Transitions)
		{
			cout << iter->Condition << endl;
		}

	map<int, FTransition*> TransitionsMap;
	TransitionsMap[1] = (new FTransition(1, "���߰�", 2));
	TransitionsMap[2]=(new FTransition(2, "����ħ", 1));
	TransitionsMap[3]=(new FTransition(2, "�����Ÿ�����", 3));
	TransitionsMap[4]=(new FTransition(3, "�����Ÿ���Ż", 2));
	TransitionsMap[5]=(new FTransition(3, "HP����", 4));

	for (auto iter : TransitionsMap)
	{
		cout << iter.first << endl;
		cout << iter.second->Condition << endl;
	}


	int MonsterCurrentState = 3; // ������ ��ȸ
	string MonsterCondition = "HP����";
	int MonsterNextState;

	for (auto Value : Transitions)
	{
		if (Value->CurrentState == MonsterCurrentState &&
			Value->Condition == MonsterCondition)
		{
			MonsterNextState = Value->CurrentState;
		}
	}
	cout << "���� ������ ���´� " << States[MonsterCurrentState - 1]->Name;
	cout << "�̰� ������ " << MonsterCondition<<"�� �ؼ��� ";
	cout << "���Ͱ� ��������" << States[MonsterNextState - 1]->Name;
	cout << "�ൿ�� �մϴ� " << endl;

	return 0;
}