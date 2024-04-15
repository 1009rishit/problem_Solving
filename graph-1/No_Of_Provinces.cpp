#include<bits/stdc++.h>
using namespace std;
    int findCircleNum(vector<vector<int>>& nums) {
         int n=nums.size();
        if(n==0)return n;
        int count=0;
        vector<bool> visited(n,false);  
        for(int i=0;i<n;i++){
            if(visited[i])continue;
            queue<int> q;
            q.push(i);
            count++;

           while(!q.empty()){               
           int cur=q.front();
           q.pop();
           visited[cur]=true;
               for(int j=0;j<nums[cur].size();j++){
                    if(visited[j]==false&&nums[cur][j]==1){
                    q.push(j);
                    visited[j]=true;
                    }
               }
                    
            }
              
            
        }
        return count;
    }