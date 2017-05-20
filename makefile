### Makefile ###

all: prog clean run rmpoper

prog: main.o st.o item.o
	gcc -Wall -o prog main.o st.o item.o -lm

st.o: st.c
	gcc -c st.c

item.o: item.c
	gcc -c item.c

main.o: main.c
	gcc -c main.c

clean:
	rm -rf  *.o

rmpoper: clean
	rm -rf prog

run: prog clean
	./prog #<in.txt #>out.txt
