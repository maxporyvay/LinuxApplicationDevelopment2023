GENERATES = prog prog-a prog-so README
TRASH = *.o *.so *.a *.txt *~ o.*

CFLAGS = -fPIC

all:	README prog prog-a prog-so test

prog:	const.o fun.o prog.o

prog-a:	liboutput_static.a
		cc -L. prog.o -loutput_static -o prog-a

prog-so:	liboutput.so
		cc -L. prog.o -loutput -o prog-so

README:	prog
		./$< 2> $@

test:	prog prog-a prog-so
		./prog 2> prog_0_output.txt
		./prog-a 2> prog-a_0_output.txt
		LD_LIBRARY_PATH=`pwd` ./prog-so 2> prog-so_0_output.txt
		sed -i 's/\<prog\>//g' prog_0_output.txt
		sed -i 's/\<prog-a\>//g' prog-a_0_output.txt
		sed -i 's/\<prog-so\>//g' prog-so_0_output.txt
		cmp prog_0_output.txt prog-a_0_output.txt > prog_prog-a_0_diff.txt
		cmp prog_0_output.txt prog-so_0_output.txt > prog_prog-so_0_diff.txt
		cmp prog-a_0_output.txt prog-so_0_output.txt > prog-a_prog-so_0_diff.txt

		./prog qwerty > prog_1_output.txt
		./prog-a qwerty > prog-a_1_output.txt
		LD_LIBRARY_PATH=`pwd` ./prog-so qwerty > prog-so_1_output.txt
		cmp prog_1_output.txt prog-a_1_output.txt > prog_prog-a_1_diff.txt
		cmp prog_1_output.txt prog-so_1_output.txt > prog_prog-so_1_diff.txt
		cmp prog-a_1_output.txt prog-so_1_output.txt > prog-a_prog-so_1_diff.txt

		./prog qw er ty > prog_3_output.txt
		./prog-a qw er ty > prog-a_3_output.txt
		LD_LIBRARY_PATH=`pwd` ./prog-so qw er ty > prog-so_3_output.txt
		cmp prog_3_output.txt prog-a_3_output.txt > prog_prog-a_3_diff.txt
		cmp prog_3_output.txt prog-so_3_output.txt > prog_prog-so_3_diff.txt
		cmp prog-a_3_output.txt prog-so_3_output.txt > prog-a_prog-so_3_diff.txt

liboutput_static.a:
		ar -rcs liboutput_static.a const.o fun.o

liboutput.so:
		cc -shared fun.o const.o -o liboutput.so

fun.o:	outlib.h

clean:
		rm -f $(TRASH)

distclean:		clean
		rm -rf $(GENERATES)