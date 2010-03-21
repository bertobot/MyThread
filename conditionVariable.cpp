/////////////////////////////////////////////////
// conditionVariable.cpp
// robert beatty
// spring 2005
//
// this code is GPL'd
//


#include "conditionVariable.h"
/////////////////////////////////////////////////
conditionVariable::conditionVariable() : mutex() {
    pthread_cond_init(&cv, NULL);
    numWaiting = 0;
}
/////////////////////////////////////////////////
void conditionVariable::signal() {
    if (numWaiting > 0) {
        pthread_cond_signal(&cv);
        //--numWaiting;
    }
}
/////////////////////////////////////////////////
void conditionVariable::wait() {
    ++numWaiting;
    lock();
    pthread_cond_wait(&cv, &mutexsum);
    unlock();
    --numWaiting;
}
/////////////////////////////////////////////////
void conditionVariable::wait(int seconds) {
    ++numWaiting;
    lock();
    pthread_cond_wait(&cv, &mutexsum);
    unlock();
    --numWaiting;
}
/////////////////////////////////////////////////
void conditionVariable::signalAll() {
    pthread_cond_broadcast(&cv);
    //numWaiting = 0;
}
/////////////////////////////////////////////////
bool conditionVariable::empty() {
    return (numWaiting == 0);
}
/////////////////////////////////////////////////
int conditionVariable::waiting() {
    return numWaiting;
}
/////////////////////////////////////////////////
conditionVariable::~conditionVariable() {
    pthread_cond_destroy(&cv);
}
/////////////////////////////////////////////////
