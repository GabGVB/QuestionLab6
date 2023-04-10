#include "arbori.h"

int main()
{
    Node *root;
    root=createTree(root);
    int nrAns=0;
    char v[20];
    Answers *C;
    C=(Answers*)calloc(1,sizeof(Answers));
    //FindPath(root,v,'0',0);
    FindPathFor(root,v,'0',0,&C,&nrAns);
    AfisForEach(C,nrAns);
    return 0;
}
