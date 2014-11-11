#pragma once
#include "searchcore.h"
class WFS :
    public SearchCore
{
public:
    WFS(void);
    WFS(EightFigureState startState,EightFigureState targetState);
    bool Search();
    ~WFS(void);
private:
    std::queue<EightFigureState> q;
    std::vector<EightFigureState> route;
};

