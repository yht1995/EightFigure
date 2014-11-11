#pragma once
#include "searchcore.h"

class DFS :
    public SearchCore
{
public:
    DFS(void);
    DFS(EightFigureState startState,EightFigureState targetState);
    int Search();
    void SetDepth(int depth);
    ~DFS(void);
private:
    int depth;
    int idx;
    std::vector<EightFigureState> route;
    std::stack<EightFigureState> s;
};

