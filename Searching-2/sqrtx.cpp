#include<bits/stdc++.h>
using namespace std;
int mySqrt(int x) {
      int s=1;
      int e=x;
      if(x==0) return 0;
      else{
          while (s<=e){
              int mid= s+(e-s)/2;
              if(mid*mid==x)
              return mid;
              else if(mid*mid>x)
              e=mid-1;
              else
              s=mid+1;
          }
      } 
      return e;
    }