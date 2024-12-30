//
// Author: Mingtian Li
// Created by Administrator on 2024/11/23.
// Archive in "D:\c++ limingtian\VS\ouirr.cpp"
// Using CLion 2024.1.5
//
#include <bits/stdc++.h>
using namespace std;
int n, op, x;
priority_queue <int, vector <int>, greater <int> > q;
int main()
{
    cin >> n;
    while(n--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> x;
            q.push(x);
        }
        else if(op == 2)
        {
            cout << q.top() << endl;
        }
        else q.pop();
    }
}