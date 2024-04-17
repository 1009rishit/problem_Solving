#include<bits/stdc++.h>
using namespace std;
int r[4] = {1, 0, 0, -1};
int c[4] = {0, -1, 1, 0};
void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
  vis[row][col] = 1; 
  queue<pair<int, int>> q;
  q.push({row, col});

  int n = grid.size();
  int m = grid[0].size();

  while (!q.empty()) {
    int newrow = q.front().first;
    int newcol = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextRow = newrow + r[i];
      int nextCol = newcol + c[i];

      if (nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < m &&
          grid[nextRow][nextCol] == '1' && vis[nextRow][nextCol] == 0) {
        vis[nextRow][nextCol] = 1;
        q.push({nextRow, nextCol});
      }
    }
  }
}
int numIslands(vector<vector<char>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '1' && vis[i][j] == 0) {
        bfs(i, j, grid, vis);
        count++;
      }
    }
  }
return count;
    }