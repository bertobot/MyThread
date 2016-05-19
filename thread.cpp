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
void * thread::run_func(void *t) {
    // TODO: try this
    //reinterpret_cast<thread *>(t)->run();
    
    thread *tt = reinterpret_cast<thread *>(t);

    if (tt) {
        //tt->mut.lock();

        tt->run();

        tt->mut.lock();

        tt->running = false;
        tt->stopped = true;

        tt->mut.unlock();
    }
    else {
        printf("thread error: object null?\n");
    }

	pthread_exit(NULL);
    return NULL;
}
/////////////////////////////////////////////////
void thread::setstate(int s) {
    pthread_attr_setdetachstate(&attr, s);
}
/////////////////////////////////////////////////
void thread::start() {
    running = true;

    return_code = pthread_create(&actualThread, NULL, thread::run_func, this);
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

    // destroy attr
    pthread_attr_destroy(&attr);

	// only execute join if thread actually ran.
	if (!running)
		return;

    if (int rc = join() ) {
        printf("thread critical: error joining!!!\n");
        printf("rc: %d\n", rc);

		pthread_exit(NULL);

        return;
    }
}
/////////////////////////////////////////////////
void thread::stop() {
    printf("base class thread stop called.  this may not be a good thing.\n");
}
/////////////////////////////////////////////////
void thread::disableCancelState()
{
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
}
/////////////////////////////////////////////////
void thread::enableCancelState()
{
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
}
/////////////////////////////////////////////////
void thread::setCancelTypeAsync()
{
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
}
/////////////////////////////////////////////////
void thread::setCancelTypeDeferred()
{
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
}
/////////////////////////////////////////////////
int thread::cancel()
{
	return pthread_cancel(actualThread);
}
/////////////////////////////////////////////////
thread::~thread() {
    // TODO: lock run and destructor (and maybe even constructor?)

    //mut.lock();

    //destroy();
    cleanup();

   //mut.unlock();
}
/////////////////////////////////////////////////
