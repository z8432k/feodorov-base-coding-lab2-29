CC = g++
PROGRAM = point_area
CFLAGS = -Wall -Wextra -ggdb
LDLIBS = -lm

default: bin/$(PROGRAM)

bin/$(PROGRAM): bin/$(PROGRAM).o bin/point.o
	$(CC) $^ $(LDLIBS) -o $@

bin/point.o: src/point.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

bin/$(PROGRAM).o: src/main.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -fv bin/*.o bin/$(PROGRAM)
