# makefile
CC=g++ -Wall -g3
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
	mkdir MyThreadLib
	cp libMyThread.a *.h MyThreadLib/

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
