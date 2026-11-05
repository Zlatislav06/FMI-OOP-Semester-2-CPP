#pragma once
#include "Profile.h"
#include "Subscriber.h"
template <typename T>
class Reader : public Profile, public Subscriber<T> {
public:
    Reader(const string& username);

    void update(const T& data) override;
};

