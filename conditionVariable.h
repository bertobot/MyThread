/////////////////////////////////////////////////
// conditionVariable.h
// robert beatty
// spring 2005
//
// this code is GPL'd
//

#ifndef __conditionVariable_h_
#define __conditionVariable_h_
/////////////////////////////////////////////////
#include "mutex.h"
/////////////////////////////////////////////////
class conditionVariable : public mutex {
protected:
    pthread_cond_t cv;
    int numWaiting;

public:
    conditionVariable();

    virtual void signal();
    virtual void wait();
    virtual void wait(int);
    virtual void signalAll();

    bool empty();
    int waiting();

    virtual ~conditionVariable();
};
/////////////////////////////////////////////////
#endif
