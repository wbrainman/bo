
all:	install

CC = gcc

INCLUDE = .

INSTDIR	= $(PWD)/  

main:	main.c cap.c cap.h
	$(CC) -o main main.c cap.c cap.h -lcap 

test:	test.c cap.c cap.h
	$(CC) -o test test.c  cap.c cap.h -lcap 


clean:
	@ -rm $(INSTDIR) -r

install:	main	test
	
