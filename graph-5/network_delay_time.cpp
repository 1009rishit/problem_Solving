#include<bits/stdc++.h>
using namespace std;
 int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int ti=times[i][2];
            adj[u].push_back({v,ti});
        }
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
         while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int time = curr.first;
            int node = curr.second;
            for(auto it:adj[node]){
                int vnode=it.first;
                int t=it.second;
                if(time+t<dist[vnode]){
                    dist[vnode]=time+t;
                    pq.push({dist[vnode],vnode});
                }
            }
         }
        int maxi=INT_MIN;
        for(int i=1;i<dist.size();i++) {
            cout<<dist[i]<<" ";
            if(dist[i]==1e9) return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }