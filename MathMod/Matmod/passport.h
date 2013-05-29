#ifndef PASSPORT_H
#define PASSPORT_H

#include "mathmod.h"

namespace mathmod
{
    class Passport : public IConverterObject
    {
    public:
        Passport(ISystem *system);
        ~Passport();

        string parameters() const;
        int numParameters() const;
        string process();
        string differentialOperator() const;
        string rightSideOfEquation() const;

        string grinFunction() const;

        string problemType();
        string controlParam();

        string area();

        string conditions();
    private:
        ISystem *pSystem;
    };
}

#endif // PASSPORT_H
