GENERATES = prog prog-a prog-so test
TRASH = *.o *~ o.* *.a *.so


all:    prog prog-a prog-so test

prog:   const.o fun.o prog.o

prog-a:  prog.o liboutput_static.a
	cc -L. prog.o -loutput_static -o prog-a
	
prog-so: prog.o liboutput.so
	cc -L. prog.o -loutput -o prog-so

liboutput_static.a:   fun.o const.o
	ar -rcs liboutput_static.a const.o fun.o

liboutput.so:   fun.o const.o
	cc -shared fun.o const.o -o liboutput.so

test: prog prog-a prog-so
	./prog 2>>errorfile >prog-test0
	./prog test1 2>>errorfile >prog-test1
	./prog test2-arg1 test2-arg2 test2-arg3 2>>errorfile >prog-test2
	./prog-a 2>>errorfile >prog-a-test0
	./prog-a test1 2>>errorfile >prog-a-test1
	./prog-a test2-arg1 test2-arg2 test2-arg3 2>>errorfile >prog-a-test2
	LD_LIBRARY_PATH=. ./prog-so 2>>errorfile >prog-so-test0
	LD_LIBRARY_PATH=. ./prog-so test1 2>>errorfile >prog-so-test1
	LD_LIBRARY_PATH=. ./prog-so test2-arg1 test2-arg2 test2-arg3  2>>errorfile >prog-so-test2
	cmp prog-test0 prog-a-test0
	cmp prog-test0 prog-so-test0
	cmp prog-so-test0 prog-a-test0
	cmp prog-test1 prog-a-test1
	cmp prog-test1 prog-so-test1
	cmp prog-so-test1 prog-a-test1
	cmp prog-test2 prog-a-test2
	cmp prog-test2 prog-so-test2
	cmp prog-so-test2 prog-a-test2
	

fun.o:  outlib.h

clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES) *test*
