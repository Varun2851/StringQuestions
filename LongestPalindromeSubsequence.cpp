#include<bits/stdc++.h>
using namespace std;

int solve(string s, int n){
	vector<vector<int>>dp(n,vector<int>(n,0));

	for(int i = 0; i<n; i++){
		dp[i][i] =  1;
	}

	for(int len = 2; len <= n; len++){
		for(int i = 0; i < n-len+1; i++){
			int j = i + len - 1;

			if(s[i] == s[j]){
				dp[i][j] = dp[i+1][j-1] +2;
			}
			else{
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	return dp[0][n-1];
}

int main(){
	string s = "abcabc";
	int n = s.size();
	cout<<solve(s,n);
	return 0;
}