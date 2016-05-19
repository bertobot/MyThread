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

/////////////////////////////////////////////////
class thread {
private:
    volatile int return_code;
    volatile bool running;
    volatile bool stopped;

    pthread_t actualThread;
    pthread_attr_t attr;

    mutex mut;

    static void * run_func(void*);

public:
    thread();

    void setstate(int);
    void start();
    void stop();
    virtual void run() = 0;
    int join();

    int forceQuit();

    void exit();
	int cancel();
    void cleanup();
	
	// TODO: fix or remove.  do not use.
	int destroy();

    int getReturnCode() { return return_code; }
    bool isRunning() { return running && !stopped; }
    bool isStopped() { return !running && stopped; }
    
    void enableCancelState();
	void disableCancelState();
	void setCancelTypeAsync();
	void setCancelTypeDeferred();

    virtual ~thread();
};
/////////////////////////////////////////////////
#endif
