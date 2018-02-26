
all:	main

CC = gcc

INCLUDE = .

INSTDIR	= /home/wangbo/MY/socket/out  

main:	client.o recvClient.o sendClient.o
	$(CC) -o main client.o recvClient.o sendClient.o -lpthread

client.o:	client.c recvClient.h sendClient.h
	$(CC) -I$(INCLUDE) -c  client.c 

recvClient.o:	recvClient.c recvClient.h
	$(CC) -I$(INCLUDE) -c recvClient.c

sendClient.o:	sendClient.c sendClient.h
	$(CC) -I$(INCLUDE) -c sendClient.c

clean:
	-rm main client.o recvClient.o sendClient.o

install:	main
