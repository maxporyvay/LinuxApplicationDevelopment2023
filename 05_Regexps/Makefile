GENERATES = esub
TRASH = *.o *.txt *~ o.*

all:	esub test

esub:	esub.o

test:	esub
		./esub "[ab]" AB bcdaefgh > test1.txt
		echo bcdaefgh | sed -E "s/[ab]/AB/" | cmp test1.txt
		./esub ahahah not_funny ahah////ahahah > test2.txt
		echo ahah////ahahah | sed -E "s/ahahah/not_funny/" | cmp test2.txt
		./esub "(a)(b)" "@@\2@\1@@" abcd > test3.txt
		echo abcd | sed -E "s/(a)(b)/@@\2@\1@@/" | cmp test3.txt
		./esub "(a)(b)" "@@\2\3@@" abcd > test4.txt || true
		echo "Wrong match number: 3" | cmp test4.txt
		./esub "[ab}" AB bcdaefgh > test5.txt || true
		echo RegComp error: Unmatched [, [^, [:, [., or [= | cmp test5.txt

clean:
		rm -f $(TRASH)

distclean:		clean
		rm -rf $(GENERATES)