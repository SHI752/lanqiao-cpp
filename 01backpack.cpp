#include<iostream>
#include<algorithm> 
using namespace std;
int dp[105];
int w[105],v[105];
int n,V;
int main()
{
	cin>>n>>V;
	for(int i=0;i<n;i++)
	{
		cin>>w[i]>>v[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=w[i];j<=V;j++)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[V];
	return 0;
}








