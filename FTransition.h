#pragma once
#include <string>

using namespace std;

class FTransition
{
public:
	FTransition(int NewCurrentState, string NewCondition, int NewNextState);
	int CurrentState;
	string Condition;
	int NextState;
};

