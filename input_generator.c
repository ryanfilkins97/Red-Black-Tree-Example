#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
	if(argc != 2 && argc != 3)
	{
		printf("Incorrect argument(s)\n");
		printf("Correct arguments: input_gen <size (-s for small, -m for medium, -l for large)> <optional: -b for bad input>\n");
		return -1;
	}

	long inputSize = 0;
	char *filename = NULL;
	unsigned char badInputFlag = 0;

	if(strcmp(*(argv+1), "-s") == 0)
	{
		inputSize = 25;
		filename = "small_input.txt";
	}
	else if(strcmp(*(argv+1), "-m") == 0)
	{
		inputSize = 1000;
		filename = "medium_input.txt";
	}
	else if(strcmp(*(argv+1), "-l") == 0)
	{
		inputSize = 10000000;
		filename = "large_input.txt";
	}
	else
	{
		printf("Incorrect argument(s)\n");
		printf("Correct arguments: input_gen <size (-s for small, -m for medium, -l for large)> <optional: -b for bad input>\n");
		return -1;
	}

	if(*(argv+2) != NULL)
	{
		if(strcmp(*(argv+2), "-b") == 0)
		{
			badInputFlag = 1;
			filename = "bad_input.txt";
		}
		else
		{
			printf("Incorrect argument(s)\n");
			printf("Correct arguments: input_gen <size (-s for small, -m for medium, -l for large)> <optional: -b for bad input>\n");
			return -1;
		}
	}

	FILE *file = fopen(filename,"w");
	if(file == NULL)
	{
		printf("Unable to write to file\n");
		return -1;
	}

	srand(time(NULL));
	int i = 0;

	if(badInputFlag == 1)
	{
		for(i = 0; i < inputSize; i++)
		{
			fprintf(file, "%c\n", ((rand() % 80) + 40));
		}
	}
	else
	{
		for(i = 0; i < inputSize; i++)
		{
			fprintf(file, "%ld\n", (rand() % inputSize)+ 1);
		}
	}

	printf("Generated file: %s\nContains: %ld inputs\n", filename, inputSize);

	fclose(file);

	return 0;
}