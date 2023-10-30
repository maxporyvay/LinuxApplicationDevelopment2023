GENERATES = move
TRASH = *.o *.txt *~ o.* *.so

CFLAGS = -Wall

all:	move test

move:	move.o

test:	move protected_remove.so

		echo -n "AAAAA" > a.txt
		strace -eopenat -e fault=openat:error=EACCES ./move a.txt b.txt 2> test-1.txt || true
		grep "Permission denied" test-1.txt	

		echo -n "BBBBB" > c_PROTECT.txt
		LD_PRELOAD=`pwd`/protected_remove.so ./move c_PROTECT.txt d.txt
		test -f c_PROTECT.txt

		echo -n "CCCCC" > e.txt
		cat e.txt > e2.txt
		./move e.txt f.txt
		diff f.txt e2.txt
		test ! -f e.txt

protected_remove.so:	protected_remove.c
		cc -shared -o protected_remove.so protected_remove.c

clean:
		rm -f $(TRASH)

distclean:		clean
		rm -rf $(GENERATES)