#include<bits/stdc++.h>
using namespace std;
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }
        vector<double> prob(n, DBL_MIN);
        prob[start_node] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            double probability = curr.first;
            int node = curr.second;
            for(auto nb: adj[node]) {
                int vnode = nb.first;
                double pr = nb.second;
                if(probability*pr > prob[vnode]) {
                    prob[vnode] = probability*pr;
                    pq.push({prob[vnode], vnode});
                }
            }
        }
        return prob[end_node];
    }