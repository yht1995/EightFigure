#pragma once

enum Direction
{
    up = 0,
    down,
    left,
    right
};
class EightFigureState
{
private:
    void swap(char& a,char& b);
public:
    unsigned int data;
    int selfIdx;
    int fatherIdx;
    EightFigureState(void);
    EightFigureState(char *data);
    ~EightFigureState(void);
    bool SetDataArray(char *data);
    char* GetDataArray(char *data);
    bool Move(Direction direction);
    int InverseOrder();
    bool CanSolve(EightFigureState c);
    bool operator == (EightFigureState c);
    void operator = (EightFigureState c);
};

inline bool EightFigureState::operator == (EightFigureState c)
{
    return (this->data == c.data);
}