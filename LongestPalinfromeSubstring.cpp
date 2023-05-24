#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
	int left = 0;
	int right = s.size()-1;

	while(left < right){
		if(s[left] != s[right]){
			return false;
		}
		left++;
		right--;
	}
	return true;
}

string longestPalindrome(string s){
	int n  = s.size();
	string longest = "";

	for(int i = 0; i<n; i++){
		for(int j = i; j<n; j++){
			string substring = s.substr(i,j-i+1);
			if(isPalindrome(substring)){
				if(substring.size() > longest.size()){
					longest = substring;
				}
			}
		}
	}
	return longest;
}

//optimised approach

string solve(string s){
	int n = s.size();
	int start = 0;
	int maxlen = 1;
	vector<vector<bool>>dp(n,vector<bool>(n,false));

	//substring of length 1 are all palindrome
	for(int i = 0; i<n; i++){
		dp[i][i] = true;
	}

	//substring of length 2
	for(int i = 0; i<n-1; i++){
		if(s[i] == s[i+1]){
			dp[i][i+1] = true;
			start = i;
			maxlen = 2;
		}
	}

	//now check for length 3 or greater than 3

	for(int len = 3; len<=n; len++){
		for(int i = 0; i<n-len+1; i++){
			int j = i+len-1;

			if(s[i] == s[j] and dp[i+1][j-1]){
				dp[i][j] = true;

				if(len > maxlen){
					start = i;
					maxlen = len;
				}
			}
		}
	}
	return s.substr(start,maxlen);
}

int main(){
	string s = "abc";
	cout<<longestPalindrome(s);
	cout<<endl;
	cout<<solve(s);
	return 0;
}