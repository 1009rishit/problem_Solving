#include<bits/stdc++.h>
using namespace std;
#define pathsss pair<int, pair<int,int>>
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        int r[4] = {-1,0,1,0}, c[4] = {0,1,0,-1};
        vector<vector<int>> dist(n,(vector<int>(m,1e9)));
        priority_queue<pathsss,vector<pathsss>,greater<pathsss>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int step=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(row==n-1 && col==m-1) return step;
            for(int i=0;i<4;i++){
                int nrow=row+r[i];
                int ncol=col+c[i];
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=m)continue;
                int nstep=max(step,abs(heights[nrow][ncol]-heights[row][col]));
                if(nstep<dist[nrow][ncol]){
                    dist[nrow][ncol]=nstep;
                    pq.push({nstep,{nrow,ncol}});
                }
            }
        }
        return 0;
    }