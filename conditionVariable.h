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
//class conditionVariable : public mutex {
class conditionVariable {
protected:
    pthread_cond_t cv;
    mutex *mtx;
    int numWaiting;

public:
    conditionVariable();

    conditionVariable(mutex *);

    void assocMutex(mutex *);
    virtual void signal();
    virtual void wait();
    virtual void signalAll();

    bool empty();
    int waiting();

    virtual ~conditionVariable();
};
/////////////////////////////////////////////////
#endif
