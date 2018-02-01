#ifndef POINT_TO_LINE_FUNCTOR_H
#define POINT_TO_LINE_FUNCTOR_H

#include "tools/point.h"
#include "tools/line.h"

class PointToLineFunctor
{
public:
    PointToLineFunctor(double x, double y, double z, bool debug = false);
    PointToLineFunctor(Point<double> point, bool debug = false);

    template<typename T>
    bool operator()(T const* line, T* residual) const
    {

        // Compute distnace
        Line<T> l(line);
        Point<T> p(T(m_point.x()),T(m_point.y()),T(m_point.z()));
        residual[0] = l.distance(p);

        // Display Error
        if (m_debug)
        {
            std::cout<<"Line: "<<l<<std::endl;
            std::cout<<"Point: "<<p<<std::endl;
            std::cout<<"Distance: "<<residual[0]<<std::endl;
        }

        return true;
    }

    Point<double> point();

private:
    bool m_debug;
    Point<double> m_point;
};

#endif // POINT_TO_LINE_FUNCTOR_H
