#include "wolframobject.h"

namespace mathmod
{

    char *WolframObject::directDiscretionProblem[] = {
        "lengthM0 = Length[M0x]; lengthMg = Length[Mgx];\n",
        "lengthL0 = Length[L0x]; lengthLg = Length[Lgx];\n",
        "H[x_] := Piecewise[{{0, x < 0}, {1, x >= 0}}];\n",
        "G11 = Table[N[G[L0x[[l]] - M0x[[m]], L0t[[l]] - M0t[[m]]]]  , {l, lengthL0}, {m, lengthM0}];\n",
        "G12 = Table[N[G[L0x[[l]] - Mgx[[m]], L0t[[l]] - Mgt[[m]]]]  , {l, lengthL0}, {m, lengthMg}];\n",
        "G21 = Table[N[G[Lgx[[l]] - M0x[[m]], Lgt[[l]] - M0t[[m]]]]  , {l, lengthLg}, {m, lengthM0}];\n",
        "G22 = Table[N[G[Lgx[[l]] - Mgx[[m]], Lgt[[l]] - Mgt[[m]]]]  , {l, lengthLg}, {m, lengthMg}];\n",
        "GMatrix = Join[Join[G11, G12, 2], Join[G21, G22, 2]];\n",
        "Y = Join[L0y, Lgy];\n",
        "uMatrix = PseudoInverse[GMatrix].Y;\n",
        "u0 = Part[uMatrix, 1 ;; lengthM0];\n",
        "ug = Part[uMatrix, lengthM0 + 1;; lengthM0 + lengthMg];\n",
        "yInfinity[x_, t_] :=NIntegrate[G[x - xx, t - tt]*u[xx, tt], {xx, X1, X2}, {tt, T1, T2}];\n",
        //"yInfinity[x_, t_] := Integrate[G[x - xx, t - tt]*u[xx, tt], {xx, X1 , X2}, {tt, T1, T2}];\n",
        "y0[x_, t_] := Sum[N[G[x - M0x[[m]], t - M0t[[m]]]*u0[[m]]], {m, 1, Length[u0]}];\n",
        "yg[x_, t_] := Sum[N[G[x - Mgx[[m]], t - Mgt[[m]]]*ug[[m]]], {m, 1, Length[ug]}];\n",
        //"yResult[x_, t_] := y0[x, t] + yg[x, t];\n",
        "yResult[x_, t_] := yInfinity[x,t] + y0[x, t] + yg[x, t];"
    };

    WolframObject::WolframObject(ISystem *system)
    {
    }

    bool WolframObject::open()
    {
        int error;
        m_LibraryEnvironment = MLInitialize(0);

        if(m_LibraryEnvironment == (MLENV)0)
        {
           printf("unable to initialize environment");
           return false;
        }

        m_WolframLink = MLOpenString(m_LibraryEnvironment, "-linkname \"C:\\Program Files\\Wolfram Research\\Mathematica\\8.0\\MathKernel.exe\" -mathlink", &error);


        if(m_WolframLink == (MLINK)0 || error != MLEOK)
        {
            printf("unable to create link to the Kernel");
            return false;
        }

        return true;
    }

    bool WolframObject::close()
    {
        MLClose(m_WolframLink);
        MLDeinitialize(m_LibraryEnvironment);

        return true;
    }

    char* WolframObject::buildInput()
    {
        return "";
    }

    const char* WolframObject::execute()
    {
        const char* inputString = buildInput();
        inputString = "Cos[2]";//example

        MLPutFunction(m_WolframLink, "EvaluatePacket", 1);
        MLPutFunction(m_WolframLink, "ToString", 1);
        MLPutFunction(m_WolframLink, "ToExpression", 1);
        MLPutString(m_WolframLink, inputString);
        MLEndPacket(m_WolframLink);

        /* send the packet */
        if(! MLFlush(m_WolframLink))
        {
            return "Error. Unable to flush an outgoing data buffered.";
        }

        int pkt;
        while ((pkt = MLNextPacket(m_WolframLink),pkt) && pkt != RETURNPKT)
        {
            MLNewPacket(m_WolframLink);
            if (MLError(m_WolframLink))
            {
                return "Error!";
            }
        }

        const char *str;
        MLGetString(m_WolframLink, &str);

        return str;
    }

}
