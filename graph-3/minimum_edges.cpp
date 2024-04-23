#include<bits/stdc++.h>
using namespace std;
  int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            unordered_map<int,list<pair<int,int>>> adj;
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back({v,0});
                adj[v].push_back({u,1});
                
            }
            vector<int> dist(n+1,INT_MAX);
            set<pair<int,int>> st;
            st.insert({0,src});
            dist[src] = 0;
            while(!st.empty()){
                auto top = *(st.begin());
                st.erase(st.begin());
                int currDist = top.first;
                int currNode = top.second;  
                for(auto nbr : adj[currNode]){   
                    int nbrNode = nbr.first;
                    int wt = nbr.second; 
                    int newCost = currDist+wt;    
                    if(newCost < dist[nbrNode]){    
                        if(dist[nbrNode] != INT_MAX)
                        {
                            st.erase(st.find(make_pair(dist[nbrNode],nbrNode)));
                        }
                        dist[nbrNode] = newCost;
                        st.insert({newCost,nbrNode});
                    }
                }
            }
            if(dist[dst] == INT_MAX){
                return -1;
            }
            return dist[dst];
    }