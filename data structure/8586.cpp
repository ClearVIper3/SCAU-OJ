typedef char SElemType;
#include"malloc.h" 
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量
struct SqStack
{
 SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
 SElemType *top; // 栈顶指针
 int stacksize; // 当前已分配的存储空间，以元素为单位
 }; // 顺序栈
Status InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType)); // 为栈分配空间
    if (!S.base) // 如果分配失败
        return ERROR;
    S.top = S.base;   // 栈顶指针初始化为栈底
    S.stacksize = STACK_INIT_SIZE;  // 初始化栈的大小
    return OK;
}

// 判断栈是否为空
Status StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return TRUE;  // 栈空
    else
        return FALSE; // 栈非空
}

// 入栈操作
Status Push(SqStack &S, SElemType e)
{
    // 判断栈是否已满，如果已满则需要扩展栈空间
    if (S.top - S.base >= S.stacksize)
    {
        SElemType *newbase = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!newbase)
            return ERROR;
        S.base = newbase;
        S.top = S.base + S.stacksize; // 更新栈顶指针
        S.stacksize += STACKINCREMENT; // 增加栈的空间
    }
    *(S.top++) = e;  // 将元素e放入栈顶，并将栈顶指针后移
    return OK;
}

// 出栈操作
Status Pop(SqStack &S, SElemType &e)
{
    if (StackEmpty(S))  // 如果栈空，则无法弹出
        return ERROR;
    e = *(--S.top);    // 将栈顶元素赋值给e，栈顶指针后移
    return OK;
}

void check()
 { // 对于输入的任意一个字符串，检验括号是否配对
   SqStack s;
   SElemType ch[80],*p,e;
   if(InitStack(s)) // 初始化栈成功
   {
    //printf("请输入表达式\n");
     scanf("%s",ch);
     p=ch;
     while(*p) // 没到串尾
       switch(*p)
       {
         case '(':
         case '[':Push(s,*(p++));
                  break; // 左括号入栈，且p++
         case ')':
         case ']':if(!StackEmpty(s)) // 栈不空
                  {
                   Pop(s,e); // 弹出栈顶元素
                    if(*p==')'&&e!='('||*p==']'&& e!='[') 
                                                // 弹出的栈顶元素与*p不配对
					{
                      printf("isn't matched pairs\n");
                      exit(ERROR);
                    }
                    else
                    {
                     p++;
                      break; // 跳出switch语句
                    }
                  }
                  else // 栈空
                  {
                    printf("lack of left parenthesis\n");
                    exit(ERROR);
                  }
         default: p++; // 其它字符不处理，指针向后移
       }
     if(StackEmpty(s)) // 字符串结束时栈空
       printf("matching\n");
     else
       printf("lack of right parenthesis\n");
   }
 }
int main()
 {
   check();
 }
