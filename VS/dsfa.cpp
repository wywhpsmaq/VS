//
// Author: Mingtian Li
// Created by Administrator on 2024/11/23.
// Archive in "D:\c++ limingtian\VS\ouirr.cpp"
// Using CLion 2024.1.5
//
#include <bits/stdc++.h>
using namespace std;
int p[999][999],a=0;
int o[4]={-1,0,0,1};
int k[4]={0,1,-1,0};
int n=0,m=0;
bool oo= false;
int dfs(int x,int y){
    if(oo) return 0;
    if(p[x][y]==1) return 0;
    if(x==n&&y==m)
    {
        cout<<"yes";
        oo= true;
        return 0;
    }
    for (int i = 0; i < 4; ++i) {
        if (x + o[i] > 0 && y + k[i] > 0 && x + o[i] <= a && y + k[i] <= a && p[x + o[i]][y + k[i]] == 0) {
            p[x][y] = 1;
            dfs(x + o[i], y + k[i]);
            p[x][y] = 0;
        }
    }

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= a; ++j) {
            cin >> p[i][j];
        }
    }
    int i,j;
    cin>>i>>j>>n>>m;
    dfs(i,j);
    if(!oo) cout<<"NO";
}