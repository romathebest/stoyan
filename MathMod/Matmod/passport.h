#ifndef PASSPORT_H
#define PASSPORT_H

#include "mathmod.h"
#include <string>
#include "Point.h"

using std::string;

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
        string buildConditionString(vector<Pointf> conditions);
    private:
        ISystem *pSystem;
    };
}

#endif // PASSPORT_H
