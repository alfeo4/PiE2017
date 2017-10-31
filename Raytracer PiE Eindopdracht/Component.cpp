#include "Component.h"

void Component::setMatrix(double A, double B, double C, double D)
{
    m_matrix[0] = A;
    m_matrix[1] = B;
    m_matrix[2] = C;
    m_matrix[3] = D;
}

Matrix22<double> Component::getMatrix()
{
    return m_matrix;
}
