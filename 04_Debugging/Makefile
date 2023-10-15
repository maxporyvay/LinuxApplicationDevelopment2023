GENERATES = range
TRASH = *.o *.txt *~ o.*

CFLAGS = -O0 -g
LDFLAGS = -g

all:	range test

range:	range.o

test:	range
		gdb -q --batch --command=./range2.gdb --args ./range 1 12 | grep ^@@@ > range2prog.txt
		echo "@@@ 1 12 1 5\n@@@ 1 12 1 10" > range2ans.txt
		diff range2prog.txt range2ans.txt
		gdb -q --batch --command=./range3.gdb --args ./range -100 100 3 | grep ^@@@ > range3prog.txt
		echo "@@@ -100 100 3 -16\n@@@ -100 100 3 -13\n@@@ -100 100 3 -10\n@@@ -100 100 3 -7" > range3ans.txt
		echo "@@@ -100 100 3 -4\n@@@ -100 100 3 -1\n@@@ -100 100 3 2\n@@@ -100 100 3 5" >> range3ans.txt
		diff range3prog.txt range3ans.txt

clean:
		rm -f $(TRASH)

distclean:		clean
		rm -rf $(GENERATES)