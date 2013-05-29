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

    string Passport::controlType()
    {
        switch(pSystem->getControlType())
        {
            case BOUNDARY_CONDITIONS:
                return "Крайові умови";
            case INITIAL_CONDITIONS:
                return "Початкові умови";
            case BOUNDARY_AND_INITIAL_CONDITIONS:
                return "Початкові та крайові умови";
            default:
                return "Чим керуємо невідомо :)";
        }
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
