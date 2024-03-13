#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int> &boards, int k,int mini){
    int sum=0,painter=1;
    for(int i=0;i<boards.size();i++){
        sum+=boards[i];
        if(sum>mini){
            sum=boards[i];
            painter++;
        }
        if(painter>=k) return false;
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int a=0,b=0;
    for(int i=0;i<boards.size();i++){
        a=max(a,boards[i]);
        b+=boards[i];
    }
    int low=a;
    int high=b;
    while(low<=high){
        int mid=(low+high)/2;
        if(solve(boards,k,mid)==true){
            high=mid-1;
        }
            else low=mid+1;
    }
    return low;
}