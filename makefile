CC = gcc
WARNING_FLAGS = -Wall -Wextra
EXE = prodcomm
SCAN_BUILD_DIR = scan-build-out

all: main.o reader.o munch1.o munch2.o writer.o queue.o
	$(CC) -o $(EXE) main.o reader.o munch1.o munch2.o writer.o queue.o

main.o: main.c main.h
	$(CC) $(WARNING_FLAGS) -c main.c

reader.o: reader.c threads.h
	$(CC) $(WARNING_FLAGS) -c reader.c

munch1.o: munch1.c threads.h
	$(CC) $(WARNING_FLAGS) -c munch1.c

munch2.o: munch2.c threads.h
	$(CC) $(WARNING_FLAGS) -c munch2.c

writer.o: writer.c threads.h
	$(CC) $(WARNING_FLAGS) -c writer.c

queue.o: queue.c threads.h
	$(CC) $(WARNING_FLAGS) -c queue.c

clean:
	rm -f $(EXE) *.o
	rm -rf $(SCAN_BUILD_DIR)

scan-build: clean
	scan-build-dir -o $(SCAN_BUILD_DIR) make
