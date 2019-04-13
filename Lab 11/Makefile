run: exe 
	./exe input.txt

exe: dns.o driver.o
	gcc -o exe dns.o driver.o

driver.o: dns.h driver.c
	gcc -C driver.c

dns.o: dns.h dns.c
	gcc -C dns.c

debug:
	gdb --tui ./exe