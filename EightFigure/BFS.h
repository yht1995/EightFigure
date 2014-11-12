#pragma once
#include "searchcore.h"
class BFS :
    public SearchCore
{
public:
    BFS(void);
    BFS(EightFigureState startState,EightFigureState targetState);
    bool Search();
    ~BFS(void);
private:
    std::queue<EightFigureState> q;
    std::vector<EightFigureState> route;
};

