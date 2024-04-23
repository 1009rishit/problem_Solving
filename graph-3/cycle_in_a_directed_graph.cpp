    #include <bits/stdc++.h>
    using namespace std;
    bool dfs(int node,vector<int> adj[],int vis[],int path[]){
        vis[node]=1;
        path[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path)==true) return true;
            }
            else if(path[it]) return true;
        }
        path[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int path[V]={0};
        
        for(int i=1;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)==true) return true;
            }
        }
        return false;
    }