#ifndef _SYSTEM_H_
#define _SYSTEM_H_ 

#include "Point.h"
#include "mathmod.h"

#include <string>
#include <vector>

using std::vector;

namespace mathmod
{
    class System : public ISystem
	{
	public:
		System(void);
		~System(void);

		void setParameters(const PointStr& param);
		PointStr getParameters() const;
		int numParameters() const;

        void setGrinFunction(const Function& func);
        Function getGrinFunction() const;

		void setProcess(const Function& func);
		Function getProcess() const;

		void setDifferentialOperator(const Function& func);
		Function getDifferentialOperator() const;

		void setRightSideOfEquation(const Function& func);
		Function getRightSideOfEquation() const;
		
        void addCondition(Pointf condition);
        void setCondtion(vector<Pointf> conditions);
        vector<Pointf> getInitialConditions();
        vector<Pointf> getCurrentConditions();
		int numConditions() const;

        void addOutsideAreaPoint(const Pointf& point);
        void setOutsideAreaPoint(vector<Pointf> conditions);

		int numOutsideAreaPoints() const;

        void setProblemType(ProblemType type);
        ProblemType getProblemType();

        void setControlType(ControlType type);
        ControlType getControlType();

        void setArea(const Area& area);
        Area getArea() const;

	private:
		Function m_Process;
		Function m_DifOperator;
		Function m_RightSideOfEquation;
        Function m_Grin;

        std::vector<Pointf> m_InitialConditions;
        std::vector<Pointf> m_CurrentConditions;

        std::vector<Pointf> m_LeftRightOutsideAreaPoints;
        std::vector<Pointf> m_BottomOutsideAreaPoints;


        ProblemType m_ProblemType;
        ControlType m_ControlType;
		PointStr m_Parameters;
        Area m_Area;
	};

}

#endif //_SYSTEM_H_

