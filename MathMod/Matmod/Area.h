#ifndef _AREA_H_
#define _AREA_H_

#include "Range.h"
#include "Point.h"
#include <vector>

namespace mathmod
{
	class Area
	{
	public:
		Area();
        Area(PointStr param);
		~Area(void);
		
		Rangef& operator[] (int index);
        int size();

        void addRange(const Rangef &range);
	private:
		std::vector<Rangef> m_Ranges;
	};
}

#endif //_AREA_H_
