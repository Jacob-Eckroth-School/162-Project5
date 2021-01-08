#Makefile for Linked List
CC = g++ -std=c++11 -g
exe_file = linked_list 
$(exe_file): node.o linked_list.o prog.o
	$(CC) node.o linked_list.o prog.o -o $(exe_file)

%.o: %.cpp
	$(CC) -c $<
clean:
	rm -f *.out *.o $(exe_file)
