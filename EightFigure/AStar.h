#pragma once
#include "searchcore.h"
#include "EightFigureState.h"

class AStar :
    public SearchCore
{
public:
    AStar(void);
    AStar(EightFigureState startState,EightFigureState targetState,int type);
    ~AStar(void);
    bool Search();
    void SetFunc(int type);
private:
    int (AStar::*clac)(EightFigureState a,EightFigureState b);
    int ClacDifference(EightFigureState a,EightFigureState b);
    int ClacManhattan(EightFigureState a,EightFigureState b);
    std::priority_queue<EightFigureState> q;
    std::vector<EightFigureState> route;
};

