#____________________________________________________________________________________
# VARIABLES
#
# SOURCE CODE FILE NAME
BASE_NAME_0    = sorting_algorithms
#
# EXECUTABLES
EXECUTABLE 		= sandbox
EXECUTABLE_GCOV = sandbox_gcov
#
# SOURCE FILENAMES
TEST_C 		 = $(EXECUTABLE).c
SRC_C  		 = $(BASE_NAME_0).c
SRC_H 		 = $(BASE_NAME_0).h
#
# SYSTEM
SHELL  = /bin/bash
CC	   = gcc
CFLAGS = -std=c99 -pedantic -Wvla -Wall -Wshadow -O3
CFLAGS_GCOV = $(CFLAGS) -fprofile-arcs -ftest-coverage

#____________________________________________________________________________________
# RULES
#
$(EXECUTABLE): $(SRC_C) $(TEST_C) $(SRC_H)
	$(CC) $(SRC_C) $(TEST_C) $(FLAGS) -o $(EXECUTABLE) 

test: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(EXECUTABLE_GCOV) *.c.gcov *.gcda *.gcno *.b *.txt

coverage: $(SRC_C) $(TEST_C)
	$(CC) $(SRC_C) $(TEST_C) $(CFLAGS_GCOV) -o $(EXECUTABLE_GCOV)
	./$(EXECUTABLE_GCOV)
	gcov -f $(SRC_C)

.PHONY: test clean pretest submit coverage

#vim: set noexpandtab tabstop=4 filetype=make: