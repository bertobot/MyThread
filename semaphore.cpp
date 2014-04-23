/////////////////////////////////////////////////
// semaphore.cpp
// robert beatty
// spring 2005
//
// this code is GPL'd
//


#include "semaphore.h"
/////////////////////////////////////////////////
semaphore::semaphore(mutex *m, int capacity) {
    mCapacity = capacity;
    mSlot = 0;
    mNumThreadsWaiting = 0;

    mCv = new conditionVariable(m);
}
/////////////////////////////////////////////////
semaphore::~semaphore() {
    if (mCv) {
        delete mCv;
        mCv = NULL;
    }
}
/////////////////////////////////////////////////
void semaphore::P() {
    mLock.lock();

    if (++mSlot > mCapacity) {
        ++mNumThreadsWaiting;
        mSlot = mCapacity;
        mLock.unlock();

        mCv->wait();
    }
    else
        mLock.unlock();
}
/////////////////////////////////////////////////
void semaphore::V() {
    mLock.lock();

    if (mSlot == mCapacity) {
        --mSlot;
        --mNumThreadsWaiting;
        mCv->signal();
    }

    else if (--mSlot < 0)
        mSlot = 0;

    mLock.unlock();
}
/////////////////////////////////////////////////
void semaphore::VP(semaphore& s) {
    mVPLock.lock();

    V();
    s.P();

    mVPLock.unlock();
}
/////////////////////////////////////////////////
bool semaphore::empty() {
    return (mSlot == 0);
}
/////////////////////////////////////////////////
bool semaphore::full() {
    return (mSlot >= mCapacity);
}
/////////////////////////////////////////////////
int semaphore::waiting() {
    return mNumThreadsWaiting;
}
/////////////////////////////////////////////////
int semaphore::slots() {
    return mSlot;
}

void semaphore::setCapacity(int capacity) {
    mCapacity = capacity;
}
/////////////////////////////////////////////////
// vim: ts=4:sw=4:expandtab
