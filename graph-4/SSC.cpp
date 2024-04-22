#include<bits/stdc++.h>
using namespace std;
void dfs(int node,stack<int>& st,vector<vector<int>>& adj,vector<bool>& vis){
	    vis[node]=true;
	        for(auto it:adj[node]){
	            if(!vis[it]) dfs(it,st,adj,vis);
	    }
	    st.push(node);
	}
	void dfs2(int node,vector<vector<int>>& adj,vector<bool>& vis){
	    vis[node]=true;
	    for(auto it:adj[node]){
	           if(!vis[it]) dfs2(it,adj,vis);
	 
	}
}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<bool>vis(V,false);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,st,adj,vis);
        }
        }
        vector<vector<int>> adj2;
        for(int i=0;i<V;i++){
            vector<int> vec=adj[i];
            for(auto x:vec){
                adj2[x].push_back(i);
            }
        }
        int ans=0;
        vector<bool>vis2(V,false);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                ans++;
                dfs2(node,adj2,vis2);
            }
        }
        return ans;
    }