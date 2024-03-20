 #include<bits/stdc++.h>
 using namespace std;
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    if (n <m ) return findMedianSortedArrays(nums2, nums1);	
    int low = 0, high = m * 2;
    while (low <= high) {
        int mid2 = (low +high) / 2; 
        int mid1 = n + m - mid2; 
        
        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == n * 2) ? INT_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == m * 2) ? INT_MAX : nums2[(mid2)/2];
        
        if (L1 > R2) low = mid2 + 1;		
        else if (L2 > R1) high = mid2 - 1;	
        else return (max(L1,L2) + min(R1, R2)) / 2;
    }
    return -1;
    }