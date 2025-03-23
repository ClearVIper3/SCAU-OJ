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

Status PreOrderTraverse( BiTree T) {
   // 前序遍历二叉树T的递归算法
   //补全代码,可用多个语句
  if(T == NULL) return OK;

  printf("%c",T->data + 'A');
  PreOrderTraverse(T -> lchild);
  PreOrderTraverse(T -> rchild);
  return OK;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T) {
     // 中序遍历二叉树T的递归算法
    //补全代码,可用多个语句
    if(T == NULL) return OK;

    InOrderTraverse(T -> lchild);
    printf("%c",T->data + 'A');
    InOrderTraverse(T -> rchild);
    return OK;
  
} // InOrderTraverse

Status PostOrderTraverse( BiTree T) {
     // 后序遍历二叉树T的递归算法
     //补全代码,可用多个语句
     if(T == NULL) return OK;

     PostOrderTraverse(T -> lchild);
     PostOrderTraverse(T -> rchild);
     printf("%c",T->data + 'A');
     return OK;
} // PostOrderTraverse



int main()   //主函数
{
    BiTree T;
    CreateBiTree(T);
    if(!PreOrderTraverse(T)) printf("preERROR\n");
    printf("\n");
    if(!InOrderTraverse(T)) printf("inERROR\n");
    printf("\n");
    if(!PostOrderTraverse(T)) printf("postERROR\n");
    return 0;
}//main

