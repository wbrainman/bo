
all:	install

CC = gcc

INCLUDE = .

INSTDIR	= $(PWD)/out  

client:	client.o recvClient.o sendClient.o
	$(CC) -o client client.o recvClient.o sendClient.o -lpthread

client.o:	client.c recvClient.h sendClient.h
	$(CC) -I$(INCLUDE) -c  client.c 

recvClient.o:	recvClient.c recvClient.h
	$(CC) -I$(INCLUDE) -c recvClient.c

sendClient.o:	sendClient.c sendClient.h
	$(CC) -I$(INCLUDE) -c sendClient.c



server:	server.o serverRecv.o serverSend.o
	$(CC) -o server server.o serverRecv.o serverSend.o -lpthread

server.o:	server.c serverRecv.h serverSend.h
	$(CC) -I$(INCLUDE) -c server.c
	
serverRecv.o:	serverRecv.c serverRecv.h
	$(CC) -I$(INCLUDE) -c serverRecv.c
	
serverSend.o:	serverSend.c serverSend.h
	$(CC) -I$(INCLUDE) -c serverSend.c

clean:
	@ -rm $(INSTDIR) -r

install:	client server
	@if [ -d $(INSTDIR) ]; then \
		echo "$(INSTDIR)exist"; \
	else \
		echo "$(INSTDIR)created"; \
		mkdir $(INSTDIR); \
	fi 
	@	mv client $(INSTDIR); \
		mv server $(INSTDIR); \
		mv *.o $(INSTDIR); \
		echo "install target to $(INSTDIR)"; \
	
