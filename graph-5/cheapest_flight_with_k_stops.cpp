#include<bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
           int u=edges[i][0];
           int v=edges[i][1];
           int weight=edges[i][2];
           adj[u].push_back({v,weight});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int> dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            auto it=q.front();
            int stops=it.first;
            int node=it.second.first;
            int price=it.second.second;
            q.pop();
            if(stops>k) continue;

            for(auto nb:adj[node]){
                int vnode=nb.first;
                int rate=nb.second;
                if(rate+price<dist[vnode] && stops<=k){
                    dist[vnode]=rate+price;
                    q.push({stops+1,{vnode,dist[vnode]}});
                }   
            }

        }
        if(dist[dst]!=1e9) return dist[dst];
        return -1;
    }