#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& pref , int cost , int mid){
        int l = 0 , r = mid;
        int flag = false;
        while(r < pref.size()){
            int sum = pref[r] - pref[l];
            if(sum <= cost){
                flag = true;
                break;
            }
            l++;
            r++;
        }
        return flag;
    }
    int equalSubstring(string s, string t, int cost) {
        int n = s.size();
        vector<int> res(n + 1 , 0);
        for(int i = 1 ; i <= n ; i++){
            res[i] = res[i-1] + abs((s[i - 1] - 'a') - (t[i - 1] - 'a'));
        }
        int low = 0 , high = s.size()+1;
        int ans = 0;
        while(low <= high){
            int mid = (high+low)/2;
            if(check(res,cost,mid)){
                ans = mid ;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
