
all:	install

CC = g++

INCLUDE = .

INSTDIR	= $(PWD)/out  

main:	main.cpp 12_02.h 12_02.cpp
	$(CC) -g -o main main.cpp 12_02.cpp 

#main.o:	main.cpp 10_10_3.h
#	$(CC) -I$(INCLUDE) -c  main.cpp 
#
#cpp.o:	10_10_3.cpp 10_10_3.h
#	$(CC) -I$(INCLUDE) -c 10_10_3.cpp

clean:
	@ -rm $(INSTDIR) -r

install:	main
	@if [ -d $(INSTDIR) ]; then \
		echo "$(INSTDIR)exist"; \
	else \
		echo "$(INSTDIR)created"; \
		mkdir $(INSTDIR); \
	fi 
	@	mv main $(INSTDIR); \
		echo "install target to $(INSTDIR)"; \
	
