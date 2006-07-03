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
protected:

public:
    binarySemaphore();
    binarySemaphore(int);

    void P();
    void V();

    virtual ~binarySemaphore();
};
/////////////////////////////////////////////////
#endif
