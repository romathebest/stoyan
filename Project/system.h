#ifndef SYSTEM_H
#define SYSTEM_H

#include "point3.h"
#include "area.h"
#include "vector"
#include "string"
using namespace std;

namespace mathmod
{
    typedef string Function;

    class System
    {
    public:
        System(Area *area);
        void addCondition(Point3f p);
        void addObservation(Point3f p);
        void setArea(Area *area);
        void setGreensFunction(Function f);
        void setStateFunction(Function f);
        void setExternalDynamicPerturbationsFunction(Function f);
        ~System();
    private:
        vector<Point3f> m_L0;//початкові умови
        vector<Point3f> m_Lg;//крайові умови
        vector<Point3f> m_U0;//точки спостереження
        vector<Point3f> m_Ug;//точки спостереження
        Area *m_Area;//область
        Function m_G;//функція Гріна
        Function m_Y;//функція стану
        Function m_U;//зовнішньодинамічні збурення
    };


}

#endif // SYSTEM_H
