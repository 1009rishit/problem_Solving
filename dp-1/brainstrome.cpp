#include<bits/stdc++.h>
using namespace std;
    long long mostPoints(vector<vector<int>>& question) {       
        long long ans=0;
        int n=question.size();
        vector<long long>dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int valid=question[i][1]+i+1;
            if(valid>=n) dp[i]=question[i][0];
            else dp[i]=question[i][0]+dp[valid];
            ans=max(ans,dp[i]);
            dp[i]=max(dp[i],dp[i+1]);
        }
        return ans;
    }