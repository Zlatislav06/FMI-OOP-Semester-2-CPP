#include "Poster.h"
template <typename T>
void Poster<T>::subscribe(Subscriber<T>* s)
{
	subscribers.push_back(s);
}
template <typename T>
void Poster<T>::unsubscribe(Subscriber<T>* s)
{
	subscribers.erase(remove(subscribers.begin(),
        subscribers.end(),
        sub),
        subscribers.end()
    );)
}
template <typename T>
void Poster<T>::notify()
{
    if (posts.empty()) {
        return;
    }

    for (Subscriber<T>* sub : subscribers) {
        sub->update(*posts.back());
    }
}
template <typename T>
void Poster<T>::createPost(T content)
{
	posts.push_back(content);
}