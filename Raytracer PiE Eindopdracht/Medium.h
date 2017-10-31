#ifndef MEDIUM_H
#define MEDIUM_H

#include "Component.h"


class Medium : public Component
{
    public:
        Medium(double length);
        Medium(double length, double index);

    private:
        double m_length;
        double m_index;

        void generateMatrix();

};

#endif // MEDIUM_H
