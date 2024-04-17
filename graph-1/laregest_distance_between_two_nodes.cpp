#include<bits/stdc++.h>
using namespace std;
int res = 0;
int dfs(int node, vector<vector<int>>& adj, int vis[]) {
    vis[node] = 1;
    priority_queue<int> pq;
    int ans = 0;
    for (auto it : adj[node]) {
        if (vis[it] != 1) {
            ans = 1 + dfs(it, adj, vis);
            pq.push(ans);
        }
    }
    int a = 0, b = 0;
    if (!pq.empty()) {
        a = pq.top();
        pq.pop();
    }
    if (!pq.empty()) {
        b = pq.top();
        pq.pop();
    }
    res = max(res, a + b);
    return max(a, b);
}
int solve(vector<int> &A) {
    vector<vector<int>> adj;
    int root=-1;
    int vis[A.size()]={0};
    for(int i=0;i<A.size();i++){
        if(A[i]==-1) {
            root=i;
            continue;
        }
        adj[A[i]].push_back(i);
        adj[i].push_back(A[i]);
    }
    dfs(root, adj, vis);
    return res;
}