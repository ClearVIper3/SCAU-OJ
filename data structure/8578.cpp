#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList &L)
{  // 算法2.3
  // 构造一个空的线性表L。
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return ERROR;        // 存储分配失败
  L.length = 0;                  // 空表长度为0
  L.listsize = LIST_INIT_SIZE;   // 初始存储容量
  return OK;
} // InitList_Sq

int input_Sq(SqList &L,int n)//n是个数
{
    int x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        L.elem[i]=x;
        L.length++;
    }
    return OK;
}

int exchange_Sq(SqList &L1,SqList &L2)//将L1数据逆序放入L2
{
    int i=L1.length-1,j=0;
    while(j<L1.length)
    {
        L2.elem[j]=L1.elem[i];
        j++;i--;
        L2.length++;
    }
    return OK;
}

void output_Sq(SqList L)//输出顺序表
{
    int i;
    for(i=0;i<L.length;i++)
    {
        printf("%d ",L.elem[i]);
    }
}

int main()
{
    SqList L1,L2;
    int n;
    scanf("%d",&n);
    InitList_Sq(L1);//创建L1
    input_Sq(L1,n);//输入L1
    InitList_Sq(L2);//创建L2

    exchange_Sq(L1,L2);//将L1数据逆序放入L2
    printf("The List is:");
    output_Sq(L1);
    printf("\n");
    printf("The turned List is:");
    output_Sq(L2);
    return 0;
}

