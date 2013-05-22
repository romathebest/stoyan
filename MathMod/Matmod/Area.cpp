#include "Area.h"

namespace mathmod
{

	Area::Area(void)
	{
	}

	Area::Area(PointStr param)
	{
		for(int i = 0; i < param.size(); i++)
			m_Ranges.push_back(Rangef(param[0]));
	}

	Rangef& Area::operator[] (int index)
	{
		return m_Ranges[index];
	}

    void Area::addRange(const Rangef& range)
    {
        m_Ranges.push_back(range);
    }

    int Area::size()
    {
        return m_Ranges.size();
    }

	Area::~Area(void)
	{
	}

    string Area::toString()
    {
        string res = "";

        for(unsigned int i = 0; i < m_Ranges.size(); i++)
        {
            res += m_Ranges[i].toString();
            res += "\n";
        }
        return res;
    }
}
