#pragma once
#include "Tutorial.h"
#include <exception>
#include <assert.h>

typedef	void* TElem;

template <typename T>
class DynamicVector
{
private:
	int size, cap;
	T* elems;

	void resize();
public:
	DynamicVector(int cap = 100);
	DynamicVector(const DynamicVector &v);
	DynamicVector& operator=(const DynamicVector &v);
	//friend DynamicVector& operator+( const T &el, const DynamicVector &v);
	DynamicVector& operator+(const T &el );
	T& operator[](int index){
		return this->elems[index];
	}
	T operator[](int index) const {
		return this->elems[index];
	}

	~DynamicVector();

	void add(const T &el);
	int get_size();
	T* get_elems();
	void remove(const T &el);
	void update(const T &el_old,const T &el_new);
	T get_el(const T &el) ;

	//T* get_elems();
};
template<typename T>
DynamicVector<T> operator+(T el, const DynamicVector<T> &v);

//template <typename T>
//inline DynamicVector <T> :: ~DynamicVector()
//{
//
//}




template<typename T>
void DynamicVector<T>::resize()
{
	this->cap *= 2;
	T* new_arr = new T[this->cap];
	for (int i = 0; i < this->size; i++)
		new_arr[i] = this->elems[i];
	delete[] this->elems;
	this->elems = new_arr;

}

template<typename T>
DynamicVector<T>::DynamicVector(int cap)
{
	this->cap = cap;
	this->size = 0;
	this->elems = new T[this->cap];



}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector & v)
{
	this->cap = v.cap;
	this->size = v.size;
	this->elems = new T[this->cap];
	int i = 0;
	for (; i < this->size; i++)
		this->elems[i] = v.elems[i];

}
template<typename T>
DynamicVector<T> & DynamicVector<T>::operator=(const DynamicVector & v)
{
	// TODO: insert return statement here

	if (this == &v)
		return *this;

	this->cap = v.cap;
	this->size = v.size;

	delete[] this->elems;

	this->elems = new T[this->cap];
	int i = 0;
	for (; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}



template<typename T>
inline DynamicVector<T>&  DynamicVector<T>::operator+(const T & el)
{
	/*DynamicVector result_vector(*this);
	
	result_vector.add(el);
	return result_vector;*/

	this->add(el);
	return *this;
}



//template<typename T>
//inline DynamicVector<T> & DynamicVector<T>::operator+(DynamicVector<T> & v, const T & el)
//{
//	// TODO: insert return statement here
//	this->add(el);
//}

template<typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}


//----------------------------------------------------------------------------


template<typename T>
void DynamicVector<T>::add(const T &el)
{
	if (this->cap == this->size)
		this->resize();
	int i = 0;
	for (; i < this->size; i++)
		if (this->elems[i] == el)
			throw std::exception("This elemet already exists!");
	this->elems[this->size++] = el;

}
template<typename T>
int DynamicVector<T>::get_size()
{
	return this->size;
}

template<typename T>
inline T* DynamicVector<T>::get_elems()
{
	return this->elems;
}

template<typename T>
inline void DynamicVector<T>::remove(const T &el)
{
	int found = 0;
	int i = 0;
	for (; i < this->size; i++)
		if (this->elems[i] == el)
		{
			found = 1;
			this->size--;
			for (int j = i; j < this->size ; j++)
				this->elems[j] = this->elems[j + 1];
			break;
		}
	if(found == 0)
		throw std::exception("This elemet does not exist!");

			
}

template<typename T>
inline void DynamicVector<T>::update(const T &el_old,const T &el_new)
{
	int found = 0;
	int i = 0;
	for (; i < this->size; i++)
		if (this->elems[i] == el_old)
		{
			found = 1;
			this->elems[i] = el_new;
			break;
		}
	if (found == 0)
		throw std::exception("This elemet does not exist!");


}

template<typename T>
inline T DynamicVector<T>::get_el(const T & el)
{
	int found = 0;
	int i = 0;
	for (; i < this->size; i++)
		if (this->elems[i] == el)
		{
			found = 1;
			return this->elems[i];
		}
	if (found == 0)
		throw std::exception("This elemet does not exist!");

}

template<typename T>
inline DynamicVector<T> operator+(T el, const DynamicVector<T>& v)
{
	DynamicVector<T> result_vector(v);
	result_vector.add(el);
	return result_vector;
}
