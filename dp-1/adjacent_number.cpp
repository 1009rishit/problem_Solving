 #include<bits/stdc++.h>
 using namespace std;
 int ms(int n, vector<vector<int>> &mat, vector<int> &a, int i){
        if(i>=n) return 0;
        if(a[i]!=-1) return a[i];
        return a[i] = max({ms(n, mat, a, i+1), max(mat[0][i], mat[1][i])})+ms(n, mat, a, i+2);
    }
    int maxSum(int n, vector<vector<int>> mat)
    {
        vector<int> a(n+1, -1);
        return ms(n, mat, a, 0);
    }