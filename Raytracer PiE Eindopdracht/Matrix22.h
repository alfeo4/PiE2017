#ifndef MATRIX22_H
#define MATRIX22_H

/* A class that implements a 2-by-2 vector. Elements can be accessed with the [] (subscript)
*  operator. Elements are stored in row-major order.
*/

template <typename T>
class Matrix22
{
public:
    T& operator[] (int index);

protected:
    T m_data[4];
};

// Access vector elements
template <typename T>
T& Matrix22<T>::operator[] (int index)
{
    if(index < 0 || index > 3) // Boundary check
    {
        // TODO throw error?
    }
    return m_data[index];
}

#endif // MATRIX22_H
