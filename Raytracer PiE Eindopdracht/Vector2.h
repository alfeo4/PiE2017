#ifndef VECTOR2_H
#define VECTOR2_H

/* A class that implements a 2-by-1 vector. Elements can be accessed with the [] (subscript)
*  operator.
*/

template <typename T>
class Vector2
{
public:
    T& operator[] (int index);

protected:
    T m_data[2];
};

// Access vector elements
template <typename T>
T& Vector2<T>::operator[] (int index)
{
    if(index < 0 || index > 1) // Boundary check
    {
        // TODO throw error?
    }
    return m_data[index];
}

#endif // VECTOR2_H
