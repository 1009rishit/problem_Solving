#include<bits/stdc++.h>
using namespace std;
int findMedian(int A[100][100],int n,int m) {
    int low=A[0][0];
    int high=A[n-1][m-1];
    int target=n+m/2;
    while(low<=high){
        int mid=(low+high)/2;
        int smaller=0;
        for(int i=0;i<n;i++)
            smaller+=upper_bound(A[i],A[i]+n,mid)-A[i];
        if(smaller<=target) low=mid+1;
        else high=mid-1;
    }
    return low;
}