# Make sure to make a ./build directory to output the final result into.

build/lib_leaves.a: *.o
	ar rcs build/lib_leaves.a *.o

*.o: src/*.c
	gcc -c src/*.c 

clean:
	rm -f *.o build/lib_leaves.a
