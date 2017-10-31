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

/* The ray transfer matrix for a transparent medium is
*       |1 d|
*       |0 1|   Where d is the length of the medium.
*/
void Medium::generateMatrix()
{
    setMatrix(1, m_length, 0, 1);
}
