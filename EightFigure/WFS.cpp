#include "stdafx.h"
#include "WFS.h"


WFS::WFS(void)
{
    route.clear();
}

WFS::WFS(EightFigureState startState,EightFigureState targetState)
    :SearchCore(startState,targetState)
{
    route.clear();
}


WFS::~WFS(void)
{
}

bool WFS::Search()
{
    startTime = clock();
    EightFigureState state,temp;
    route.push_back(startState);
    q.push(startState);
    do 
    {
        state = q.front();
        q.pop();
        if (state == targetState)
        {
            path.clear();
            while (state.fatherIdx>0)
            {
                path.push_back(state);
                state = route[state.fatherIdx];
            }
            path.push_back(state);
            path.push_back(startState);
            stopTime = clock();
            return true;
        }
        for (int i = 0;i<4;i++)
        {
            temp = state;
            if (temp.Move((Direction)i))
            {
                if (!open.count(temp.data))
                {
                    temp.selfIdx = route.size();
                    temp.fatherIdx = state.selfIdx;
                    route.push_back(temp);
                    q.push(temp);
                    open.insert(temp.data);
                }
            }
        }
    }while (!q.empty());
    stopTime = clock();
    return false;
}
