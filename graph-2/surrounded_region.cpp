    #include<bits/stdc++.h>
    using namespace std;
    int r[4]={1,0,0,-1};
    int c[4]={0,1,-1,0};
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;

        for(int i=0;i<4;i++){
            int newrow=row+r[i];
            int newcol=col+c[i];
            if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && vis[newrow][newcol]==0 && board[newrow][newcol]=='O'){
                dfs(newrow,newcol,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++){
            if(vis[0][i]==0 && board[0][i]=='O') dfs(0,i,vis,board);
            if(vis[n-1][i]==0 && board[n-1][i]=='O') dfs(n-1,i,vis,board);
        }
        
        for(int i=0;i<n;i++){
             if(vis[i][0]==0 && board[i][0]=='O') dfs(i,0,vis,board);
            if(vis[i][m-1]==0 && board[i][m-1]=='O') dfs(i,m-1,vis,board);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }