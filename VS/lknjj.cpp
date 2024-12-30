//
// Author: Mingtian Li
// Created by Administrator on 2024/11/23.
// Archive in "D:\c++ limingtian\VS\ouirr.cpp"
// Using CLion 2024.1.5
//
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
int n;
int maze[MAXN][MAXN];
bool visited[MAXN][MAXN];

// 四个方向的移动向量
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0 && !visited[x][y];
}

bool dfs(int x, int y, int bx, int by) {
    if (x == bx && y == by) {
        return true; // 到达终点
    }
    visited[x][y] = true; // 标记当前位置为已访问
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny)) {
            if (dfs(nx, ny, bx, by)) {
                return true;
            }
        }
    }
    visited[x][y] = false; // 回溯，取消标记
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }
    int ha, la, hb, lb;
    cin >> ha >> la >> hb >> lb;

    // 检查起点和终点是否可通行
    if (maze[ha][la] == 1 || maze[hb][lb] == 1) {
        cout << "NO" << endl;
        return 0;
    }

    if (dfs(ha, la, hb, lb)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}