#include<bits/stdc++.h>
using namespace std;
int knight(int A, int B, int C, int D, int E, int F) {
    int vis[A][B]={0};
    queue<pair<pair<int,int>,int>> q;
    
    q.push({{C,D},0});
    vis[C][D]=1;
    int r[8]={-2,-2,-1,-1,1,1,2,2};
    int c[8]={-1,1,-2,2,-2,2,-1,1};
    
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int step=q.front().second;
        q.pop();
        vis[row][col]=1;
        if(row==E && col==F) return step;
        
        for(int i=0;i<8;i++){
            int Nrow=row + r[i];
            int Ncol=col + c[i];
            if(Nrow>=0 && Ncol>=0 && Nrow<A && Ncol<B){
                if(Nrow==E && Ncol==F) return step+1;
            }
            if(!vis[Nrow][Ncol]){
               vis[Nrow][Ncol]=1;
               q.push({{Nrow,Ncol},step+1}); 
            }
        }
        return -1;
    }
}