#include<bits/stdc++.h>
using namespace std;
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> vis(n,0);
    for(int i=0;i<edges.size();i++){
        int a=edges[i][1];
        vis[a]=1;
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(vis[i]==0) ans.push_back(i); 
    }
    return ans;
}