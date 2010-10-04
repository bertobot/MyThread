/////////////////////////////////////////////////
// mutex.cpp
// robert beatty
// spring 2005
//
// this code is GPL'd
//

#include "mutex.h"
/////////////////////////////////////////////////
mutex::mutex() {
    pthread_mutex_init(&mutexsum, NULL);
    //mutexsum = PTHREAD_MUTEX_INITIALIZER;
    //TODO: incomplete?
    //mutexsum =
    debug = false;
}
/////////////////////////////////////////////////
mutex::mutex(bool d) {
    pthread_mutex_init(&mutexsum, NULL);
    debug = d;
}
/////////////////////////////////////////////////
void mutex::setDebug(bool d) {
    debug = d;
}
/////////////////////////////////////////////////
void mutex::lock() {
    pthread_mutex_lock (&mutexsum);
    
    if (debug) printf("lock set.\n");
}
/////////////////////////////////////////////////
void mutex::tryLock() {
    pthread_mutex_trylock(&mutexsum);
    if (debug) printf("lock attempt.\n");
}
/////////////////////////////////////////////////
void mutex::unlock() {
    pthread_mutex_unlock (&mutexsum);
    if (debug) printf("lock unset.\n");
}
/////////////////////////////////////////////////
pthread_mutex_t & mutex::getMutex() {
    return mutexsum;
}
/////////////////////////////////////////////////
mutex::~mutex() {
    pthread_mutex_destroy(&mutexsum);
}
/////////////////////////////////////////////////
