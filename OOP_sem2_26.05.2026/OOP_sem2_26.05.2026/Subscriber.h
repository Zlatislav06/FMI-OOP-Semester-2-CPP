#pragma once
template <typename T>
class Subscriber
{
	virtual void update(T data) = 0;
	virtual ~Subscriber() = default;
};


