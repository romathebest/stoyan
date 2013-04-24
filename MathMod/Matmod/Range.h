#ifndef _RANGE_H_
#define _RANGE_H_

#include <string>

namespace mathmod
{
	template<typename T>
	class Range
	{
	public:
		T min, max;
		std::string param;
	public:
		Range();
		Range(std::string _param);
		Range(T _min, T _max, std::string _param);
		~Range();

		bool isIn(T val);
	};

	template <typename T>
	Range<T>::Range()
		: min(0), max(0), param("")
	{
	}

	template <typename T>
	Range<T>::Range(T _min, T _max, std::string _param)
		: min(_min), max(_max), param(_param)
	{
	}

	template <typename T>
	Range<T>::Range(std::string _param)
		: param(_param), min(0), max(0)
	{
	}

	template <typename T>
    bool Range<T>::isIn(T val)
	{
		if(min <= val && val <= max)
			return true;
		else return false;
	}

	template <typename T>
	Range<T>::~Range(void)
	{
	}

	typedef Range<int> Rangei;
	typedef Range<double> Ranged;
	typedef Range<float> Rangef;
}

#endif //_RANGE_H_
