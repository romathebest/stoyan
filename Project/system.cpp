#include "system.h"

namespace mathmod
{
    System::System(Area *area)
    {
        m_Area = area;
    }

    void System::addCondition(Point3f p)
    {
        if(m_Area->isInitial(p))
        {
            m_L0.push_back(p);
        }
        else
        {
            m_Lg.push_back(p);
        }
    }

    void System::addObservation(Point3f p)
    {
        Position position = m_Area->position(p);
        if(position == LEFT || position == RIGHT)
        {
            m_U0.push_back(p);
        }
        else if(position == DOWN)
        {
            m_Ug.push_back(p);
        }
    }

    void System::setGreensFunction(Function f)
    {
        m_G = f;
    }

    void System::setStateFunction(Function f)
    {
        m_Y = f;
    }

    void System::setExternalDynamicPerturbationsFunction(Function f)
    {
        m_U = f;
    }
}
