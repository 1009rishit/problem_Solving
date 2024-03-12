#include<bits/stdc++.h>
using namespace std;
    int searchRange(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1;
        int mid;
        while(low <= high)
        {
            long long mid = (low+high)/2;
            if(nums[mid]==target) return mid;

            if(nums[mid] >= nums[low])
            {
                if(target <= nums[mid] && target>= nums[low]) high = mid-1;
                else low = mid+1;
            }
            else if (nums[mid] <= nums[high])
            {
                if(target >= nums[mid] && target <= nums[high])low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
};