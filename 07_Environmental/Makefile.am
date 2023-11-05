AM_CFLAGS = -O0 -g

bin_PROGRAMS=rhasher

rhasher_SOURCES=rhasher.c

test:
	cat Makefile | sha1sum | cut -d ' ' -f 1 > pattern1.log
	echo 'SHA1 Makefile' | ./rhasher | grep -f pattern1.log

	cat Makefile | md5sum | cut -d ' ' -f 1 > pattern2.log
	echo 'MD5 Makefile' | ./rhasher | grep -f pattern2.log

distclean:
	rm -rf .deps *.cache *.log config.* config.* configure configure~ rhasher *.o *.m4 install-sh Makefile Makefile.in missing stamp-h1 compile depcomp test-driver *.log src/.deps src/.dirstamp src/rhasher.o