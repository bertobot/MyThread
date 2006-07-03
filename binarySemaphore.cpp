/////////////////////////////////////////////////
// binarySemaphore.cpp
// robert beatty
// spring 2005
//
// this code is GPL'd
//

#include "binarySemaphore.h"
/////////////////////////////////////////////////
binarySemaphore::binarySemaphore() : semaphore() {
    capacity = 0;
}
/////////////////////////////////////////////////
binarySemaphore::binarySemaphore(int c) : semaphore(c) {
    if (c >= 1)
        capacity = 1;
    else
        capacity = 0;
}
/////////////////////////////////////////////////
void binarySemaphore::P() {
    ++numThreadsWaiting;
    if (++slot > 1) {
        slot = 1;
        cv.wait();
    }
    --numThreadsWaiting;
}
/////////////////////////////////////////////////
void binarySemaphore::V() {
    if (--slot < 0)
        slot = 0;
    cv.signal();
}
/////////////////////////////////////////////////
binarySemaphore::~binarySemaphore() {

}
/////////////////////////////////////////////////
