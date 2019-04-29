#pragma once
#include "Tutorial.h"

template <typename T>
class Comparator 
{

public:
	
	virtual bool compare(T, T) = 0;
	virtual ~Comparator();

};




template<typename T>
inline Comparator<T>::~Comparator()
{
}
