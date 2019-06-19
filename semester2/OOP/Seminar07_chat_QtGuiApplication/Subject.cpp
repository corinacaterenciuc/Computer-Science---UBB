#include "Subject.h"



Subject::Subject()
{
}

void Subject::registerObserver(Observer * obs)
{
	auto it = find(this->observers.begin(), this->observers.end(), obs);
	if (it != this->observers.end())
		throw std::exception("observer already here!");
	this->observers.push_back(obs);
}

void Subject::unregisterObserver(Observer * obs)
{
	auto it = find(this->observers.begin(), this->observers.end(),obs);
	if (it == this->observers.end())
		throw std::exception("observer note here!");
	this->observers.erase(it);
}


void Subject::notify()
{
	for (auto o : this->observers)
	{
		o->update();
	}
}

Subject::~Subject()
{
}
