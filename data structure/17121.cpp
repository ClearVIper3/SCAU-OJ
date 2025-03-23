#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;

typedef char  ElemType;
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T) {  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T -> data = ch - 'A'; // 生成根结点
    CreateBiTree(T -> lchild);
    CreateBiTree(T -> rchild);
  }
  return OK;
} // CreateBiTree

int r2 = 0;
int r1 = 0;
int r0 = 0;

void dfs(BiTree &T)
{
    if(T == NULL) return;

    if(!T -> lchild && !T -> rchild) r0++;
    if(!T -> lchild && T -> rchild || !T -> rchild && T -> lchild) r1++;
    if(T -> lchild && T -> rchild) r2++;
    dfs(T -> lchild);
    dfs(T -> rchild);
}

int main()   //主函数
{
    BiTree T;
    CreateBiTree(T);
    dfs(T);
    printf("%d\n%d\n%d",r2,r1,r0);
    return 0;
 }//main
