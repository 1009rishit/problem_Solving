	#include<bits/stdc++.h>
    using namespace std;
    vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> ans(n, vector<int>(m, -1));
	    queue<pair<int, int>> q;
	    
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            if(grid[i][j]==1){
	                ans[i][j] = 0;
	                q.push({i, j});
	            }
	        }
	    }
	    
	    int r[4] = {-1, 1, 0, 0};
	    int c[4] = {0, 0, -1, 1};
	    
	    while(!q.empty()){
	        
	        int row = q.front().first;
	        int col = q.front().second;
	        q.pop();
	        
	        for(int i = 0; i<4; i++){
	            int newR = row + r[i];
	            int newC = col + c[i];
	            
	            if(newR>=0 && newR<n && newC>=0 && newC<m && ans[newR][newC]==-1){
	                ans[newR][newC] = ans[row][col]+1;
	                q.push({newR, newC});
	            }
	        }
	    }
	    
	    return ans;
	}