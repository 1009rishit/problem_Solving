#include<bits/stdc++.h>
using namespace std;
#define in INT_MAX
int solve(int n,vector<vector<int>> adj){
    int length=in;
    for(int i=0;i<n;i++){
        vector<int> dist(n,in);
        vector<int> parent(n,-1);

        dist[i]=0;
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(int it:adj[top]){
                if(dist[it]==in){
                    dist[it]=dist[top]+1;
                    parent[it]=top;
                    q.push(it);
                }
                else if(parent[top]!=it && parent[it]!=top)
                length=min(length,dist[it]+dist[top]+1);
            }
        }
    }
    if(length==in) return -1;
    return length;
}
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return solve(n,adj);
    }