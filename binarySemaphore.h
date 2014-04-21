/////////////////////////////////////////////////
// binarySemaphore.h
// robert beatty
// spring 2005
//
// this code is GPL'd
//

#ifndef __binarySemaphore_h_
#define __binarySemaphore_h_
/////////////////////////////////////////////////
#include "semaphore.h"
/////////////////////////////////////////////////
class binarySemaphore : public semaphore {
public:
    binarySemaphore(int capacity=0) : semaphore(c) {
        if (capacity > 1) setCapacity(1);
    }

    virtual ~binarySemaphore() { }
};
/////////////////////////////////////////////////
#endif
// vim: ts=4:sw=4:expandtab
