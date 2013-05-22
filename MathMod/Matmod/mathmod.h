#ifndef _MATHMOD_H_
#define _MATHMOD_H_

#include "Area.h"
#include "Point.h"
#include "iostream"
using std::string;

namespace mathmod
{
    typedef std::string Function;
    typedef Pointf Condition;
    typedef Pointf OutsideAreaPoint;

    enum ProblemType
    {
        DIRECT_PROBLEM = 0,
        INVERSE_PROBLEM = 1
    };

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

        virtual void setProcess(const Function& func) = 0;
        virtual Function getProcess() const = 0;

        virtual void setDifferentialOperator(const Function& func) = 0;
        virtual Function getDifferentialOperator() const = 0;

        virtual void setRightSideOfEquation(const Function& func) = 0;
        virtual Function getRightSideOfEquation() const = 0;

        virtual void setProblemType(ProblemType type) = 0;
        virtual ProblemType getProblemType() = 0;

        virtual void setControlType(ControlType type) = 0;
        virtual ControlType getControlType() = 0;

        virtual void addCondition(const Condition& condition) = 0;
        virtual int numConditions() const = 0;

        virtual void addOutsideAreaPoint(const OutsideAreaPoint& point) = 0;
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

        virtual string problemType() = 0;
        virtual string controlType() = 0;

        virtual string area() = 0;

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
