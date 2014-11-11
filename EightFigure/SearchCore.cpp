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
    open.clear();
    path.clear();
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

void SearchCore::GetPath(std::vector<EightFigureState> &path)
{
    path.clear();
    for (unsigned int i = 1;i<=this->path.size();i++)
    {
        path.push_back(this->path[this->path.size() - i]);
    }
}