#Sample makefile

SRC1 = code7_1001825785.c
SRC2 = FileLib.c
SRC3 = ListLib.c
SRC4 = MovieTheater.c
SRC5 = StackLib.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
OBJ4 = $(SRC4:.c=.o)
OBJ5 = $(SRC5:.c=.o)
EXE = $(SRC1:.c=.e)

CFLAGS = -g

all : $(EXE)
 
$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)
	gcc $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) -o $(EXE) 

$(OBJ1) : $(SRC1)
	gcc -c $(CFLAGS) $(SRC1) -o $(OBJ1)
$(OBJ2) : $(SRC2)
	gcc -c $(CFLAGS) $(SRC2) -o $(OBJ2)	
$(OBJ3) : $(SRC3)
	gcc -c $(CFLAGS) $(SRC3) -o $(OBJ3)	
$(OBJ4) : $(SRC4)
	gcc -c $(CFLAGS) $(SRC4) -o $(OBJ4)	
$(OBJ5) : $(SRC5)
	gcc -c $(CFLAGS) $(SRC5) -o $(OBJ5)	
