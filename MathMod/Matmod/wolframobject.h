#ifndef WOLFRAMOBJECT_H
#define WOLFRAMOBJECT_H

#include "mathmod.h"
#include "mathlink.h"

#include <string>

using std::string;


namespace mathmod
{
    class WolframObject
    {
    public:
        WolframObject(ISystem *system);
        bool open();
        bool close();
        const char* execute();
    private:
        char* buildInput();
    private:
        ISystem *pSystem;

        MLENV m_LibraryEnvironment;
        MLINK m_WolframLink;

        static char *directDiscretionProblem[];
    };
}

#endif // WOLFRAMOBJECT_H
