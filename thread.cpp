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
    //return_code = pthread_create(&actualThread, NULL, run_func, (void *)this);
    return_code = pthread_create(&actualThread, NULL, run_func, this);
}
/////////////////////////////////////////////////
void thread::forceQuit() {
    // force-quit the thread
    pthread_exit(NULL);
}
/////////////////////////////////////////////////
void thread::join() {
    return_code = pthread_join(actualThread, (void **)&return_code);
}
/////////////////////////////////////////////////
void thread::destroy() {
    pthread_attr_destroy(&attr);
}
/////////////////////////////////////////////////
thread::~thread() {
    //destroy();
    pthread_exit(NULL);
}
/////////////////////////////////////////////////
static void *run_func(void *t) {

    // TODO: try this
    reinterpret_cast<thread *>(t)->run();

    /*
    thread *tt = (thread *)t;
    if (tt) {
        tt->run();
    }
    else {
        printf("thread error: object null?\n");
    }
    */
}
/////////////////////////////////////////////////
