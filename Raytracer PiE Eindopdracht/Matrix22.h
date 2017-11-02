#ifndef MATRIX22_H
#define MATRIX22_H

#include <iostream>

/* A class that implements a 2-by-2 vector. Elements can be accessed with the [] (subscript)
*  operator. Elements are stored in row-major order.
*/

template <typename T>
class Matrix22
{
public:
    Matrix22(); // Default constructor: unity matrix;
    T& operator[] (int index); // Overloaded subscript operator

protected:
    T m_data[4];
};

template <typename T>
Matrix22<T>::Matrix22()
{
    m_data[0] = 1;
    m_data[1] = 0;
    m_data[2] = 0;
    m_data[3] = 1;
}


// Return a reference to a selected element (by index)
template <typename T>
T& Matrix22<T>::operator[] (int index)
{
    if(index < 0 || index > 3) // Boundary check
    {
        std::cerr << "Error: in Matrix22, index is out of bounds! \n";

    }
    return m_data[index];
}

// Multiply two 2-by-2 matrices
// WARNING: Not suitable for chaining!! Operator* acts from left to right, where matrix
// multiplication should be done from right to left.
template <typename T>
Matrix22<T> operator* (Matrix22<T> A, Matrix22<T> B)
{
    Matrix22<T> C;
    // First row
    C[0] = A[0]*B[0] + A[1]*B[2];
    C[1] = A[0]*B[1] + A[1]*B[3];
    // Second row
    C[2] = A[2]*B[0] + A[3]*B[2];
    C[3] = A[2]*B[1] + A[3]*B[3];

    return C;
}

#endif // MATRIX22_H
