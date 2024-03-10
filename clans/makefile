GCC = gcc -g

edit : test_clans.o clans.o personne.o
	$(GCC) -o $@ test_clans.o clans.o personne.o



test_clans.o : test_clans.c clans.h personne.h

clans.o : clans.c clans.h

personne.o : personne.c personne.h


%.o : 
	$(GCC) -c $< -Iinclude
	
clean : 
	rm edit *.o clans
