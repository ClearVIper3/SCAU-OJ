#include <iostream>//C++
using namespace std;
struct LNode
{
    int data;
    LNode * next;
};
void createList(LNode * &L,int n)
{/**< 尾插法创建单链表 */
    LNode *r, *p;
    r=L=new LNode;/**< 创建头结点 */
    L->next=NULL;
    for(int i=1;i<=n;i++)
    {
        p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}
void trv(LNode * L)
{ /**< 一个简单的链表遍历函数，供编程过程中测试使用 */
    L=L->next;
    while(L)
    {
        cout<<L->data<<' ';
        L=L->next;
    }
}
int getK(LNode * L,int k)
{
    LNode * ptr = L;
    LNode * res = L;
    while(k--)
        ptr = ptr -> next;
    if(!ptr) return -1;
    
    while(ptr != NULL)
    {
        ptr = ptr -> next;
        res = res -> next;
    }

    return res -> data;
}
int main()
{
    int n,k;
    LNode *L;
    cin>>n>>k;
    createList(L,n);
    //trv(L);
    cout<<getK(L,k);
    return 0;
}
