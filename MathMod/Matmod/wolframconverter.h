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
        virtual string differentialOperator() const;
        virtual string rightSideOfEquation() const;

        virtual string problemType();
        virtual string controlType();
        virtual string controlParam();

        virtual string grinFunction() const;

        virtual string area();

        virtual string conditions();

    private:
        string bigString(vector<string> v);
        string buildCondtionString(string name, const vector<Pointf> condtions);
    private:
        ISystem *m_pSystem;
    };
}

#endif // WOLFRAMCONVERTER_H
