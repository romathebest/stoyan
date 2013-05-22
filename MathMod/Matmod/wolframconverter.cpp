#include "wolframconverter.h"

namespace mathmod
{
    WolframConverter::WolframConverter(ISystem *system)
        : m_pSystem(system)
    {
    }

    string WolframConverter::parameters() const
    {
        return m_pSystem->getParameters().toString();
    }

    int WolframConverter::numParameters() const
    {
        return m_pSystem->numParameters();
    }

    string WolframConverter::process()
    {
        string res = "y[";
        res += parameters();
        res += "] =";
        res += m_pSystem->getProcess();
        res += ";";
        return  res;
    }

    string WolframConverter::differentialOperator() const
    {
        string res = "L[";
        res += parameters();
        res += "] =";
        res += m_pSystem->getDifferentialOperator();
        res += ";";
        return  res;
    }
    string WolframConverter::rightSideOfEquation() const
    {
        return "";
    }

    string WolframConverter::problemType()
    {

    }

    string WolframConverter::controlType()
    {

    }

    string WolframConverter::area()
    {

    }
}
