#include "stdafx.h"
#include "DFS.h"


DFS::DFS(void)
{
}

DFS::DFS(EightFigureState startState,EightFigureState targetState)
    :SearchCore(startState,targetState)
{
    open.clear();
}


DFS::~DFS(void)
{
}

int DFS::Search()
{
    startTime = clock();
    EightFigureState state,temp;
    s.push(startState);
    do 
    {
        state = s.top();
        s.pop();
        if (state == targetState)
        {
            while (state.father)
            {
                path.push_back(state);
                state = *state.father;
            }
            stopTime = clock();
            return true;
        }
        for (int i = 0;i<4;i++)
        {
            temp = state;
            if (temp.Move((Direction)i))
            {
                if (!Exist(temp))
                {
                    temp.father = &state;
                    s.push(temp);
                    open.push_back(temp);
                }
            }
        }
    } while (!s.empty());
    stopTime = clock();
    return false;
}

void DFS::SetDepth(int depth)
{
    this->depth = depth;
}

bool DFS::Exist(EightFigureState state)
{
    for (int i =0;i<open.size();i++)
    {
        if (state == open[i])
        {
            return true;
        }
    }
    return false;
}
