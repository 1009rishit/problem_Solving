 #include<bits/stdc++.h>
using namespace std;
 int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int mini=INT_MAX;
            int j=1;
            while(i-j*j>=0){
                mini=min(mini,dp[i-j*j]+1);
                j++;
            }
            dp[i]=mini;
        } 
        return dp[n];
    }