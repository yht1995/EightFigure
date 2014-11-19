#pragma once
#include "searchcore.h"
#include "EightFigureState.h"

class AStar :
    public SearchCore
{
struct cmp{
    bool operator ()(EightFigureState &a,EightFigureState &b)
    {
        return (a.fVaule<b.fVaule);
    }
};
public:
    AStar(void);
    AStar(EightFigureState startState,EightFigureState targetState,int type);
    ~AStar(void);
    bool Search();
    void SetFunc(int type);
private:
    int (AStar::*clac)(EightFigureState a,EightFigureState b);
    std::priority_queue<EightFigureState,std::vector<EightFigureState>,cmp> q;
    std::vector<EightFigureState> route;
    int ClacDifference(EightFigureState a,EightFigureState b);
    int ClacManhattan(EightFigureState a,EightFigureState b);
};

