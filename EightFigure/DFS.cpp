#include "stdafx.h"
#include "DFS.h"


DFS::DFS(void)
{
    route.clear();
}

DFS::DFS(EightFigureState startState,EightFigureState targetState)
    :SearchCore(startState,targetState)
{
    route.clear();
}


DFS::~DFS(void)
{
}

bool DFS::Search()
{
    startTime = clock();
    EightFigureState state,temp;
    route.push_back(startState);
    s.push(startState);
    do 
    {
        state = s.top();
        s.pop();
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
                    s.push(temp);
                    open.insert(temp.data);
                }
            }
        }
    }while (!s.empty());
    stopTime = clock();
    return false;
}

void DFS::SetDepth(int depth)
{
    this->depth = depth;
}

