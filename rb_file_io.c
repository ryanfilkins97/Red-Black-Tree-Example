#include <stdio.h>
#include <stdlib.h>

#include "rb_tree.h"
#include "rb_file_io.h"

RBTreeNode* buildTreeFromFile(FILE *input)
{
	long sizeOfTree = 0;

	RBTreeNode *root = NULL;

	char *temp = malloc(sizeof(char) * INPUT_BUFFER_SIZE);
	if(temp == NULL)
	{
		printf("Memory allocation error when reading from file\n");
		return NULL;
	}

	int keyToInsert = 0;

	while(!feof(input))
	{
		if(fgets(temp, INPUT_BUFFER_SIZE, input) != NULL)
		{
			if((keyToInsert = atoi(temp)) == 0)
			{
				printf("Bad character in input\n");
				free(temp);
				freeTree(root);
				return NULL;
			}
			else
			{
				insertKeyIntoRBTree(&root, keyToInsert);
				sizeOfTree++;
			}
		}
	}

	free(temp);

	printf("Built tree with %ld nodes\n", sizeOfTree);
	return root;
}

void outputTreeToFile(RBTreeNode *root, FILE *output)
{
	RBPrintQueue *queue = malloc(sizeof(RBPrintQueue));
	if(queue == NULL)
	{
		printf("Memory allocation error\nCould not output tree\n");
		return;
	}
	queue->head = NULL;
	queue->tail = NULL;

	if(root != NULL)
	{
		RBPrintQueueNode *newNode = malloc(sizeof(RBPrintQueueNode));
		if(newNode == NULL)
		{
			printf("Memory allocation error\nCould not output tree\n");
			free(queue);
			return;
		}
		newNode->treeNode = root;
		newNode->next = NULL;
		newNode->prev = NULL;
		printEnqueue(queue, newNode);
	}

	RBTreeNode *current = root;

	while(printQueueIsEmpty(queue) == 0)
	{
		current = printDequeue(queue);
		if(current->left != NULL)
		{
			RBPrintQueueNode *newNode = malloc(sizeof(RBPrintQueueNode));
			if(newNode == NULL)
			{
				printf("Memory allocation error\nCould not output tree\n");
				freeQueue(queue);
				return;
			}
			newNode->treeNode = current->left;
			newNode->next = NULL;
			newNode->prev = NULL;
			printEnqueue(queue, newNode);
		}
		if(current->right != NULL)
		{
			RBPrintQueueNode *newNode = malloc(sizeof(RBPrintQueueNode));
			if(newNode == NULL)
			{
				printf("Memory allocation error\nCould not output tree\n");
				freeQueue(queue);
				return;
			}
			newNode->treeNode = current->right;
			newNode->next = NULL;
			newNode->prev = NULL;
			printEnqueue(queue, newNode);
		}

		fprintf(output, "%d-", current->key);
		if(current->color == BLACK)
		{
			fprintf(output, "B; ");
		}
		else
		{
			fprintf(output, "R; ");
		}
	}
	
	free(queue);
}

int printQueueIsEmpty(RBPrintQueue *queue)
{
	if(queue->head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void printEnqueue(RBPrintQueue *queue, RBPrintQueueNode *node)
{
	if(printQueueIsEmpty(queue) == 1)
	{
		queue->head = node;
		queue->tail = node;
	}
	else
	{
		node->next = queue->head;
		queue->head->prev = node;
		queue->head = node;
	}
}

RBTreeNode* printDequeue(RBPrintQueue *queue)
{
	RBPrintQueueNode *temp = NULL;

	if(printQueueIsEmpty(queue) == 1)
	{
		temp = NULL;
	}
	else if(queue->head == queue->tail)
	{
		temp = queue->head;
		queue->head = NULL;
		queue->tail = NULL;
	}
	else
	{
		temp = queue->tail;
		queue->tail = temp->prev;
		queue->tail->next = NULL;
	}

	RBTreeNode *node = temp->treeNode;

	free(temp);

	return node;
}

void freeQueue(RBPrintQueue *queue)
{
	RBPrintQueueNode *current = queue->head;
	RBPrintQueueNode *temp = NULL;

	while(current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	free(queue);
}