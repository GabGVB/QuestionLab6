#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct N
{
    char type;
    int num;
    struct N *left, *right;
};

typedef struct
{
    int lenPath;
    char *path;
} PathsForEach;

typedef struct
{
    int nrCai;
    int Type;
    PathsForEach *caiTo;
} Answers;

typedef struct N Node;

Node* createNode(char type, int num);

Node* createTree(Node *root);

void preorder ( Node * root );

void AfisPath (char *v, int n);

void FindPath(Node *root,char *v,char c,int n);

void SaveIn (char *v,int lenPath, int AnswerType, Answers **C,int *nrAns);

void FindPathFor(Node *root,char *v, char c,int n, Answers **C,int *nrAns);

void AfisForEach(C,nrAns);
