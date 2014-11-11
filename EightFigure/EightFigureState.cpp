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
    unsigned int temp = this->data;
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
    char data[5][5];
    bool result;
    memset(data,0,25*sizeof(char));
    char array[9];
    GetDataArray(array);
    int zeroc,zeror;
    for (int r = 1;r <= 3;r++)
    {
        for (int c = 1;c <= 3;c++)
        {
            data[r][c] = array[(r-1)*3+(c-1)];
            if (data[r][c] == 0)
            {
                zeroc = c;
                zeror = r;
            }
        }
    }
    switch (direction)
    {
    case up:
        if (data[zeror-1][zeroc])
        {
            swap(data[zeror][zeroc],data[zeror-1][zeroc]);
            result = true;
        }
        else
        {
            result = false;
        }
        break;
    case down:
        if (data[zeror+1][zeroc])
        {
            swap(data[zeror][zeroc],data[zeror+1][zeroc]);
            result = true;
        }
        else
        {
            result = false;
        }
        break;
    case left:
        if (data[zeror][zeroc-1])
        {
            swap(data[zeror][zeroc],data[zeror][zeroc-1]);
            result = true;
        }
        else
        {
            result = false;
        }
        break;
    case right:
        if (data[zeror][zeroc+1])
        {
            swap(data[zeror][zeroc],data[zeror][zeroc+1]);
            result = true;
        }
        else
        {
            result = false;
        }
        break;
    default:
        break;
    }
    for (int r = 1;r <= 3;r++)
    {
        for (int c = 1;c <= 3;c++)
        {
            array[(r-1)*3+(c-1)] = data[r][c];
        }
    }
    this->data = 0;
    for (int i = 0;i<9;i++)
    {
        this->data = this->data * 10 + array[i];
    }
    return result;
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