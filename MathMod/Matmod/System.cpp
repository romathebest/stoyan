#include "Matmod/System.h"

namespace mathmod
{
	System::System(void):  
        m_Process(""),
        m_DifOperator(""),
        m_RightSideOfEquation(""),
        m_Parameters(0)
	{
	}


	System::~System(void)
	{

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
		
    void System::addCondition(Pointf condition)
	{
        if(condition[0] == m_Area[0].min)
        {
            m_InitialConditions.push_back(condition);
        }
        else
        {
            m_CurrentConditions.push_back(condition);
        }
	}

    void System::setCondtion(vector<Pointf> conditions)
    {
        for(int i = 0; i < conditions.size(); i++)
        {
            addCondition(conditions[i]);
        }
    }

	int System::numConditions() const
	{
        return 0;
        //return m_InitialConditions.size() + m_BoundaryConditions.size() + m_CurrentConditions.size();
	}

    void System::addOutsideAreaPoint(const Pointf& point)
    {
        m_LeftRightOutsideAreaPoints.push_back(point);
    }

    void System::setOutsideAreaPoint(vector<Pointf> conditions)
    {
        for(int i = 0; i < conditions.size(); i++)
        {
            addOutsideAreaPoint(conditions[i]);
        }
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

    void System::setGrinFunction(const Function& func)
    {
        m_Grin = func;
    }

    Function System::getGrinFunction() const
    {
        return m_Grin;
    }

    vector<Pointf> System::getInitialConditions()
    {
        return m_InitialConditions;
    }

    vector<Pointf> System::getCurrentConditions()
    {
        return m_CurrentConditions;
    }
}
