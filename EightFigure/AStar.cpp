#include "stdafx.h"
#include "AStar.h"


AStar::AStar(void)
{
    route.clear();
}

AStar::AStar(EightFigureState startState,EightFigureState targetState,int type)
    :SearchCore(startState,targetState)
{
    route.clear();
    SetFunc(type);
}


AStar::~AStar(void)
{
}

int AStar::ClacDifference(EightFigureState a,EightFigureState b)
{
    char aArray[9];
    char bArray[9];
    a.GetDataArray(aArray);
    b.GetDataArray(bArray);
    int vaule = 0;
    for (int i = 0;i<9;i++)
    {
        if (aArray[i]!=bArray[i])
        {
            vaule++;
        }
    }
    return vaule;
}


int AStar::ClacManhattan(EightFigureState a,EightFigureState b)
{
    char aArray[9];
    char bArray[9];
    a.GetDataArray(aArray);
    b.GetDataArray(bArray);
    const int Manhattan[9][9]=
    {
    {0, 1, 2, 1, 2, 3, 2, 3, 4},  
    {1, 0, 1, 2, 1, 2, 3, 2, 3},  
    {2, 1, 0, 3, 2, 1, 4, 3, 2},  
    {1, 2, 3, 0, 1, 2, 1, 2, 3},  
    {2, 1, 2, 1, 0, 1, 2, 1, 2},  
    {3, 2, 1, 2, 1, 0, 3, 2, 1},  
    {2, 3, 4, 1, 2, 3, 0, 1, 2},  
    {3, 2, 3, 2, 1, 2, 1, 0, 1},  
    {4, 3, 2, 3, 2, 1, 2, 1, 0}};
    int distance = 0;
    for (int i = 0;i<9;i++)
    {
        for (int j = 0;j<9;j++)
        {
            if (aArray[i] == bArray[j])
            {
                distance += Manhattan[i][j];
                break;
            }
        }
    }
    return distance;
}

bool AStar::Search()
{
    startTime = clock();
    EightFigureState state,temp;
    startState.depth = 0;
    startState.fValue = (this->*clac)(startState,targetState);
    close.insert(startState.data);
    route.push_back(startState);
    q.push(startState);
    do 
    {
        state = q.top();
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
                temp.depth = state.depth + 1;
                temp.fValue = temp.depth + (this->*clac)(temp,targetState);
                if (!close.count(temp.data))
                {
                    temp.selfIdx = route.size();
                    temp.fatherIdx = state.selfIdx;
                    q.push(temp);
                    route.push_back(temp);
                    close.insert(temp.data);
                }
            }
        }
    }while (!q.empty());
    stopTime = clock();
    return false;
}

void AStar::SetFunc(int type)
{
    switch (type)
    {
    case (0):
        clac = &AStar::ClacDifference;
        break;
    case (1):
        clac = &AStar::ClacManhattan;
        break;
    default:
        break;
    }
}
