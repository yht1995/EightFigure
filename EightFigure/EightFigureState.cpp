#include "stdafx.h"
#include "EightFigureState.h"


EightFigureState::EightFigureState(void)
{
}

EightFigureState::EightFigureState(int *data)
{
    this->data = 0;
    for (int i = 0;i<9;i++)
    {
        this->data = this->data * 10 + data[i];
    }
}

EightFigureState::~EightFigureState(void)
{
}

int* EightFigureState::GetDataArray(int *data)
{
    unsigned int temp = this->data;
    for (int i = 0;i<9;i++)
    {
        data[i] = temp % 10;
        temp = temp /10;
    }
    return data;
}


