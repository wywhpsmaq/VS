//
// Author: Mingtian Li
// Created by Administrator on 2024/11/23.
// Archive in "D:\c++ limingtian\VS\ouirr.cpp"
// Using CLion 2024.1.5
//
#include<bits/stdc++.h>
using namespace std;
int zz(int a)
{
    if(a==2) return 1;
    if(a<4) return 0;
    for(int i=2;i*i<=a;i++) if(a%i==0) return 0;
    return 1;
}
int ff(int a)
{
    long long ans=0;
    while(a>0)
    {
        ans*=10;
        ans+=a%10;
        a/=10;
    }
    return ans;
}
int main()
{
    vector<int> v;
    int a;
    v.push_back(0);
    while(cin>>a&&a!=-1) v.push_back(a);
    cin>>a;
    int p,n,m;
    for(int i=0;i<a;i++)
    {
        cin>>p>>n>>m;
        if(p==1)
        {
            if(!zz(n))
            {
                v.insert(v.begin()+n+1,m);
            }
        }
        else if(p==2)
        {
            v[n]=m;
        }
        else if(p==3)
        {
            int g=ff(v[n]);
            v[n]=ff(v[m]);
            v[m]=g;
        }
        else
        {
            if(!zz(v[n]+m))
            {
                v.erase(v.begin()+n);
            }
        }
        for(int j=1;j<v.size();j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<'\n';
    }
}
