typedef enum RBColor
{
	RED,
	BLACK
}RBColor;

typedef struct RB_node
{
	int key;
	struct RB_node *parent;
	struct RB_node *left;
	struct RB_node *right;
	RBColor color;
}RBTreeNode;

void insertKeyIntoRBTree(RBTreeNode **root, int key);
void freeTree(RBTreeNode *root);
void rightRotate(RBTreeNode **root, RBTreeNode *x);
void leftRotate(RBTreeNode **root, RBTreeNode *x);
void RBFixup(RBTreeNode **root, RBTreeNode *node);