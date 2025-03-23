#include<cstdlib>
#include<cstdio>
#include <iostream>
#include <cstring>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
using namespace  std;
struct SqStack
{
    SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
    SElemType *top; // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)
{
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
    S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base) return ERROR;
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S,SElemType e)
{
// 在栈S中插入元素e为新的栈顶元素
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) return ERROR;
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    if(S.top==S.base) return ERROR;
    e=*(S.top-1);
    return OK;
}

int StackLength(SqStack S)
{
// 返回栈S的元素个数
    int i;
    i=S.top-S.base;
    return i;
}

Status StackTraverse(SqStack S)
{
// 从栈顶到栈底依次输出栈中的每个元素
    SElemType *p = (SElemType *)malloc(sizeof(SElemType));
    p = S.top;
    if(S.top==S.base)printf("The Stack is Empty!");
    else
    {
        printf("The Stack is: ");
        p--;
        while(p>=S.base)
        {
            printf("%d ", *p);
            p--;
        }
    }
    printf("\n");
    return OK;
}

char prio(char e,char c){//比较运算符优先级
    char n;
    switch(c){
        case'+':
        case'-':{
            if(e=='('||e=='=') n='<';  //c>e
            else n='>';}break;
        case'*':
        case'/':{
            if(e=='*'||e=='/'||e==')') n='>';//c<e
            else n='<';}break;
        case'(':{
            if(e==')')
            {
                printf("括号不匹配\n");
                exit(ERROR);
            }
            else n='<';} //c>e;
            break;
        case')':{
            if(e=='(') n='=';
            else if(e=='=') {printf("缺少左括号\n");exit(ERROR);}
            else n='>';
        }//e>c
            break;
        case'=':{
            if(e=='=') n='=';
            else if(e=='(') {printf("缺少右括号\n");exit(ERROR);}
            else n='>';
        } //e>c
    }//switch

    return n;
}

int main()
{
    SqStack s1,s2;//s1操作数栈，s2算符栈
    InitStack(s1);
    InitStack(s2);
    Push(s2,'=');
    char w;
    w=getchar();
        int e;
        GetTop(s2,e);
        while(w!='='||e!='=')
        {
          //  cout<<w<<endl;
          int d=0;
          if(w>='0'&&w<='9') {
              while (w >= '0' && w <= '9') {
                  d = d * 10 + (w - '0');
                  w = getchar();
              }
              Push(s1, d);
             // cout << d << endl;
          }
          else {
              if (prio(e, w) == '<') {
                  //cout<<"123"<<endl;
                  Push(s2, w);
                  //StackTraverse(s1);
                  w = getchar();

              } else if (prio(e, w) == '=' && w == ')') {
                  //cout<<"321"<<endl;
                  int t;
                  Pop(s2, t);
                  w = getchar();
              } else if (prio(e, w) == '>') {
                  int a, b, c = 0, d;
                  Pop(s1, a);
                  Pop(s1, b);
                  Pop(s2, d);
                  if (d == '+')
                      c = a + b;
                  else if (d == '-')
                      c = b - a;
                  else if (d == '/')
                      c = b / a;
                  else if (d == '*')
                      c = b * a;
                  Push(s1, c);
              }
          }
            GetTop(s2,e);
        }
        int r;
        Pop(s1,r);
        cout<<r<<endl;
    return 0;
}
