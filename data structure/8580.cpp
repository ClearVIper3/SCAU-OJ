#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int
#include <iostream>
using namespace std;

typedef int Status;
typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;


Status ListInsert_L(LinkList &L, int i, ElemType e) {  // 算法2.9
  // 在带头结点的单链线性表L的第i个元素之前插入元素e
  LinkList p,s;
  p = L;
  int j = 0;
  while (p && j < i-1) {  // 寻找第i-1个结点
    p = p->next;
    ++j;
  }
  if (!p || j > i-1) return ERROR;      // i小于1或者大于表长
  s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
  s->data = e;  s->next = p->next;      // 插入L中
  p->next = s;
  return OK;
} // LinstInsert_L

Status list(LinkList &L,int n)
{
  for(int i = 1; i <= n; i++)
  {
    int val;
    cin >> val;
    ListInsert_L(L, i, val);
  }
  return OK;
}

Status sort(LinkList &L)
{
  LNode *ptr = L->next;
  while (ptr->next != NULL)
  {
    LNode *p = ptr;
    while (p != NULL)
    {
        if(ptr->data > p->data)
        {
            int tmp = ptr->data;
            ptr->data = p->data;
            p->data = tmp;
        }
        p = p->next;
    }
    ptr = ptr->next;
  }
  return OK;
}

Status link(LinkList &L,LinkList &l)
{
  LNode * ptr = L->next;
  while(ptr->next != NULL)
  {
      ptr=ptr->next;
  }
  ptr->next = l->next;

  return OK;
}

Status print(LinkList &L,int length)
{
    LNode *ptr = L->next;
    for(int i = 0; i < length; i++)
    {
      printf("%d ",ptr->data);
      ptr = ptr->next;
    }
    printf("\n");

    return OK;
}

int main()
{
    int m,n;
    LNode *A = new LNode;
    LNode *B = new LNode;

    cin >> m;
    list(A,m);
    sort(A);
    cin >> n;
    list(B,n);
    sort(B);

    printf("List A:");
    print(A,m);

    printf("List B:");
    print(B,n);

    link(A,B);
    sort(A);
    int l=n+m;
    printf("List C:");
    print(A,l);


    return 0;
}
