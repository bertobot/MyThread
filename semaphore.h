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
public:
    semaphore(mutex *m, int capacity=1);

    virtual ~semaphore();

    void P();
    void V();
    void VP(semaphore&);

    bool empty();
    bool full();
    int waiting();
    int slots();

    void setCapacity(int capacity);

private:
    int
        mCapacity,
        mSlot,
        mNumThreadsWaiting;

    mutex mLock, mVPLock;
    conditionVariable *mCv;

};
/////////////////////////////////////////////////
#endif
// vim: ts=4:sw=4:expandtab
