#include "DynamicVector.h"
//#include "DynamicVector.h"
//#include "DynamicVector.h"
//#include <exception>
//
//
//template<typename T>
//void DynamicVector<T>::resize()
//{
//	this->cap *= 2;
//	T* new_arr = new T[this->cap];
//	for (int i = 0; i < this->size; i++)
//		new_arr[i] = this->elems[i];
//	delete[] this->elems;
//	this->elems = new_arr;
//
//}
//
//template<typename T>
//DynamicVector<T>::DynamicVector(int cap)
//{
//	this->cap = cap;
//	this->size = 0;
//	this->elems = new T[this->cap];
//
//
//
//}
//
//template<typename T>
//DynamicVector<T>::DynamicVector(const DynamicVector & v)
//{
//	this->cap = v.cap;
//	this->size = v.size;
//	this->elems = new T[this->cap];
//	int i = 0;
//	for (; i < this->size; i++)
//		this->elems[i] = v.elems[i];
//	
//}
//template<typename T>
//DynamicVector<T> & DynamicVector<T>::operator=(const DynamicVector & v)
//{
//	// TODO: insert return statement here
//
//	if (this == &v)
//		return *this;
//
//	this->cap = v.cap;
//	this->size = v.size;
//
//	delete[] this->elems;
//
//	this->elems = new T[this->cap];
//	int i = 0;
//	for (; i < this->size; i++)
//		this->elems[i] = v.elems[i];
//
//	return *this;
//}
// template<typename T>
// void DynamicVector<T>::add(T el)
// {
//	 if (this->cap == this->size)
//		 this->resize();
//	 int i = 0;
//	 for (; i < this->size; i++)
//		 if (this->elems[i] == el)
//			 throw ("This elemet already exists!");
//	 this->elems[this->size++] = el;
//	 
// }
// template<typename T>
// int DynamicVector<T>::get_size()
// {
//	 return this->size;
// }
//template<typename T>
//DynamicVector<T>::~DynamicVector()
//{
//	delete[] this->elems;
//}
//
//

