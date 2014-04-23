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
class conditionVariable {
public:
    conditionVariable(mutex *m);

    virtual ~conditionVariable();

    void wait();

    void signal();

    void broadcast();

    bool empty();

    int waiting() const;

private:
    pthread_cond_t mCV; 

    mutex mLock;

    int mWaiting;

};
/////////////////////////////////////////////////
#endif
// vim: ts=4:sw=4:expandtab

