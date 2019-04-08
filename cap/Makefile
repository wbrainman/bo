
all:	install

CC = gcc

INCLUDE = .

INSTDIR	= $(PWD)/  

main:	main.c cap.c cap.h setEther.c setEther.h
	$(CC) -o main main.c cap.c cap.h setEther.c setEther.h -lcap 

test:	test.c cap.c cap.h setEther.c setEther.h
	$(CC) -o test test.c  cap.c cap.h setEther.c setEther.h -lcap 


clean:

install:	main	test
	
