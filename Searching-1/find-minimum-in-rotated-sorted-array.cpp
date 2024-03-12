#include<bits/stdc++.h>
using namespace std;
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        int mid;
        while(s<=e){
           mid=s+(e-s)/2;
            if(e-s<2)
            return min(nums[e],nums[s]);
            else if(nums[mid]<nums[mid-1]&& nums[mid]<nums[mid+1])
            return nums[mid];
            else if(nums[mid]>nums[mid-1]&& nums[mid]>nums[mid+1])
            return nums[mid+1];
            else if(nums[mid]>nums[mid-1] && nums[mid]>nums[nums.size()-1]){
                s=mid+1;
            }
            else
            e=mid-1;
            
        }
        return nums[mid];
};