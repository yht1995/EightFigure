#pragma once
#include "stdafx.h"
#include "EightFigureState.h"
const int MAXSTATES = 362882;
class SearchCore
{
public:
	SearchCore();
    SearchCore(EightFigureState startState,EightFigureState targetState);
	~SearchCore();
    void SetStart(EightFigureState state);
    void SetTarget(EightFigureState state);
    void GetPath(std::vector<EightFigureState> &path);
    time_t GetTime();
    virtual bool Search() = 0;
protected:
    EightFigureState startState;
    EightFigureState targetState;
    std::vector<EightFigureState> path;
    std::hash_set<unsigned int> open;
    clock_t startTime;
    clock_t stopTime;
};