#include <iostream>
#include <cstdio>
using namespace std;
int a[1000001],n,s[1000001],top=0;/**< s为栈结构，top为栈顶指针 */
int main()
{
    int i,j=1,k,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {/**< 算法思想：判断可以出栈的栈顶元素和尚未入栈的元素哪个更大 */
        int maxs=a[j];/**< 先找到还没入栈的元素中最大值 */
        for(k=j;k<=n;k++)
              maxs=max(maxs,a[k]);
        if(top==0||s[top-1]<maxs)/**< 空栈或栈顶元素<未入栈最大值 */
        {
            while(a[j]!=maxs) /**< 将后面的元素依次入栈 */
                s[top++]=a[j++];
            cout<<maxs<<' ';
            j++;/**< 跳过这个maxs值 */
        }
        else
            cout<<s[--top]<<' ';/**< 栈顶元素更大，出栈 */
    }
    return 0;
}
