#include<bits/stdc++.h>
using namespace std;
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid;
        int sh=-1,eh=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target)
            { sh=mid;
              e=mid-1;
              }
              else if (nums[mid]<target) s=mid+1;
              else e=mid-1;
        }
        s=0;
        e=nums.size()-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]== target){
                eh=mid;
                s=mid+1;
            }
            else if(nums[mid]<target){
                s= mid+1;
            }
            else e=mid-1;
        }
        return{ sh,eh};
};