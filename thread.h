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

#include "mutex.h"

// func declaration of our friend
static void *run_func(void *t);

/////////////////////////////////////////////////
class thread {
protected:
    volatile int return_code;
    volatile bool running;
    volatile bool stopped;

    pthread_t actualThread;
    pthread_attr_t attr;
    friend void *run_func(void*);

    mutex mut;

public:
    thread();

    void setstate(int);
    void start();
    void stop();
    virtual void run() = 0;
    int join();

    int forceQuit();
    int destroy();
    void exit();
    void cleanup();

    int getReturnCode() { return return_code; }
    bool isRunning() { return running && !stopped; }
    bool isStopped() { return !running && stopped; }

    virtual ~thread();
};
/////////////////////////////////////////////////
#endif
