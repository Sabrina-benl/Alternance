CC = gcc
OPTION = -W -Wall -std=gnu89 -pedantic -O2 -g
all : menu2

menu2 : menu2.o lutin.o ligne.o
	$(CC) $(OPTION) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` menu2.o lutin.o ligne.o `pkg-config --libs-only-l MLV` -o menu2


lutin.o : lutin.c
	$(CC) $(OPTION) -c lutin.c

ligne.o : ligne.c
	$(CC) $(OPTION) -c ligne.c


menu2.o : menu2.c
	$(CC) $(OPTION) -c menu2.c

clean :
	rm -rf *.o *~ menu2
