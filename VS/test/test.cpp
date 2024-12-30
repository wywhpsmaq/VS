#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int b[100][100];
int x,y;
int main()
{
    cin>>x>>y;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(i!=0&&j!=0&&i!=x-1&&j!=y-1)
            {
                cout<<round((a[i][j]+a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1])/5)<<" ";
            }
            else
            {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<'\n';
    }
}