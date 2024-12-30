#include <bits/stdc++.h>
using namespace std;
struct un
{
    int a, b;
};
bool cmp(un x,un y)
{
    return x.a > y.a;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<un> v(k);
    for (int i=0;i<k;i++)
    {
        cin>>v[i].a>>v[i].b;
    }
    sort(v.begin(),v.end()+1,cmp);
    int p = 0;
    for (int i=0;i<k&&n>0;i++)
    {
        int o=min(n,v[i].b);
        p+=o*v[i].a;
        n-=o;
    }
    p--;
    if (p>m)
    {
        cout<<p-m;
    }
    else
    {
        cout<<"NO";
    }
}