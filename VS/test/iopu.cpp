#include <cmath>
#include <iostream>
using namespace std;
int zhishu(int a)
{
    for(int i=2;i<=(int)sqrt(a)+1;i++)
    {
        if(a%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int fan(int a)
{
    int x;
    int n,m;
    n=a%10;
    m=(a/10)%10;
    x=n*10+m;
    if(zhishu(a)==1&&zhishu(x)==1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        if(fan(i)==1)
        {
            cout<<i<<'\n';
        }
    }
}