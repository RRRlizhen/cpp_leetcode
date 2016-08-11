all: myapp

CC = gcc

INCLUDE = .

INSTDIR = /home/lizhen/basic/bin

CFLAGS = -g -Wall -ansi

#Local libraries
MYLIB = mylib.a

myapp: main.o $(MYLIB)
	$(CC) -o myapp main.o $(MYLIB)

$(MYLIB): $(MYLIB)(2.o) $(MYLIB)(3.o)

.SUFFIXES: .cpp
.cpp.o:
	$(CC) -xc++ $(CFLAGS) -I(INCLUDE) -c $<
clean:
	-rm main.o 2.o 3.o myapp $(MYLIB)
install:myapp
	@if [ -d $(INSTDIR) ];  \
	then \
		cp myapp $(INSTDIR); \
		chmod a+x $(INSTDIR)/myapp; \
		chmod og-w $(INSTDIR)/myapp; \
		echo "installed in $(INSTDIR)"; \
	else \
		echo "sorry, $(INSTDIR) does not exist"; \
	fi

