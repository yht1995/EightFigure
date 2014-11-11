#pragma once
#include "searchcore.h"
#include "EightFigureState.h"

class AStar :
    public SearchCore
{
struct cmp{
    bool operator ()(EightFigureState &a,EightFigureState &b)
    {
        return (a.fVaule>b.fVaule);
    }
};
public:
    AStar(void);
    AStar(EightFigureState startState,EightFigureState targetState);
    ~AStar(void);
    bool Search();
private:
    std::priority_queue<EightFigureState,std::vector<EightFigureState>,cmp> q;
    std::vector<EightFigureState> route;
    int ClacDifference(EightFigureState a,EightFigureState b);
    int ClacManhattan(EightFigureState a,EightFigureState b);
};

