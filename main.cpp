#include<iostream>
#include "FState.h"
#include "FTransition.h"
#include <array>
#include <set>
#include <map>  //STL
#include <vector> //STL
#include <list> //STL 추가 삭제할때 vector와다르게 배열로 못찾음
#include <algorithm> 
#include <queue>
#include <stack> //확장 boost

using namespace std;
//함수 재정의 오버로딩
//container
template<typename T> // 컴파일시 생성 탬플릿 구 class 인자를 여러개 넣을수 있다.

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
	////STL 알아오기
	//map<string, int> state;
	//int A[4];
	////A["회피"]

	//Array<int> IntArray;
	//Array<float> Intfloat;
	//Array<FState> StateArray;
	//
	//
	//cout << Add<char>((char)22, (char)22) << endl;
	//cout << Add<int>(22,22) << endl;
	
	// fopen 

	vector<FState*> States;

	States.push_back(new FState(1, "배회"));
	States.push_back(new FState(2, "추격"));
	States.push_back(new FState(3, "공격"));
	States.push_back(new FState(4, "죽음"));
	States.push_back(new FState(5, "필살기")); // 다른곳에서 불러 올 수 있다.

	//sort(States.begin(),States.end()) //정렬 algorithm

	// States.size() 갯수

	for (int i = 0; i < States.size(); ++i)
	{
		cout << States[i]->Name << endl;
	}
	for (auto iter = States.rbegin(); iter != States.rend(); ++iter) //iter 반복자 범위형for문은 뒤집을수가없다.
	{
			cout << (*iter)->Name << endl;
	}
	for (auto iter : States)
	{
		cout << iter->Name << endl;
	}


	list<FTransition*> Transitions;

	Transitions.push_back(new FTransition(1,"적발견",2));
	Transitions.push_back(new FTransition(2,"적놓침", 1));
	Transitions.push_back(new FTransition(2,"사정거리접근", 3));
	Transitions.push_back(new FTransition(3,"사정거리이탈", 2));
	Transitions.push_back(new FTransition(3,"HP없음", 4)); 

	//구스타일
	//for (auto iter = Transitions.rbegin(); iter != Transitions.rend(); ++iter) // r reverse반대순서
	//{
	//	cout << (*iter)->Condition << endl;
	//}
	//범위기반 for
	for (auto iter : Transitions)
		{
			cout << iter->Condition << endl;
		}

	map<int, FTransition*> TransitionsMap;
	TransitionsMap[1] = (new FTransition(1, "적발견", 2));
	TransitionsMap[2]=(new FTransition(2, "적놓침", 1));
	TransitionsMap[3]=(new FTransition(2, "사정거리접근", 3));
	TransitionsMap[4]=(new FTransition(3, "사정거리이탈", 2));
	TransitionsMap[5]=(new FTransition(3, "HP없음", 4));

	for (auto iter : TransitionsMap)
	{
		cout << iter.first << endl;
		cout << iter.second->Condition << endl;
	}


	int MonsterCurrentState = 3; // 가만히 배회
	string MonsterCondition = "HP없음";
	int MonsterNextState;

	for (auto Value : Transitions)
	{
		if (Value->CurrentState == MonsterCurrentState &&
			Value->Condition == MonsterCondition)
		{
			MonsterNextState = Value->CurrentState;
		}
	}
	cout << "현재 몬스터의 상태는 " << States[MonsterCurrentState - 1]->Name;
	cout << "이고 조건은 " << MonsterCondition<<"을 해서는 ";
	cout << "몬스터가 다음에는" << States[MonsterNextState - 1]->Name;
	cout << "행동을 합니다 " << endl;

	return 0;
}