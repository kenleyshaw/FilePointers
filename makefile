make:
	gcc -Wall driver.c functions.c -o PA2

run:
	./PA2 input.txt output.txt

clean:
	rm -f *.o PA2


