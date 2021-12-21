CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB= my_string.h my_string.o
FLAGS= -g -Wall


all:my_string_lib.so  stringProg
#programs.exe
stringProg:$(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) ./my_string_lib.so -lm


#libs
my_string_lib.so:$(OBJECTS_LIB)
	$(CC) -shared -o my_string_lib.so $(OBJECTS_LIB)

#simple objects
main.o: main.c my_string_lib.so 
	$(CC) $(FLAGS) -c main.c
my_string.o: my_string.c my_string.h 
	$(CC) $(FLAGS) -c my_string.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg