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
protected:
    int
        capacity,
        slot,
        numThreadsWaiting;

    mutex mut;
    bool locked;
    conditionVariable cv;

public:
    semaphore();
    semaphore(int);

    virtual void P();
    virtual void V();
    virtual void VP(semaphore&);

    bool empty();
    bool full();
    int waiting();
    int slots();

    virtual ~semaphore();
};
/////////////////////////////////////////////////
#endif
