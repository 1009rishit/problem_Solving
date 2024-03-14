#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int> a,int s,int mid){
    for(int i=0;i<a.size()-mid;i++){
        int sum=0,j=0;
        while(j<mid){
            sum+=a[i+j];
            j++;
        }
        if(sum>s) return false;
    }
    return true;
}
int find(vector<int>& a,int s){
    int low=1;
    int high=a.size();
    int mid;
    int ans=0;
    while(low<=high){
        mid=(low+high)/2;
        if(solve(a,mid,s)==true) {
         low=mid+1;
         ans=mid;
        }
        else high=mid-1;
    }
 return ans;
}