#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005;  
int n,V,cnt;
int dp[N];
int nw[N],nv[N];
int main()
{
	cin>>n>>V;
	for(int i=0;i<n;i++)
	{
		int w,v,s;
		cin>>n>>v>>s;
		int k=0;
		while(s>0)
		{
			int take=min(k,s);
			cnt++;
			nw[cnt]=w*take;
			nv[cnt]=v*take;
			s-=take;
			k*=2;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=V;j>=nw[i];j--)
		{
			dp[j]=max(dp[j],dp[j-nw[i]]+nv[i]);
		}
	}
	cout<<dp[V];
	return 0;
 } 



