#ifndef _MATHMOD_H_
#define _MATHMOD_H_

#include "Area.h"
#include "Point.h"
#include "iostream"

#include <vector>
using std::string;
using std::vector;


namespace mathmod
{
    struct FixedStruct
    {
        string param;
        string value;
    };

    typedef std::string Function;

    enum ProblemType
    {
        DIRECT_PROBLEM = 0,
        INVERSE_PROBLEM = 1
    };

    /**
     * @brief ControlParam - bool mas[3]
     * fisrt - if true - present control function
     * second - if true - present initial condition
     * third - if true - present boundary condition
     */
    typedef bool* ControlParam;
    enum ControlType
    {
        BOUNDARY_CONDITIONS = 0,
        INITIAL_CONDITIONS = 1,
        BOUNDARY_AND_INITIAL_CONDITIONS = 2
    };

    class ISystem
    {
    public:
        virtual void setParameters(const PointStr& param) = 0;
        virtual PointStr getParameters() const = 0;
        virtual int numParameters() const = 0;

        virtual void setGrinFunction(const Function& func) = 0;
        virtual Function getGrinFunction() const = 0;

        virtual void setProcess(const Function& func) = 0;
        virtual Function getProcess() const = 0;

        virtual void setDifferentialOperator(const Function& func) = 0;
        virtual Function getDifferentialOperator() const = 0;

        virtual void setRightSideOfEquation(const Function& func) = 0;
        virtual Function getRightSideOfEquation() const = 0;

        virtual void setProblemType(ProblemType type) = 0;
        virtual ProblemType getProblemType() = 0;

        virtual void setControlParam(ControlParam type) = 0;
        virtual ControlParam getControlParam() = 0;

        virtual void setControlType(ControlType type) = 0;
        virtual ControlType getControlType() = 0;

        virtual void addCondition(Pointf condition) = 0;
        virtual void setCondtion(vector<Pointf> conditions) = 0;
        virtual int numConditions() const = 0;
        virtual vector<Pointf> getInitialConditions() = 0;
        virtual vector<Pointf> getCurrentConditions() = 0;

        virtual void addOutsideAreaPoint(const Pointf& point) = 0;
        virtual void setOutsideAreaPoint(vector<Pointf> conditions) = 0;
        virtual int numOutsideAreaPoints() const = 0;

        virtual  void setArea(const Area& area) = 0;
        virtual Area getArea() const = 0;
    };

    class IConverterObject
    {
    public:
        virtual string parameters() const = 0;
        virtual int numParameters() const = 0;
        virtual string process() = 0;
        virtual string differentialOperator() const = 0;
        virtual string rightSideOfEquation() const = 0;

        virtual string grinFunction() const = 0;

        virtual string problemType() = 0;
        virtual string controlParam() = 0;

        virtual string area() = 0;

        virtual string conditions() = 0;

        //virtual int numConditions() const = 0;
        //virtual int numOutsideAreaPoints() const = 0;
    };

    class IWolframObject
    {
    public:
        virtual string toWolfram();
    };
}

#endif //_MATHMOD_H_
