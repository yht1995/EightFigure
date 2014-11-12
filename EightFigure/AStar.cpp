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
    close.insert(startState.data);
    route.push_back(startState);
    open.push_back(startState);
    do 
    {
        state = *GetMinOpen();
        open.erase(GetMinOpen());
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
                temp.fVaule = ClacManhattan(startState,temp) + ClacManhattan(temp,targetState);
                std::vector<EightFigureState>::iterator iter;
                iter = ExistOpen(temp);
                if (iter != open.end())
                {
                    if (temp.fVaule < iter->fVaule)
                    {
                        iter->fatherIdx = state.selfIdx;
                    }
                }
                if (!close.count(temp.data))
                {
                    temp.selfIdx = route.size();
                    temp.fatherIdx = state.selfIdx;
                    route.push_back(temp);
                    open.push_back(temp);
                    close.insert(temp.data);
                }
            }
        }
    }while (!open.empty());
    stopTime = clock();
    return false;
}

std::vector<EightFigureState>::iterator AStar::GetMinOpen()
{
    std::vector<EightFigureState>::iterator i,minIter;
    int min = 9999;
    for (i = open.begin();i != open.end();i++)
    {
        if (i->fVaule <= min)
        {
            min = i->fVaule;
            minIter = i;
        }
    }
    return minIter;
}

std::vector<EightFigureState>::iterator AStar::ExistOpen(EightFigureState state)
{
    std::vector<EightFigureState>::iterator i,minIter;
    for (i = open.begin();i != open.end();i++)
    {
        if (*i == state)
        {
            return i;
        }
    }
    return open.end();
}
