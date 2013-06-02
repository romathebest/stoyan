#ifndef WOLFRAMCONVERTER_H
#define WOLFRAMCONVERTER_H

#include "mathmod.h"

namespace mathmod
{
    class WolframConverter : public IConverterObject
    {
    public:
        WolframConverter(ISystem *system);
        virtual string parameters() const;
        virtual int numParameters() const;
        virtual string process();
        virtual string processFor2DGraphic(vector<FixedStruct> fixedParam, string unfixedparam);
        virtual string differentialOperator() const;
        virtual string rightSideOfEquation() const;

        virtual string problemType();
        virtual string controlType();
        virtual string controlParam();

        virtual string grinFunction() const;

        virtual string area();

        virtual string conditions();

    private:
        void replaceAll( string &s, const string &search, const string &replace );
        string bigString(vector<string> v);
        string buildCondtionString(string name, const vector<Pointf> condtions);
    private:
        ISystem *m_pSystem;
    };
}

#endif // WOLFRAMCONVERTER_H
