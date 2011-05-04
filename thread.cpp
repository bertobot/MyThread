/////////////////////////////////////////////////
// thread.cpp
// robert beatty
// funkejunx@aim.com
//
// this code is GPL'd
//
#include "thread.h"
/////////////////////////////////////////////////
thread::thread() {
    return_code = 0;
    running = false;
    stopped = false;

    pthread_attr_init(&attr);
    //pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
}
/////////////////////////////////////////////////
void thread::setstate(int s) {
    pthread_attr_setdetachstate(&attr, s);
}
/////////////////////////////////////////////////
void thread::start() {
    running = true;

    //return_code = pthread_create(&actualThread, NULL, run_func, (void *)this);
    return_code = pthread_create(&actualThread, NULL, run_func, this);
}
/////////////////////////////////////////////////
int thread::join() {
    return pthread_join(actualThread, (void **)&return_code);
}
/////////////////////////////////////////////////
int thread::destroy() {
    return pthread_attr_destroy(&attr);
}
/////////////////////////////////////////////////
void thread::exit() {
    pthread_exit(NULL);
}
/////////////////////////////////////////////////
void thread::cleanup() {
    //printf("thread debug: joining...\n");

	// only execute join if thread actually ran.
	if (!running)
		return;

    if (int rc = join() ) {
        printf("thread critical: error joining!!!\n");
        printf("rc: %d\n", rc);

        return;
    }

    /*
    printf("thread debug: exiting...\n");
    pthread_exit(NULL);
    */

    //printf("thread debug: done.\n");
}
/////////////////////////////////////////////////
void thread::stop() {
    printf("base class thread stop called.  this may not be a good thing.\n");
}
/////////////////////////////////////////////////
thread::~thread() {
    // TODO: lock run and destructor (and maybe even constructor?)

    mut.lock();

    //destroy();
    cleanup();

   mut.unlock();
}
/////////////////////////////////////////////////
static void *run_func(void *t) {
    // TODO: try this
    //reinterpret_cast<thread *>(t)->run();

    thread *tt = (thread *)t;
    if (tt) {
        tt->mut.lock();

        tt->run();

        tt->running = false;
        tt->stopped = true;

        tt->mut.unlock();
    }
    else {
        printf("thread error: object null?\n");
    }
}
/////////////////////////////////////////////////
