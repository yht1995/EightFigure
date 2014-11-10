#pragma once
class EightFigureState
{
private:
    unsigned int data;
public:
    EightFigureState(void);
    EightFigureState(int *data);
    int* GetDataArray(int *data);
    bool operator == (const EightFigureState& c);
    ~EightFigureState(void);
};

inline bool EightFigureState::operator == (const EightFigureState& c)
{
    return (this->data == c.data);
}