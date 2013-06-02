#include "wolframconverter.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace mathmod
{
    WolframConverter::WolframConverter(ISystem *system)
        : m_pSystem(system)
    {
    }

    string WolframConverter::parameters() const
    {
        string res = "";
        PointStr param = m_pSystem->getParameters();
        int paramSize = param.size();

        for(int i = 0; i < paramSize - 1; i++)
        {
            res += param[i] + "_ ,";
        }
        res += param[paramSize - 1] + "_";
        return res;
    }

    int WolframConverter::numParameters() const
    {
        return m_pSystem->numParameters();
    }

    string WolframConverter::process()
    {
        string res = "y[" + parameters() + "] =" + m_pSystem->getProcess() + ";\n";
        return  res;
    }

    void WolframConverter::replaceAll( string &s, const string &search, const string &replace )
    {
        for( size_t pos = 0; ; pos += replace.length() )
        {
            pos = s.find( search, pos );
            if( pos == string::npos ) break;
            s.erase( pos, search.length() );
            s.insert( pos, replace );
        }
    }

    void WolframConverter::buildPlot2DString(vector<FixedStruct> fixedParam, string unfixedparam)
    {
        string param = m_pSystem->getProcess();
        for(int i = 0; i < fixedParam.size(); i++)
        {
            replaceAll(param, fixedParam[i].param, fixedParam[i].value);
        }
        m_Plot2D = "Plot[" + param + ", " + unfixedparam + "]";
    }

    string WolframConverter::plotString()
    {
        return m_Plot2D;
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
        return "u[x_, t_] := -((Pi^2 + 9)*Sin[t]*Sin[(Pi*x)/3])/9;";
    }

    string WolframConverter::problemType()
    {

    }

    string WolframConverter::controlType()
    {

    }

    string WolframConverter::area()
    {
        int aresize = m_pSystem->getArea().size();
        Area area = m_pSystem->getArea();
        string areaString = "";
        for(int i = 0; i < aresize; i++)
        {
            Rangef range = area[i];

            areaString += range.param + "_min = " + Converter::toStr(range.min) + ";\n";
            areaString += range.param + "_max = " + Converter::toStr(range.max) + ";\n";
        }
        return areaString;
    }

    string WolframConverter::grinFunction() const
    {
        string res = "G[" + parameters() + "] =" + m_pSystem->getGrinFunction() + ";\n";
        return res;
    }

    string WolframConverter::bigString(vector<string> v)
    {
        string str = "";
        for(int i = 0; i < v.size(); i++)
        {
            str += v[i];
        }
        return str;
    }

    string WolframConverter::buildCondtionString(string name, const vector<Pointf> condtions)
    {
        vector<string> conditionsVectorString;
        PointStr parameters = m_pSystem->getParameters();
        for(int i = 0; i < m_pSystem->numParameters(); i++)
        {
            conditionsVectorString.push_back(name + parameters[i] + " = {");
        }
        conditionsVectorString.push_back(name + "y = {");

        for(int i = 0; i < condtions.size(); i++)
        {
            Pointf point = condtions[i];
            for(int j = 0; j < point.size(); j++ )
            {
                if(i < condtions.size() - 1)
                conditionsVectorString[j] += Converter::toStr(point[j]) + ", ";
                else conditionsVectorString[j] += Converter::toStr(point[j]);
            }

        }

        for(int i = 0; i < conditionsVectorString.size(); i++)
        {
            conditionsVectorString[i] += "};\n";
        }

        return bigString(conditionsVectorString);
    }

    string WolframConverter::conditions()
    {
        return buildCondtionString("L0",m_pSystem->getInitialConditions())
                + buildCondtionString ("Lg", m_pSystem->getCurrentConditions());
    }

    string WolframConverter::controlParam()
    {
        return "";
    }
}
