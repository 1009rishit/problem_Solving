#include<bits/stdc++.h>
using namespace std;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int fcount = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 2;
                    q.push({{i,j},0});
                }
                
                if(grid[i][j] == 1){
                    fcount++;
                }
                
            }
        }

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int tmax = 0;
        
        int count = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tmax = max(tmax,t);
            
            for(int i=0;i<4;i++){
                int row = r + dr[i];
                int col = c + dc[i];
            
                if(row >= 0 && col >= 0 && row < n && col < m && grid[row][col] == 1 && visited[row][col] != 2){
                    visited[row][col] = 2;
                    q.push({{row,col},t + 1});
                    count++;
                }
            }
        }

        if(fcount != count){
            return -1;
        }

     return tmax;
}