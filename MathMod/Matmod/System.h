#ifndef _SYSTEM_H_
#define _SYSTEM_H_ 

#include "Point.h"
#include <string>
#include <vector>

namespace mathmod
{
	typedef std::string Function;
	typedef Pointf Condition;
	typedef Pointf OutsideAreaPoint;


	class System
	{
	public:
		System(void);
		~System(void);

		void setParameters(const PointStr& param);
		PointStr getParameters() const;
		int numParameters() const;

		void setProcess(const Function& func);
		Function getProcess() const;

		void setDifferentialOperator(const Function& func);
		Function getDifferentialOperator() const;

		void setRightSideOfEquation(const Function& func);
		Function getRightSideOfEquation() const;
		
		void addCondition(const Condition& condition);
		int numConditions() const;

		void addOutsideAreaPoint(const OutsideAreaPoint& point);
		int numOutsideAreaPoints() const;

	private:
		Function m_Process;
		Function m_DifOperator;
		Function m_RightSideOfEquation;

		std::vector<Condition> m_InitialConditions;
		std::vector<Condition> m_BoundaryConditions;
		std::vector<Condition> m_CurrentConditions;

		std::vector<OutsideAreaPoint> m_LeftRightOutsideAreaPoints;
		std::vector<OutsideAreaPoint> m_BottomOutsideAreaPoints;



		PointStr m_Parameters;
	};

}

#endif //_SYSTEM_H_

