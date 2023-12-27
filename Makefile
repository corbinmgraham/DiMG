CC = mpicc
FFLAGS = -O3 -Wall -std=c99
LFLAGS =
OBJECTS = main.o \
		#   other_files.o \

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean :
	rm -f $(OBJECTS) *.exe