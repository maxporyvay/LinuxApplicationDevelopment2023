GENERATES = *~ lab0 lab1 lab2 lab3 lab0.c lab1.c lab2.c lab3.c

all:	ptch run

ptch:	lab.c 1.patch 2.patch 3.patch
		cp lab.c lab0.c
		cp lab0.c lab1.c
		patch lab1.c < 1.patch
		cp lab1.c lab2.c
		patch lab2.c < 2.patch
		cp lab2.c lab3.c
		patch lab3.c < 3.patch

run:	lab0 lab1 lab2 lab3
		./lab0 && sleep 1
		./lab1 8 && sleep 1
		./lab2 ' @' 5 && sleep 1
		./lab3 12 '.#' 4 && sleep 1
		./lab3 11 '.#' 4 && sleep 1
		./lab3 12 '.#' 4

lab0: ptch
	cc lab0.c -o lab0

lab1: ptch
	cc lab1.c -o lab1

lab2: ptch
	cc lab2.c -o lab2

lab3: ptch
	cc lab3.c -o lab3

clean:
		rm -f $(GENERATES)
