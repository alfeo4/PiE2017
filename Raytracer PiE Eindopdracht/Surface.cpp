#include "Surface.h"

Surface::Surface(double curvatureRadius, double indexBefore, double indexAfter)
{
    m_radius = curvatureRadius;
    m_index1 = indexBefore;
    m_index2 = indexAfter;

    generateMatrix();
}

/* The ray transfer matrix for a (curved) surface is
*       |    1             0   |
*       |(n1 - n2)/Rn2   n1/n2 |
*/
void Surface::generateMatrix()
{
    double C;
    if (m_radius == 0) // Flat surface
    {
        C = 0;
    }
    else // Curved surface
    {
        C = (m_index1 - m_index2) / (m_radius * m_index2);
    }
    setMatrix(1, 0, C, m_index1/m_index2);
}
