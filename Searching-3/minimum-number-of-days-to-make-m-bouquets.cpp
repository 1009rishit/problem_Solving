#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>& bloom, int m, int k,int dist){
        int count=0;
        int buq=0;
        for(int i=0;i<bloom.size();i++){
            if(bloom[i]<=dist) count++;
            else count=0;
            if(count==k) {
                count=0;
                buq++;
            }
        }
        return (buq>=m);
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int a=INT_MAX,b=INT_MIN;
        for(int i=0;i<bloom.size();i++){
            a=min(a,bloom[i]);
            b=max(b,bloom[i]);
        }
        int low=a;
        int high=b;
        long long ab=(long)m;
        long long ba=(long)k;
        long long val=ab*ba;
        if(val>bloom.size()) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(bloom,m,k,mid)==false) low=mid+1;
            else high=mid-1;
        }
      return low;
    }