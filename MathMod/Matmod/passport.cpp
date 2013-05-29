#include "passport.h"

namespace mathmod
{
    Passport::Passport(ISystem *system)
        : pSystem(system)
    {

    }

    Passport::~Passport()
    {

    }

    string Passport::parameters() const
    {
        return pSystem->getParameters().toString();
    }

    int Passport::numParameters() const
    {
        return pSystem->numParameters();
    }

    string Passport::process()
    {
        return pSystem->getProcess();
    }

    string Passport::differentialOperator() const
    {
        return pSystem->getDifferentialOperator();
    }

    string Passport::rightSideOfEquation() const
    {
        return "u(t, " + pSystem->getParameters().toString() + ") = " + pSystem->getRightSideOfEquation();
    }

    string Passport::problemType()
    {
        switch(pSystem->getProblemType())
        {
            case DIRECT_PROBLEM:
                return "Пряма задача";
            case INVERSE_PROBLEM:
                return "Обернена задача";
            default:
                return "Тип задачі не визначений";
        }
    }

    string Passport::controlParam()
    {
        bool* control = (bool*)pSystem->getControlParam();
        string result = "";

        if (control == NULL) return "NOT INITIALIZE!";

        if ((!control[0])&&(!control[1])&&(!control[2]))
        {
            return "Чим керуємо невідомо :)";
        }
        else
        {
            if (control[0])
            {
                result += "функція керування;  ";
            }
            if (control[1])
            {
                result += "початкові умови;  ";
            }
            if (control[2])
            {
                result += "крайові умови.";
            }
        }
        return result;
    }

    string Passport::area()
    {
        return pSystem->getArea().toString();
    }

    string Passport::grinFunction() const
    {
        return pSystem->getGrinFunction();
    }

    string Passport::conditions()
    {
        return "undefinded";
    }
}
