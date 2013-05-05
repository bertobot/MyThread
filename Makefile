# makefile
RELEASE_DIR=MyThread_release
RELEASE_INCLUDE=$(RELEASE_DIR)/include/MyThread
RELEASE_LIB=$(RELEASE_DIR)/lib

ifndef CC
CC=g++
endif

CC+=-Wall $(CCFLAGS)

LIB=-lpthread
OBJ=\
mutex.o \
semaphore.o \
binarySemaphore.o \
conditionVariable.o \
thread.o 

lib: $(OBJ)
	ar rs libMyThread.a $(OBJ)
	
lib_release: lib
	mkdir -p $(RELEASE_INCLUDE)
	cp *.h $(RELEASE_INCLUDE)
	mkdir -p $(RELEASE_LIB)
	cp libMyThread.a $(RELEASE_LIB)

install: lib
	mkdir -p /usr/local/include/MyThread
	cp *.h /usr/local/include/MyThread
	mkdir -p /usr/local/lib
	cp *.a /usr/local/lib

mutex.o: mutex.cpp
	$(CC) -c mutex.cpp
	
semaphore.o: semaphore.cpp
	$(CC) -c semaphore.cpp

binarySemaphore.o: binarySemaphore.cpp
	$(CC) -c binarySemaphore.cpp

thread.o: thread.cpp
	$(CC) -c thread.cpp

conditionVariable.o: conditionVariable.cpp
	$(CC) -c conditionVariable.cpp

clean:
	rm -f *.o

mrproper: clean
	rm -f libMyThread.a
	rm -f *~
