hanoi : hanoi.c list.c stack.c
	gcc -Wall -std=c11 hanoi.c list.c stack.c -o hanoi 

.PHONY : clean
clean :
	rm -rf hanoi *.o *.core