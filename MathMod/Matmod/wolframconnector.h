#ifndef WOLFRAMOBJECT_H
#define WOLFRAMOBJECT_H

//#include "mathmod.h"
#include "mathlink.h"

#include "Matmod/System.h"

#include <string>

using std::string;


namespace mathmod
{
    class WolframConnector
    {
    public:
        WolframConnector(System* system);
        bool open();
        bool close();
        const char* execute();
        bool isOpen();
    private:
        char* buildInput();
    private:
        ISystem *pSystem;

        bool m_IsOpened;

        MLENV m_LibraryEnvironment;
        MLINK m_WolframLink;

        static char *directDiscretionProblem[];
    };
}

#endif // WOLFRAMOBJECT_H
