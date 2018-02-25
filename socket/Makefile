


all:	main

CC = gcc

INCLUDE = .

main:	client.o recvClient.o sendClient.o
	$(CC) -o main client.o recvClient.o sendClient.o

client.o:	client.c recvClient.h sendClient.h
	$(CC) -I$(INCLUDE) -c client.c

recvClient.o:	recvClient.c recvClient.h
	$(CC) -I$(INCLUDE) -c recvClient.c

sendClient.o:	sendClient.c sendClient.h
	$(CC) -I$(INCLUDE) -c sendClient.c

clean:
	-rm client.o recvClient.o sendClient.o
