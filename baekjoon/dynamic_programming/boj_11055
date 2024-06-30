#include<iostream>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;
int dp[1001];
int a[1001];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[i]=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j])
                dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }
    cout<<*max_element(dp,dp+n);
}
