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
    bool Exist(EightFigureState state);
    ~DFS(void);

private:
    int depth;
    std::vector<EightFigureState> open;
    std::stack<EightFigureState> s;
};

