#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int n=matrix.size();
     int m=matrix[0].size();
     int low=0;
     int high=n*m-1;
     while(low<=high){
        int mid=(low+high)/2;
        int middle_value=matrix[mid/m][mid%m];
        if(middle_value<target) low=mid+1;
        else if(middle_value>target) high=mid-1;
        else return true;
       }
       return false;
    } 