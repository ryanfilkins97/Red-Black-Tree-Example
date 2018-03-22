HW2: prog_assign_2.o rb_tree.o rb_file_io.o input_gen
	gcc -g prog_assign_2.o rb_tree.o rb_file_io.o -o HW2
input_gen: input_generator.c
	gcc -g input_generator.c -o input_gen
prog_assign_2.o: prog_assign_2.c rb_tree.h rb_file_io.h
	gcc -g -c prog_assign_2.c
rb_tree.o: rb_tree.c rb_tree.h
	gcc -g -c rb_tree.c
rb_file_io.o: rb_file_io.c rb_file_io.h rb_tree.h
	gcc -g -c rb_file_io.c
clean: 
	rm *.o HW2 input_gen