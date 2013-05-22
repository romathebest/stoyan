#ifndef _POINT_H_
#define _POINT_H_ 

#include <vector>
#include <string>

using std::string;

namespace mathmod
{
	template<typename T>
	class Point
	{
	public:
		Point(void);
		Point(int size);

		T& operator[] (int index);
		int size() const;

        void push_back(T val);
        void clear();

        string toString();

		~Point(void);
	private:
		std::vector<T> m_Vector;
	};

	template <typename T>
	Point<T>::Point()
	{
        m_Vector.resize(0);
	}

	template <typename T>
	Point<T>::~Point(void)
	{
		m_Vector.clear();
	}

	template <typename T>
	Point<T>::Point(int size)
	{
		m_Vector.resize(size);
	}

	template <typename T>
	int Point<T>::size() const
	{
		return m_Vector.size();
	}

	template <typename T>
	T& Point<T>:: operator[] (int index)
	{
		return m_Vector[index];
	}

    template <typename T>
    void Point<T>::push_back(T val)
    {
        m_Vector.push_back(val);
    }

    template <typename T>
    void Point<T>::clear()
    {
        m_Vector.clear();
    }


    template <typename T>
    string Point<T>::toString()
    {
        string str = "";
        for(unsigned int i = 0; i < m_Vector.size() - 1; i++ )
        {
            str += m_Vector[i] +", ";
        }
        str += m_Vector[m_Vector.size() - 1];
        return str;
    }


	typedef Point<int> Pointi;
	typedef Point<double> Pointd;
	typedef Point<float> Pointf;
	typedef Point<std::string> PointStr;



}

#endif //_POINT_H_

