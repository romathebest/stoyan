#include "area.h"

namespace mathmod
{
    Area::Area()
    {
    }

    Area::Area(Point3f leftBottom, Point3f rightTop)
    {
        m_LeftBottomPoint = leftBottom;
        m_RightTopPoint = rightTop;
    }

    Area::Area(float x1, float t1, float x2, float t2)
    {
        m_LeftBottomPoint.set(x1, t1, 0);
        m_RightTopPoint.set(x2, t2, 0);
    }

    void Area::setLeftBottomPoint(Point3f point)
    {
        m_LeftBottomPoint = point;
    }

    void Area::setLeftBottomPoint(float x, float t)
    {
        m_LeftBottomPoint.set(x, t, 0);
    }

    void Area::setRightTopPoint(Point3f point)
    {
        m_RightTopPoint = point;
    }

    void Area::setRightTopPoint(float x, float t)
    {
        m_RightTopPoint.set(x, t, 0);
    }

    Point3f Area::getLeftBottomPoint()
    {
        return m_LeftBottomPoint;
    }

    Point3f Area::getRightBottomPoint()
    {
        return m_RightTopPoint;
    }

    Position Area::position(Point3f point)
    {
        if(point.y < m_LeftBottomPoint.y)
        {
            if(m_LeftBottomPoint.x > point.x && point.x < m_RightTopPoint.x)
            {
                return DOWN;
            }
            else
            {
                return UNKNOWN;
            }
        }
        else if (point.y > m_RightTopPoint.y)
        {
            if(m_LeftBottomPoint.x > point.x && point.x < m_RightTopPoint.x)
            {
                return UP;
            }
            else
            {
                return UNKNOWN;
            }
        }
        else if (point.x < m_LeftBottomPoint.x)
        {
            return LEFT;
        }
        else if (point.x > m_RightTopPoint.x)
        {
            return RIGHT;
        }
        else return INSIDE;
    }

    bool Area::isInitial(Point3f point)
    {
        if(point.x == m_LeftBottomPoint.x && point.y == m_LeftBottomPoint.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}
