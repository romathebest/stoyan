#include "Matmod/System.h"

namespace mathmod
{
	System::System(void):  
        m_Process(""),
        m_DifOperator(""),
        m_RightSideOfEquation(""),
        m_Parameters(0)
	{
        m_ControlParam = new bool[3];
        for (int i=0; i<3; ++i)
        {
            m_ControlParam[i] = false;
        }
	}


	System::~System(void)
	{
        delete m_ControlParam;
	}

	void System::setParameters(const PointStr& param)
	{
		m_Parameters = param;
	}

	PointStr System::getParameters() const
	{
		return m_Parameters;
	}

	int System::numParameters() const
	{
		return m_Parameters.size();
	}

	void System::setProcess(const Function& func)
	{
		m_Process = func;
	}

	Function System::getProcess() const
	{
		return m_Process;
	}

	void System::setDifferentialOperator(const Function& func)
	{
		m_DifOperator = func;
	}

	Function System::getDifferentialOperator() const
	{
		return m_DifOperator;
	}

	void System::setRightSideOfEquation(const Function& func)
	{
		m_RightSideOfEquation = func;	
	}

	Function System::getRightSideOfEquation() const
	{
		return m_RightSideOfEquation;
	}
		
	void System::addCondition(const Condition& condition)
	{
		//m_Conditions.push_back(point);
	}

	int System::numConditions() const
	{
		return m_InitialConditions.size() + m_BoundaryConditions.size() + m_CurrentConditions.size();
	}

    void System::addOutsideAreaPoint(const OutsideAreaPoint& point)
    {

    }

    int System::numOutsideAreaPoints() const
    {
        return 0;
    }

    void System::setProblemType(ProblemType type)
    {
        m_ProblemType = type;
    }

    ProblemType System::getProblemType()
    {
        return m_ProblemType;
    }

    void System::setControlParam(ControlParam type)
    {
        m_ControlParam = type;
    }

    bool* System::getControlParam()
    {
        return m_ControlParam;
    }

    void System::setControlType(ControlType type)
    {
        m_ControlType = type;
    }

    ControlType System::getControlType()
    {
        return m_ControlType;
    }

    void System::setArea(const Area &area)
    {
        m_Area = area;
    }

    Area System::getArea() const
    {
        return m_Area;
    }
}
