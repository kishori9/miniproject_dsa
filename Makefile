all: project text.txt
project : string1.o test.o 
	   cc string1.o test.o -o project
string1.o : string1.c string1.h
	   cc -c string1.c
test.o : string1.c string1.h test.c
	   cc -c test.c
clean : 
	   rm *.o
