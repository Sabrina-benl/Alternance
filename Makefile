CC= gcc
OPTIONS=-W -Wall -std=c89 -pedantic -O2                                         
EXEC_FILES= calendrier

all : $(EXEC_FILES)
calendrier : calendrier.c tests.o
	$(CC) $(OPTIONS) $^ -o $@

tests.o : tests.c
	$(CC) $(OPTIONS) -c tests.c

clean:
	rm -rf $(EXEC_FILES) *.o
