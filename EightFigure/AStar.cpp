#include "stdafx.h"
#include "AStar.h"


AStar::AStar(void)
{
}

AStar::AStar(EightFigureState startState,EightFigureState targetState)
    :SearchCore(startState,targetState)
{

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
        if (aArray[i]!=aArray[i])
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
    int vaule = 0;
    for (int i = 0;i<9;i++)
    {
        for (int j = i;j<9;j++)
        {
            if (aArray[i] == bArray[j])
            {
                vaule += Manhattan[i][j];
                break;
            }
        }
    }
    return vaule;
}

bool AStar::Search()
{
    startTime = clock();
    EightFigureState state,temp;
    startState.fVaule = ClacManhattan(startState,startState) + ClacManhattan(startState,targetState);
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
                if (!close.count(temp.data))
                {
                    temp.fVaule = ClacManhattan(startState,temp) + ClacManhattan(temp,targetState);
                    temp.selfIdx = route.size();
                    temp.fatherIdx = state.selfIdx;
                    route.push_back(temp);
                    q.push(temp);
                    close.insert(temp.data);
                }
            }
        }
    }while (!q.empty());
    stopTime = clock();
    return false;
}
