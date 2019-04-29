#pragma once
#include "vector"
#include <algorithm>

template <typename T>
class VRepository
{
protected:
	std::vector<T> &arr;
	//std::vector <T> &watch_list;

public:
	VRepository(std::vector<T> &a);
	virtual ~VRepository() {
	}

	virtual void add(const T &t);
	virtual void remove(const T &t) ;
	virtual void update(const T &t_old, const T &t_new) ;
	T get_tutorial(const T &t);
	virtual void incerement_like(const T&t) ;
	//int get_size_repo();
	//std::vector<T> get_tutorials();

	virtual void add_watch_list(const T &t) ;
	virtual void play_first_watch_list();
	virtual void delete_first_watch_list() ;
	virtual T get_first();
	virtual void open_file();
	//int get_size_watch();
	//std::vector<T> get_watch_list();


	std::vector<T> get_all();
	int get_size();

	virtual void like_first_watch_list() ;

};

template<typename T>
inline VRepository<T>::VRepository(std::vector<T>& a) :arr{ a }
{
}



template<typename T>
inline int VRepository<T>::get_size()
{
	return this->arr.size();
}

template<typename T>
inline void VRepository<T>::like_first_watch_list()
{
	/*auto it = std::find(this->arr.begin(), this->arr.end(), this->arr[0]);
	(*it).plus_like();*/
}

template<typename T>
inline std::vector<T> VRepository<T>::get_all()
{
	return this->arr;
}

//template<typename T>
//inline void VRepository<T>::play_first_watch_list()
//{
//	this->watch_list[0].play();
//}

template<typename T>
inline void VRepository<T>::add(const T & t)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t);
	if (it != this->arr.end())
		throw std::exception("The tutorial exists already!");
	this->arr.push_back(t);
}

template<typename T>
inline void VRepository<T>::remove(const T & t)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t);
	if (it == this->arr.end())
		throw std::exception("The tutorial does not exist!");
	this->arr.erase(it);
}

template<typename T>
inline void VRepository<T>::update(const T & t_old, const T & t_new)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t_old);
	if (it == this->arr.end())
		throw std::exception("The tutorial does not exist!");
	std::replace(this->arr.begin(), this->arr.end(), t_old, t_new);

}

template<typename T>
inline T VRepository<T>::get_tutorial(const T & t)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t);
	if (it == this->arr.end())
		throw std::exception("The tutorial does not exist!");
	return *it;
}

template<typename T>
inline void VRepository<T>::incerement_like(const T & t)
{
	auto it = std::find(this->arr.begin(), this->arr.end(), t);
	(*it).plus_like();
}

template<typename T>
inline void VRepository<T>::add_watch_list(const T & t)
{
	//this->arr.push_back(t);
}

template<typename T>
inline void VRepository<T>::play_first_watch_list()
{
	//this->arr[0].play();
}

template<typename T>
inline void VRepository<T>::delete_first_watch_list()
{
	//this->arr.erase(this->watch_list.begin());
}

template<typename T>
inline T VRepository<T>::get_first()
{
	return this->arr[0];
}

template<typename T>
inline void VRepository<T>::open_file()
{
	//
}
