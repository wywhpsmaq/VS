//
// Author: Mingtian Li
// Created by Administrator on 2024/11/23.
// Archive in "D:\c++ limingtian\VS\ouirr.cpp"
// Using CLion 2024.1.5
//
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[2005],k,ans,l,r,ll,rr;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    l=1; r=1; k=1; b[a[1]]=1; ans=1000005;
    while(l<=r && r<=n){
        if(k==m){
            if(ans>r-l+1){
                ans=r-l+1;
                ll=l; rr=r;}
            b[a[l]]--;
            if(b[a[l]]==0) k--;
            l++;}else{
            r++;
            b[a[r]]++;
            if(b[a[r]]==1) k++;}}
    cout<<ll<<" "<<rr;}