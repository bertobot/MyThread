/////////////////////////////////////////////////
// semaphore.cpp
// robert beatty
// spring 2005
//
// this code is GPL'd
//


#include "semaphore.h"
/////////////////////////////////////////////////
semaphore::semaphore() {
    capacity = 1;
    slot = 0;
    numThreadsWaiting = 0;
    locked = false;
}
/////////////////////////////////////////////////
semaphore::semaphore(int c) {
    capacity = c;
    slot = 0;
    numThreadsWaiting = 0;
    locked = false;
}
/////////////////////////////////////////////////
void semaphore::P() {
    ++numThreadsWaiting;
    if (++slot > capacity) {
        slot = capacity;
        cv.wait();
    }
}
/////////////////////////////////////////////////
void semaphore::V() {
    if (--slot < capacity) {
        cv.signal();
        if (slot <= 0)
            slot = 0;
    }
    --numThreadsWaiting;
}
/////////////////////////////////////////////////
void semaphore::VP(semaphore& s) {
    mut.lock();
    V();
    s.P();
    mut.unlock();
}
/////////////////////////////////////////////////
bool semaphore::empty() {
    return (slot == 0);
}
/////////////////////////////////////////////////
bool semaphore::full() {
    return (slot >= capacity);
}
/////////////////////////////////////////////////
int semaphore::waiting() {
    return numThreadsWaiting;
}
/////////////////////////////////////////////////
int semaphore::slots() {
    return slot;
}
/////////////////////////////////////////////////
semaphore::~semaphore() {

}
/////////////////////////////////////////////////
