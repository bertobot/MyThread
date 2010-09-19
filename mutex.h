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
#include <stdio.h>
/////////////////////////////////////////////////
class mutex {
protected:
    pthread_mutex_t mutexsum;
    bool taken;
    bool debug;

public:
    mutex();
    mutex(bool);

    void setDebug(bool);

    void lock();
    void tryLock();
    void unlock();

    pthread_mutex_t & getMutex();

    virtual ~mutex();
};
/////////////////////////////////////////////////
#endif
