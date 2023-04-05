#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct N
{
    char type;
    int num;
    struct N *left, *right;
};
typedef struct N Node;
Node* createNode(char type, int num);
Node* createTree(Node *root);
void preorder ( Node * root );