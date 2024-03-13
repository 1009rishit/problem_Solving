#include<bits/stdc++.h>
using namespace std;
   bool solve(vector<int>& nums, int max,int limit){
    int count=0;
    for(int i=0;i<nums.size();i++){
        count+=(nums[i]-1)/limit;
        if(count>max) return false;
    }
    return true;
   }
    int minimumSize(vector<int>& nums, int max) {
        int a=INT_MIN;
        for(auto x: nums){
            a=a>x?a:x;
        }
        int low=1;
        int high=a;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(nums,max,mid)==true){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }