#include "Temp.h"

unsigned int Temp::N=0;
unsigned int Temp::Sum=0;

Temp::Temp()
{
    ++N;
    Sum+=N;
}
void Temp::Reset()
{
    N=0;
    Sum=0;
}
void Temp::init()
{
    m_val=0;
}
unsigned int Temp::GetSum()
{
    return Sum;
}
Temp::~Temp()
{
    //dtor
}
