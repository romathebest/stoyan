#ifndef WOLFRAMOBJECT_H
#define WOLFRAMOBJECT_H

#include "mathmod.h"


namespace mathmod
{
    class WolframObject //: public IConverterObject
    {
    public:
        WolframObject(ISystem *system);
        /*string parameters();
        int numParameters();
        string process();
        string differentialOperator();
        string rightSideOfEquation();

        string problemType();
        string controlType();*/
    private:
        ISystem *pSystem;
    };
}

#endif // WOLFRAMOBJECT_H
