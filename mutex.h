/////////////////////////////////////////////////
// mutex.h
// robert beatty
// spring 2005
//
// this code is GPL'd
//

#ifndef __mutex_h_
#define __mutex_h_
/////////////////////////////////////////////////
#include <pthread.h>
/////////////////////////////////////////////////
class mutex {
protected:
    pthread_mutex_t mutexsum;
    bool taken;

public:
    mutex();

    void lock();
    void tryLock();
    void unlock();

    virtual ~mutex();
};
/////////////////////////////////////////////////
#endif
