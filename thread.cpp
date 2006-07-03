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
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
}
/////////////////////////////////////////////////
void thread::start() {
    return_code = pthread_create(&actualThread, NULL, run_func, (void *)this);
}
/////////////////////////////////////////////////
void thread::stop() {
    // force-quit the thread
    pthread_exit(NULL);
}
/////////////////////////////////////////////////
void thread::join() {
    return_code = pthread_join(actualThread, (void **)&return_code);
}
/////////////////////////////////////////////////
thread::~thread() {
    stop();
    pthread_attr_destroy(&attr);

    printf("destruct\n");
}
/////////////////////////////////////////////////
void *run_func(void *t) {
    thread *tt = (thread *)t;
    tt->run();
    tt->stop();
}
/////////////////////////////////////////////////
