#include<bits/stdc++.h>
using namespace std;
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
           int u=edges[i][0];
           int v=edges[i][1];
           int weight=edges[i][2];
           adj[u].push_back({v,weight});
           adj[v].push_back({u,weight}); 
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            int count=0;
            pq.push({0,i});
            vector<bool>vis(n,false);
            
            while(!pq.empty()){
                auto it=pq.top();
                int weight=it.first;
                int node=it.second;
                pq.pop();
                if(!vis[node]) count++;
                vis[node]=true;
                for(auto nb:adj[node]){
                    int vnode=nb.first;
                    int we=nb.second;
                    if(we+weight<=distanceThreshold && !vis[vnode]){
                        pq.push({we+weight,vnode});
                    }
                }
            }
            ans[i]=count;
        }
        int res=INT_MAX;
        int city=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]<=res) {
                res=ans[i];
                city=i;
            }
        }
        return city;
    }