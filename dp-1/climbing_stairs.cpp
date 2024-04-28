#include<bits/stdc++.h>
using namespace std;
int climbStairs(int n) {
    int a=1;
    int b=1;
    int curr=1;
    for(int i=2;i<=n;i++){
      curr=a+b;
      a=b;
      b=curr;
    }
     return curr;
    }