/////////////////////////////////////////////////
// semaphore.h
// robert beatty
// spring 2005
//
// this code is GPL'd
//




#ifndef __semaphore_h_
#define __semaphore_h_
/////////////////////////////////////////////////
#include "conditionVariable.h"
/////////////////////////////////////////////////
class semaphore {
private:
    int
        mCapacity,
        mSlot,
        mNumThreadsWaiting;

    mutex mLock, mVPLock;
    conditionVariable mCv;

public:
    semaphore(int capacity=1);

    virtual void P();
    virtual void V();
    virtual void VP(semaphore&);

    bool empty();
    bool full();
    int waiting();
    int slots();

    void setCapacity(int capacity);

    virtual ~semaphore();
};
/////////////////////////////////////////////////
#endif
// vim: ts=4:sw=4:expandtab
