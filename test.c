#include "arbori.h"

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
int nrAns;
void SaveIn (char *v,int lenPath, int AnswerType, Answers **C)
{
    int i=0,j;
    while (i<nrAns && (*C)[i].Type!=AnswerType)
        i++;
    if (i==nrAns)
    {
        nrAns++;
        *C=(Answers*)realloc(*C,nrAns*sizeof(Answers));
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
void FindPathFor(Node *root,char *v, char c,int n, Answers **C)
{

    if (c!='0')
        v[n]=c;

    if (root->type=='C')
    {

        SaveIn(v,n+1,root->num,C);
    }
    else
    {
        FindPathFor(root->left,v,'d',n+1,C);
        FindPathFor(root->right,v,'n',n+1,C);
    }


}
int main()
{
    int i,j,k;
    Answers *C;
    C=(Answers*)calloc(1,sizeof(Answers));
    char v[20];
    Node *root;
    root=createTree(root);
    //FindPath(root,v,'0',0);
    FindPathFor(root,v,'0',0,&C);

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
    return 0;
}
