/////////////////////////////////////////////////
// conditionVariable.cpp
// robert beatty
// spring 2005
//
// this code is GPL'd
//


#include "conditionVariable.h"
/////////////////////////////////////////////////
conditionVariable::conditionVariable(mutex *m) {
    pthread_cond_init(&mCV, NULL);
    mLock = m;
    mWaiting = 0;
}
/////////////////////////////////////////////////
void conditionVariable::signal() {
    if (mWaiting > 0) {
        pthread_cond_signal(&mCV);
    }
}
/////////////////////////////////////////////////
void conditionVariable::wait() {
    ++mWaiting;

    pthread_cond_wait(&mCV, &(mLock.getMutex() ) );

    --mWaiting;
}
/////////////////////////////////////////////////
void conditionVariable::broadcast() {
    pthread_cond_broadcast(&mCV);
}
/////////////////////////////////////////////////
bool conditionVariable::empty() {
    return (mWaiting == 0);
}
/////////////////////////////////////////////////
int conditionVariable::waiting() const {
    return mWaiting;
}
/////////////////////////////////////////////////
conditionVariable::~conditionVariable() {
    pthread_cond_destroy(&mCV);
}
/////////////////////////////////////////////////
// vim: ts=4:sw=4:expandtab

