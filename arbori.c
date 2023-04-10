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


void SaveIn (char *v,int lenPath, int AnswerType, Answers **C,int *nrAns)
{
    int i=0,j;
    while (i<*nrAns && (*C)[i].Type!=AnswerType)
        i++;
    if (i==*nrAns)
    {
        (*nrAns)++;
        *C=(Answers*)realloc(*C,*nrAns*sizeof(Answers));
        (*C)[i].caiTo=(PathsForEach*)malloc(sizeof(PathsForEach));
        (*C)[i].Type=AnswerType;
        (*C)[i].nrCai=0;
    }
    else
        (*C)[i].caiTo=(PathsForEach*)realloc((*C)[i].caiTo,((*C)[i].nrCai+1)*sizeof(PathsForEach));

    (*C)[i].caiTo[(*C)[i].nrCai].path=(char*)malloc(lenPath*sizeof(char));
    (*C)[i].caiTo[(*C)[i].nrCai].lenPath=lenPath;

    for (j=0; j<lenPath; j++)
        (*C)[i].caiTo[(*C)[i].nrCai].path[j]=v[j];
    (*C)[i].nrCai++;
}
void FindPathFor(Node *root,char *v, char c,int n, Answers **C,int *nrAns)
{

    if (c!='0')
        v[n]=c;

    if (root->type=='C')
        SaveIn(v,n+1,root->num,C,nrAns);
    else
    {
        FindPathFor(root->left,v,'d',n+1,C,nrAns);
        FindPathFor(root->right,v,'n',n+1,C,nrAns);
    }
}
void AfisForEach (Answers *C,int *nrAns)
{
    int i,j,k;
    for (i=0; i<nrAns; i++)
    {

        printf ("C%d: %d ",C[i].Type,C[i].nrCai);
        (C[i].nrCai==1)?(printf ("cale\n")):(printf("cai\n"));

        for (j=0; j<C[i].nrCai; j++)
        {
            for (k=0; k<C[i].caiTo[j].lenPath; k++)
                printf("%c ",C[i].caiTo[j].path[k]);
            printf("\n");
        }

    }
}
