#include<iostream>
using namespace std;
int arr[2010],dp[2010][2010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;	
	cin>>n;
	for(int i=1;i<=n;i++)	    
		cin>>arr[i];
	for(int i=1;i<=n;i++){
		dp[i][i]=1;
		if(arr[i-1]==arr[i])
			dp[i-1][i]=1;
	}
	for(int gap=2;gap<n;gap++){
		for(int j=1;j<=n-gap;j++){
			int s=j,en=j+gap;
			if(dp[s+1][en-1] &&arr[s]==arr[en])
				dp[s][en]=1;
		}
	}
	int t;
	cin>>t;
	while(t--){
		int s,e;
		cin>>s>>e;
		cout<<dp[s][e]<<'\n';
	}
	
}
