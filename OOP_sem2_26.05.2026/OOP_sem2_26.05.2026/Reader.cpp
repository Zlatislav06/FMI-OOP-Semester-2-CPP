#include "Reader.h"
#include "Profile.h"
template <typename T>

Reader<T>::Reader(const string& username):Profile(username) {}
template <typename T>
void Reader<T>::update(const T& data) {
    cout << username
        << " received notification: "
        << data << endl;
}