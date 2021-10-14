#include<stdio.h>
#include "stdlib.h"
#include "string.h"
//二叉树的二叉链表结构
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;//左右孩子指针
}BiTNode,*BiTree;
char pre_string[30];
char in_string[30];
BiTree  restoreTree(char pre[], char in[], int n)
{
    int i;
    char lpre[60],rpre[60];
    char lin[60],rin[60];
    int n1,n2;
    n1=n2=0;
    int m1=0,m2=0;
    if(n==0){
        return NULL;
    }
    BiTree T=(BiTree)malloc(sizeof(struct BiTNode));
    T->data=pre[0];
    for(i=0;i<n;i++){
        if(i<=n1&&in[i]!=pre[0]){
            lin[n1++]=in[i];
        }
        else if(in[i]!=pre[0]){
            rin[n2++]=in[i];
        }
    }
    for(i=1;i<n;i++){
        if(i<n1+1){
            lpre[m1++]=pre[i];
        }
        else{
            rpre[m2++]=pre[i];
        }
    }
    T->lchild=restoreTree(lpre,lin,n1);
    T->rchild=restoreTree(rpre,rin,n2);
    return T;
}
int main()
{
    BiTree T;
    T=NULL;
    printf("please input The result of the traversal in order:");
    gets(pre_string);
    printf("please input The result of the traversal in preorder:");
    gets(in_string);
    int n=strlen(in_string);
    T=restoreTree(pre_string,in_string,n);
    return 0;
    system ("pause");
}

