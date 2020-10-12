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
	./prog
	./prog test1
	./prog test2-arg1 test2-arg2 test2-arg3
	./prog-a
	./prog-a test1
	./prog-a test2-arg1 test2-arg2 test2-arg3
	LD_LIBRARY_PATH=. ./prog-so
	LD_LIBRARY_PATH=. ./prog-so test1
	LD_LIBRARY_PATH=. ./prog-so test2-arg1 test2-arg2 test2-arg3

fun.o:  outlib.h

clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)
