#include <iostream>
#include <queue>
#include <string>
#include <deque>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int dp[10001]={0, };
		dp[0]=1;
		int N;
		int coin[21];
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>coin[i];
		}
		int m;
		cin>>m;
		for(int j=0;j<N;j++){
			for(int k=coin[j];k<=m;k++){
				dp[k]+=dp[k-coin[j]];
			}
		}
		cout<<dp[m]<<"\n";
	}
	return 0;
		

}
