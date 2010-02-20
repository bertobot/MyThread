/////////////////////////////////////////////////
// thread.h
// robert beatty
// funkejunx@aim.com
//
// this code is GPL'd
//
#ifndef __thread_h_
#define __thread_h_
/////////////////////////////////////////////////
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// func declaration of our friend
static void *run_func(void *t);

/////////////////////////////////////////////////

void *run_func(void *t);

class thread {
protected:
    int return_code;
    pthread_t actualThread;
    pthread_attr_t attr;
    friend void *run_func(void*);

public:
    thread();

    void setstate(int);
    void start();
    virtual void stop() = 0;
    virtual void run() = 0;
    void join();

    void forceQuit();
    void destroy();

    int getReturnCode() { return return_code; }

    virtual ~thread();
};
/////////////////////////////////////////////////
#endif
