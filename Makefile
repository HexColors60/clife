     all: src/main.c
	gcc -g -o bin/clife src/main.c

     clean:
	rm bin/clife

     halfclean:
	rm -r arch/svf/*.rtf

     cheat:
	echo -n "[w];[t];" > arch/svf/inv.rtf

     help:
	cat Makefile
