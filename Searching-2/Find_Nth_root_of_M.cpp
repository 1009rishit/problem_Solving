#include<bits/stdc++.h>
using namespace std;
   int NthRoot(int n, int m)
	{
	    if(m==0 || m==1) return m;
	   int s=1;
	   int e=m/n;
	   int x=m;
	   while(s<=e){
	       long long ans=1;
	       long long mid=(e+s)/2;
	       for(int i=0;i<n;i++){
	           if(ans>x)break;
	           ans*=mid;
	       }
	       if(ans==x) return mid;
	       else if(ans>x)e=mid-1;
	       else s=mid+1;
	   }
	   return -1;
	}  