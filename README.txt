README:
This program directory includes a makefile and can be compiled using the 'make' command. 'make clean' can be used to remove all object files and executables, leaving only source code.

CONTENTS:
prog_assign_2.c : main program file

rb_tree.c/rb_tree.h : contains functions for red-black tree operations

rb_file_io.c/rb_file_io.h : contains functions for building and outputting red-black trees

input_generator.c : a separate program that can generate various sizes of input files for testing purposes

INSTRUCTIONS:
This program takes 2 command line arguments:
<input_file> <output_file>

The input file should be a newline separated list of integers

This directory also contains a utility program, input_gen.
This program takes 1 or 2 command line arguments:
<size> <optional: bad input flag>

The following sizes are supported:
'-s' : small (25 integers)
'-m' : medium (1000 integers)
'-l' : large (10000000 integers)

The bad input flag '-b' will generate an error filled input file for testing purposes
