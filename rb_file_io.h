#define INPUT_BUFFER_SIZE 50

typedef struct rb_print_queue_node
{
	RBTreeNode *treeNode;
	struct rb_print_queue_node *next;
	struct rb_print_queue_node *prev;
}RBPrintQueueNode;

typedef struct rb_print_queue
{
	struct rb_print_queue_node *head;
	struct rb_print_queue_node *tail;
}RBPrintQueue;

RBTreeNode* buildTreeFromFile(FILE *input);
void outputTreeToFile(RBTreeNode *root, FILE *output);
int printQueueIsEmpty(RBPrintQueue *queue);
void printEnqueue(RBPrintQueue *queue, RBPrintQueueNode *node);
RBTreeNode* printDequeue(RBPrintQueue *queue);
void freeQueue(RBPrintQueue *queue);