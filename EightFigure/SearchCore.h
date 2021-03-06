#pragma once
#include "stdafx.h"
#include "EightFigureState.h"
class SearchCore
{
public:
	SearchCore();
    SearchCore(EightFigureState startState,EightFigureState targetState);
	~SearchCore();
    void SetStart(EightFigureState state);
    void SetTarget(EightFigureState state);
    void GetPath(std::vector<EightFigureState> &path);
    int GetTime();
    int GetStateCount();
    virtual bool Search() = 0;
protected:
    EightFigureState startState;
    EightFigureState targetState;
    std::vector<EightFigureState> path;
    std::hash_set<unsigned int> close;
    clock_t startTime;
    clock_t stopTime;
};