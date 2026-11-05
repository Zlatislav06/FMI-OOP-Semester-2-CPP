#pragma once
#include "Profile.h"
#include "Publisher.h"
#include <memory>
template <typename T>
class Poster:public Publisher<T>,public Profile
{
private:
	vector<std::unique_ptr<T>> posts;
	vector<Subscriber<T>*> subscribers;
public:
	void subscribe(Subscriber<T>* s) override;
	void unsubscribe(Subscriber<T>* s) override;
	void notify() override;
	void createPost(T content);

};

