#include <stdio.h>
#include <malloc.h>
typedef long long ll;
using namespace std;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;
void  CreateBiTree(BiTree &T)
{ /**< 先序建树算法 */
    char ch;
    scanf("%c",&ch);
    if (ch=='#') T = NULL;
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void Rview(BiTree T)
{/**< 右视图算法，用队列作为辅助存储结构 */
   BiTree q[1001];
   int f = 0,e = 0;
   if(T) q[e++] = T;
   while(f != e)
   {
       int sz = e - f;
       int bol = 1;
       for(int i = 0; i < sz; i++)
       {
            BiTree node = q[f++];
            if(bol){
                printf("%c",node -> data);
                bol = 0;
            }
            if(node -> rchild) q[e++] = node -> rchild;
            if(node -> lchild) q[e++] = node -> lchild;
       }
   }
}
int main()
{
    BiTree T;
    CreateBiTree(T);
    Rview(T);
    return 0;
}
