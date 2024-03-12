#include<bits/stdc++.h>
using namespace std;
    vector<int> searchRange(vector<int>& nums, vector<int> query) {
        for(int i=0;i<query.size();i++){
            int q=query[i];
            int ans=INT_MIN;
            int low=0,high=nums.size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[mid]<=q && q<ans){
                    q=mid;
                }
                if(nums[mid]>q) high=mid-1;
                else low=mid+1;
            }
        }
    }