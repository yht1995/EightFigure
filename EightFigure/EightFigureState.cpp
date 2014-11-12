#include "stdafx.h"
#include "EightFigureState.h"


EightFigureState::EightFigureState(void)
{
    selfIdx = NULL;
    fatherIdx = NULL;
}

EightFigureState::EightFigureState(char *data)
{
    selfIdx = NULL;
    fatherIdx = NULL;
    this->data = 0;
    for (int i = 0;i<9;i++)
    {
        this->data = this->data * 10 + data[i];
    }
}

EightFigureState::~EightFigureState(void)
{
}

char* EightFigureState::GetDataArray(char *data)
{
    int temp = this->data;
    for (int i = 0;i<9;i++)
    {
        data[8-i] = temp % 10;
        temp = temp /10;
    }
    return data;
}

 //r   c  0   1   2   3   4
 // 
 //0      0   0   0   0   0
 //1      0   0   1   2   0
 //2      0   3   4   5   0  
 //3      0   6   7   8   0  
 //4      0   0   0   0   0
bool EightFigureState::Move(Direction direction)
{
    const int move[9][4]={{-1,3,-1,1},{-1,4,0,2},{-1,5,1,-1},{0,6,-1,4},
    {1,7,3,5},{2,8,4,-1},{3,-1,-1,7},{4,-1,6,8},{5,-1,7,-1}};
    int temp = this->data;
    int zeroPos;
    char data[9];
    for (int i = 8;i>=0;i--)
    {
        data[i] = temp % 10;
        if (data[i] ==0)
        {
            zeroPos = i;
        }
        temp = temp /10;
    }
    if (move[zeroPos][direction] == -1)
    {
        return false;
    }
    else
    {
        data[zeroPos] = data[move[zeroPos][direction]];
        data[move[zeroPos][direction]] = 0;
        SetDataArray(data);
        return true;
    }
}

int EightFigureState::InverseOrder()
{
    char array[9];
    GetDataArray(array);
    int inverseOrder = 0;
    for (int i = 1;i<9;i++)
    {
        if (array[i] !=0)
        {
            for (int j =0;j<i;j++)
            {
                if (array[j] != 0)
                {
                    if (array[j] > array[i])
                    {
                        inverseOrder ++;
                    }
                }
            }
        }
    }
    return inverseOrder;
}

bool EightFigureState::SetDataArray(char *data)
{
    bool check[9] = {0,0,0,0,0,0,0,0,0};
    for (int i = 0;i<9;i++)
    {
        if (data[i]<0)
        {
            return false;
        }
        if (data[i]>8)
        {
            return false;
        }
    }
    for (int i = 0;i<9;i++)
    {
        if (check[data[i]])
        {
            return false;
        }
        else
        {
            check[data[i]] = true;
        }
    }
    for (int i = 0;i<9;i++)
    {
        if (!check[i])
        {
            return false;
        }
    }
    this->data = 0;
    for (int i = 0;i<9;i++)
    {
        this->data = this->data * 10 + data[i];
    }
    return true;
}

bool EightFigureState::CanSolve(EightFigureState c)
{
    return((this->InverseOrder()%2) == (c.InverseOrder()%2));
}