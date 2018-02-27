
all:	client

CC = gcc

INCLUDE = .

INSTDIR	= /home/wangbo/MY/socket/out  

client:	client.o recvClient.o sendClient.o
	$(CC) -o client client.o recvClient.o sendClient.o -lpthread

client.o:	client.c recvClient.h sendClient.h
	$(CC) -I$(INCLUDE) -c  client.c 

recvClient.o:	recvClient.c recvClient.h
	$(CC) -I$(INCLUDE) -c recvClient.c

sendClient.o:	sendClient.c sendClient.h
	$(CC) -I$(INCLUDE) -c sendClient.c

clean:
	@ -rm $(INSTDIR) -r

install:	client
	@if [ -d $(INSTDIR) ]; then \
		echo "$(INSTDIR)exit"; \
	else \
		echo "$(INSTDIR)created"; \
		mkdir $(INSTDIR); \
	fi 
	@	cp client $(INSTDIR); \
		cp *.o $(INSTDIR); \
		echo "install target to $(INSTDIR)"; \
	
