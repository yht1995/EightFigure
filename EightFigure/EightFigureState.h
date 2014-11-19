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
    int data;
    int depth;
    int selfIdx;
    int fatherIdx;
    int fVaule;
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

inline void EightFigureState::operator=(EightFigureState c)
{
    this->data = c.data;
    this->selfIdx = c.selfIdx;
    this->fatherIdx = c.fatherIdx;
    this->depth = c.depth;
}

inline void EightFigureState::swap(char& a,char& b)
{
    char t = a;
    a = b;
    b = t;
}