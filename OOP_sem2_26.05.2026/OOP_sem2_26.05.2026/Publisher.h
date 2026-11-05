#pragma once
#include "Subscriber.h"
template <typename T>
class Publisher
{
public:
	
	virtual void subscribe(Subscriber<T>* s)=0;
	virtual void unsubscribe(Subscriber<T>* s)=0;
	virtual void notify()=0;
	virtual ~Publisher() = default;
};

