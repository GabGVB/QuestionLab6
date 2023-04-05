#include "arbori.h"



Node* createNode(char type, int num)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->num = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* createTree(Node *root)
{
    root = createNode('Q',1);
    root->left = createNode('Q',2);
    root->right = createNode('Q',3);
    root->left->left = createNode('Q',4);
    root->left->right = createNode('Q',5);
    root->right->left = createNode('Q',6);
    root->right->right = createNode('C',2);
    root->left->left->left = createNode('Q',7);
    root->left->left->right = createNode('Q',8);
    root->left->right->left = createNode('Q',9);
    root->left->right->right = createNode('C',3);
    root->right->left->left = createNode('C',4);
    root->right->left->right = createNode('Q',10);
    root->left->left->left->left = createNode('C',1);
    root->left->left->left->right = createNode('C',2);
    root->left->left->right->left = createNode('C',2);
    root->left->left->right->right = createNode('C',4);
    root->left->right->left->left = createNode('C',2);
    root->left->right->left->right = createNode('C',1);
    root->right->left->right->left = createNode('C',1);
    root->right->left->right->right = createNode('C',4);

    return root;
}
void preorder ( Node * root )
{
    if ( root )
    {
        printf ("%c%d",root ->type,root->num );
        preorder (root -> left );
        preorder (root -> right );
    }
}
void AfisPath (char *v, int n)
{
    for (int i=0; i<n; i++)
        printf("%c ",v[i]);
    printf("\n");
}

void FindPath(Node *root,char *v,char c,int n)
{
    if (c!='0')
        v[n]=c;

    if (root->type=='C')
    {
        printf ("C%d: ",root->num);
        AfisPath(v,n+1);
    }
    else
    {
        FindPath(root->left,v,'d',n+1);
        FindPath(root->right,v,'n',n+1);
    }
}

