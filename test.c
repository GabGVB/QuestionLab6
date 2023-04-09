#include "arbori.h"

typedef struct
{
    int lenPath;
    char *path;
} PathsForEach;

struct Answers
{
    int nrCai;
    int Type;
    PathsForEach caiTo[5];
} C[5];
int nrAns;
void SaveIn (char *v,int lenPath, int AnswerType)
{
    int i=0,j;
    while (i<nrAns && C[i].Type!=AnswerType)
        i++;
    if (i==nrAns)
    {
        nrAns++;
        C[i].Type=AnswerType;
    }
    C[i].caiTo[C[i].nrCai].path=(char*)malloc(lenPath*sizeof(char));
    C[i].caiTo[C[i].nrCai].lenPath=lenPath;

    for (j=0; j<lenPath; j++)
        C[i].caiTo[C[i].nrCai].path[j]=v[j];
        C[i].nrCai++;
}
void FindPathFor(Node *root,char *v, char c,int n)
{

    if (c!='0')
        v[n]=c;

    if (root->type=='C')
    {

        SaveIn(v,n+1,root->num);
    }
    else
    {
        FindPathFor(root->left,v,'d',n+1);
        FindPathFor(root->right,v,'n',n+1);
    }


}
int main()
{
    int i,j,k;
    char v[20];
    Node *root;
    root=createTree(root);
    //FindPath(root,v,'0',0);
    FindPathFor(root,v,'0',0);
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
