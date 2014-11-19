#include "stdafx.h"
#include "DFS.h"


DFS::DFS(void)
{
    route.clear();
}

DFS::DFS(EightFigureState startState,EightFigureState targetState,int depth)
    :SearchCore(startState,targetState)
{
    route.clear();
    SetDepth(depth);
}


DFS::~DFS(void)
{
}

bool DFS::Search()
{
    startTime = clock();
    EightFigureState state,temp;
    startState.depth = 0;
    route.push_back(startState);
    close.insert(startState.data);
    s.push(startState);
    do 
    {
        state = s.top();
        s.pop();
        while((depth != 0) && (state.depth > depth))
        {
            state = s.top();
            s.pop();
            if (s.empty())
            {
                return false;
            }
        }
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
                if (!close.count(temp.data))
                {
                    temp.depth = state.depth + 1;
                    temp.selfIdx = route.size();
                    temp.fatherIdx = state.selfIdx;
                    route.push_back(temp);
                    s.push(temp);
                    close.insert(temp.data);
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

