#include<bits/stdc++.h>
using namespace std;
bool solve( vector<int> &stalls,int dist,int k){
        int last=stalls[0];
        int count=1;
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=dist){
                count++;
                last=stalls[i];
            }
            if(count>=k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[stalls.size()-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(solve(stalls,mid,k)==true) low=mid+1;
        else high=mid-1;
    }
    return high;
    }