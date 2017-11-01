#include "Surface.h"
Surface::Surface(double curvatureRadius, double indexBefore, double indexAfter)
{
    m_radius = curvatureRadius;
    m_index1 = indexBefore;
    m_index2 = indexAfter;

    generateMatrix();
}

void Surface::generateMatrix()
{
    double C = (m_index1 - m_index2) / (m_radius * m_index2);
    setMatrix(1, 0, C, m_index1/m_index2);
}
