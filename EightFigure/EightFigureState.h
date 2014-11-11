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
    unsigned int data;
    void swap(char& a,char& b);
public:
    EightFigureState(void);
    EightFigureState(char *data);
    ~EightFigureState(void);
    char* GetDataArray(char *data);
    bool Move(Direction direction);
    int InverseOrder();
    bool CanSolve(EightFigureState c);
    bool operator == (const EightFigureState c);
};

inline bool EightFigureState::operator == (const EightFigureState c)
{
    return (this->data == c.data);
}