#include <stdio.h>
#include <stdlib.h>

#include "rb_tree.h"
#include "rb_file_io.h"

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Incorrect argument(s)\nCorrect arguments: HW2 <input_file> <output_file>\n");
		return -1;
	}

	FILE *input = fopen(*(argv + 1),"r");
	if(input == NULL)
	{
		printf("File IO error\nPlease check that input file exists\n");
		return -1;
	}

	printf("Building tree from file: %s\n", *(argv + 1));
	RBTreeNode *root = buildTreeFromFile(input);

	fclose(input);

	if(root == NULL)
	{
		printf("Could not build tree\n");
		return -1;
	}

	printf("Writing tree to file: %s\n", *(argv + 2));
	FILE *output = fopen(*(argv + 2), "w");
	if(output == NULL)
	{
		printf("File IO error\n");
		freeTree(root);
		return -1;
	}

	outputTreeToFile(root, output);

	fclose(output);

	freeTree(root);

	return 0;
}