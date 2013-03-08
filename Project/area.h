#ifndef AREA_H
#define AREA_H

#include "point3.h"
namespace mathmod
{
    enum Position
    {
        LEFT = 0,
        RIGHT = 1,
        UP = 2,
        DOWN = 3,
        INSIDE = 4,
        UNKNOWN = 5
    };

    class Area
    {
    public:
        Area();
        Area(Point3f leftBottom, Point3f rightTop);
        Area(float x1, float t1, float x2, float t2);
        void setLeftBottomPoint(Point3f point);
        void setLeftBottomPoint(float x, float t);
        void setRightTopPoint(Point3f point);
        void setRightTopPoint(float x, float t);
        Point3f getLeftBottomPoint();
        Point3f getRightBottomPoint();
        Position position(Point3f point);
        bool isInitial(Point3f point);
    private:
        Point3f m_LeftBottomPoint;
        Point3f m_RightTopPoint;
    };
}

#endif // AREA_H
