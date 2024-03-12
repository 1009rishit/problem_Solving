#include<bits/stdc++.h>
using namespace std;
 int findMin(vector<int> nums, int n){
       int low=0,high=nums.size()-1;
       int mid;
       while(low<=high){
           mid=low+high/2;
           if(high-low<2) return high;
           if(nums[mid]<nums[mid-1] && nums[mid] <nums[mid+1])  return mid;
           else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid+1;
           else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]) low=mid+1;
           else high=mid+1;
       }
       return mid;
 }