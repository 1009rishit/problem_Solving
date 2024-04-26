    #include<bits/stdc++.h>
    using namespace std;
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }   
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<vector<int>> parent(n);
    queue<int> q;
        for (int i=0; i<n; i++){
            if (indegree[i]==0)
                q.push(i);
        }
         while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto nbr : adj[front])
            {   
                vis[front][nbr] = 1;
                for(int i=0; i<n; i++)
                {  
                    if(vis[i][front] == 1)
                        vis[i][nbr] = 1;
                }
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
         for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==1) parent[j].push_back(i);
            }
        }
        return parent;
    }