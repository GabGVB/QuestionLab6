#include "arbori.h"

typedef struct
{
    int lenPath;
    char path[10];
} PathsForEach;

struct Answers
{
    int nrCai;
    PathsForEach caiTo[5];
} C[5];

void SaveIn (char *v,int lenPath, int AnswerType)
{
    C[AnswerType].nrCai++;
    C[AnswerType].caiTo[C[AnswerType].nrCai].lenPath=lenPath;
    for(int i=0; i<lenPath; i++)
        C[AnswerType].caiTo[C[AnswerType].nrCai].path[i]=v[i];
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
    for (i=1; i<=4; i++)
    {

        printf ("C%d: %d ",i,C[i].nrCai);
        (C[i].nrCai==1)?(printf ("cale\n")):(printf("cai\n"));
        for (j=1; j<=C[i].nrCai; j++)
        {
            for (k=0; k<=C[i].caiTo[j].lenPath; k++)
                printf("%c ",C[i].caiTo[j].path[k]);
            printf("\n");
        }

    }
    return 0;
}
