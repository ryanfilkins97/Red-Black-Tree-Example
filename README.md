## Overview

This is a small C program that will read integers from a text input file and create a red-black tree. It will then output the contents of the tree and the color of each node to an output file. It was created as a project for CS3050.

## Contents

**prog_assign_2.c** - Main program file

**rb_tree.c/rb_tree.h** - Contains functions for red-black tree operations

**rb_file_io.c/rb_file_io.h** - Contains functions for building and outputting red-black trees

**input_generator.c** - A separate program that can generate various sizes of input files for testing purposes

## Usage

Both the main program and the input generator can be compiled using 'make'. 'make clean' can be used to remove all object files and executables, leaving only source code.

### Main Program

```
$ ./HW2 <input_file> <output_file>
```

**Note:** Input file should be a newline separated list of integers

### Input Generator

```
$ ./input_gen <size_flag> <optional: bad_input_flag>
```

**Size flag options:** -s (25 integers), -m (1000 integers), -l (10000000 integers)

**Note:** Adding the bad input flag, -b, will generate invalid input for testing
