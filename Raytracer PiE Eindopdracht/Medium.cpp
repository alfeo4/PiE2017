#include "Medium.h"

Medium::Medium(double length)
{
    m_length = length;
    m_index = 1;
    generateMatrix();
}

Medium::Medium(double length, double index)
{
    m_length = length;
    m_index = index;
    generateMatrix();
}

void Medium::generateMatrix()
{
    setMatrix(1, m_length, 0, 1);
}
