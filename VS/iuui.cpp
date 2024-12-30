//
// Author: Mingtian Li
// Created by Administrator on 2024/11/23.
// Archive in "D:\c++ limingtian\VS\ouirr.cpp"
// Using CLion 2024.1.5
//
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n,d;
int zz(int a)
{
    if(v.size()==0)
    {
        v.push_back(a);
        return 0;
    }
    for (int i = 0; i+1 < v.size(); ++i) {
        if(v[i]<a&&v[i+1]>a)
        {
            if(a-v[i]>=d&&v[i+1]-a>=d)
            {
                cout<<a<<" ";
                v.push_back(a);
                return 0;
            }
        }
    }
    v.push_back(v[v.size()-1]+d);
}
int main() {
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
    cin>>n>>d;
    for(int i=1; i<=n; i++) {
        int x;cin>>x;
        zz(x);//为当前牛选座位
        sort(v.begin(),v.end());
    }
    return 0;
}
