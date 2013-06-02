#ifndef WOLFRAMOBJECT_H
#define WOLFRAMOBJECT_H

//#include "mathmod.h"
#include "mathlink.h"

#include "Matmod/System.h"
#include "Matmod/wolframconverter.h"

#include <string>

using std::string;


namespace mathmod
{
    class WolframConnector
    {
    public:
        WolframConnector(WolframConverter* wolframConverter);
        bool open();
        bool close();
        const char* execute();
        bool isOpen();
        bool buildGraphic();
    private:
        char* buildInput();
    private:
        WolframConverter *m_pWolframConverter;

        bool m_IsOpened;

        MLENV m_LibraryEnvironment;
        MLINK m_WolframLink;

        static char *directDiscretionProblem[];
    };
}

#endif // WOLFRAMOBJECT_H
