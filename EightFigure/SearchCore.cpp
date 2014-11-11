#include "stdafx.h"
#include "SearchCore.h"
void SearchCore::SetStart(EightFigureState state)
{
    this->startState = state;
}

void SearchCore::SetTarget(EightFigureState state)
{
    this->targetState = state;
}

SearchCore::SearchCore()
{
    startTime = 0;
    stopTime = 0;
}

SearchCore::SearchCore(EightFigureState startState,EightFigureState targetState)
{
    startTime = 0;
    stopTime = 0;
    this->startState = startState;
    this->targetState = targetState;
}

SearchCore::~SearchCore()
{
}

time_t SearchCore::GetTime()
{
    return((stopTime - startTime)/CLOCKS_PER_SEC*1000);
}
