#include<bits/stdc++.h>
using namespace std;
void solve(int mat[100][100], int n, int k,int mid,int& count){
    for(int i=0;i<n;i++){
        int smaller=0;
        for(int j=0;j<n;j++){
            if(mat[i][j]<=k) smaller++;
            else break;
        }
        count+=smaller;
    }
}
int kthSmallest(int mat[100][100], int n, int k)
{
  int low=mat[0][0];
  int high=mat[n-1][n-1];
  if(k==n*n) return high;
  while(low<high){
      int mid=(low+high)/2;
      int count=0;
      solve(mat, n, k, mid,count);
      if(count<k) low=mid+1;
      else if(count>=k) high=mid;
  }
  return low-1;
}