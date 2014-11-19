#pragma once
#include "searchcore.h"

class DFS :
    public SearchCore
{
public:
    DFS(void);
    DFS(EightFigureState startState,EightFigureState targetState,int depth);
    bool Search();
    void SetDepth(int depth);
    ~DFS(void);
private:
    int depth;
    std::vector<EightFigureState> route;
    std::stack<EightFigureState> s;
};

