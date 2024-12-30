#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b;
    cin>>a>>b;
    long long ans=0,num=0;
    for(long long i=1;i<b;i*=2)
    {
        num+=i;
        ans++;
    }
    cout<<ans-1;
}