all:	install

CC = g++

INCLUDE = .

INSTDIR	= $(PWD)/out  

#main:	main.cpp 10_10_3.h 10_10_3.cpp
#main:	main.cpp 10_10_4.h 10_10_4.cpp
#main:	main.cpp 10_10_5.h 10_10_5.cpp
#main:	main.cpp 10_10_6.h 10_10_6.cpp
main:	main.cpp 10_10_7.h 10_10_7.cpp
	$(CC) -o main main.cpp 10_10_7.cpp 

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
	
