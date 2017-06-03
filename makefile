### Makefile ###

all: prog clean #run rmpoper

prog: main.o ST.o item.o
	gcc -Wall -o prog main.o ST.o item.o -lm

st.o: ST.c
	gcc -c ST.c

item.o: item.c
	gcc -c item.c

main.o: main.c
	gcc -c main.c

clean:
	rm -rf  *.o

rmpoper: clean
	rm -rf prog

run: prog clean
	./prog -n11 #<in3.txt #>out.txt
