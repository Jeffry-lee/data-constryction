#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;
LinkList Createit(LinkList L, int n)
{
    int i;
    LinkList p, r;
    L= (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    r = L;
    printf("input the numbers:");
    for(i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return L;
}
void Displayit(LinkList L)
{
    LinkList p;
    p = L->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int FindElem(LinkList L, int finde)
{
    LinkList p;
    p = L->next;
    while(p)
    {
        if(p->data == finde){
        	printf("Found!\n");
        	break;
        }
        p = p->next;    
    }
    if(!p)
        printf("No found!\n");
    return 0;
}
void Insertit(LinkList L, int locate, int inserte)
{
    LinkList p, N;
    int i = 0;
    p = L;
    while(p && i < locate - 1)
	{
        p = p->next;
        ++i;
    }
    if(!p || i > locate - 1)
        printf("The given position is invalid!\n");
    else{
    	N = (LinkList)malloc(sizeof(LNode));
    	N->data = inserte;
    	N->next = p->next;
   		p->next = N;
    	Displayit(L);
    }
}
void Deleteit(LinkList La, int dele)
{
    LinkList p1, p2;
    p1 = La;
    p2 = La->next;
    while(p2){
        if(p2->data == dele)
		{
            p1->next = p2->next;
        }
        p1 = p2;
        p2 = p2->next;
    }
    Displayit(La);
}
int main()
{
    int n;
    LNode La;
    LinkList L1;
    printf("input the number of LNode:");
    scanf("%d",&n);
 
    L1 = Createit(&La, n);
    Displayit(L1);
 
    FindElem(L1, 30);
    FindElem(L1, 67);
 
    Insertit(L1, 5, 12);
    Insertit(L1, 10, 18);
 
    Displayit(L1);
    Deleteit(L1, 10);
    return 0;
}
