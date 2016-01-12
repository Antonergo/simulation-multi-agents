OPT = -g -Wall -Wextra -ansi -pedantic -O2
LIB = -lm
CC  = g++

OBJ = main.o Controler.o Carre.o Antity.o Farmer.o Fighter.o

exe:$(OBJ)
	$(CC) -o $@ $(OBJ) $(OPT)

.cpp.o:
	$(CC) -c $(OPT) -c $< -o $@


dependencies: 
	$(CC) -MM *.cpp > makefile.dep

clean :
	rm -f $(OBJ) core




include makefile.dep

# Utilisation des dépendances:
#
# 1) touch makefile.dep
# 2) make dependencies
# 3) make
