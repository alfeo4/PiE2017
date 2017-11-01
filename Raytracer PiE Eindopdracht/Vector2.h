#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include "Matrix22.h"

/* A class that implements a 2-by-1 vector. Elements can be accessed with the [] (subscript)
*  operator.
*/

template <typename T>
class Vector2
{
public:
    T& operator[] (int index); // Overloaded subscript operator
    Vector2<T>& operator*= (Matrix22<T> M); // Multiply this vector by a matrix

protected:
    T m_data[2];
};

// Return a reference to a selected element (by index)
template <typename T>
T& Vector2<T>::operator[] (int index)
{
    if(index < 0 || index > 1) // Boundary check
    {
        std::cerr << "Error: in Vector2, index is out of bounds \n";
    }
    return m_data[index];
}

// Left-multiply a vector by a matrix
template <typename T>
Vector2<T> operator* (Matrix22<T> M, Vector2<T> v)
{
    Vector2<T> u;
    u[0] = M[0] * v[0] + M[1] * v[1];
    u[1] = M[2] * v[0] + M[3] * v[1];
    return u;
}

// Left-multiply this vector by a matrix
template <typename T>
Vector2<T>& Vector2<T>::operator*= (Matrix22<T> M)
{
    Vector2<T> temp = M * (*this); // "this" is a pointer to the current vector2 object.
    m_data[0] = temp[0];
    m_data[1] = temp[1];
    return *this; // Return reference to this vector for chaining of assignments.
}

#endif // VECTOR2_H
