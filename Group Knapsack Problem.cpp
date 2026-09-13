#include<iostream>
#include<algorithm> 
using namespace std;
int dp[105];
int n,V;
int main()
{
	cout<<"输入背包重量，组数" <<endl; 
	cin>>V>>n;//输入背包容量V,n组元素 
	struct Group
	{
		int k;//本组k件物品 
		int w[105];
		int v[105];
	};
	Group g[105];//群组g[0]第0组g[1]...... 
	for(int i=0;i<n;i++)
	{
		cout<<"输入第n组物品数量"<<endl;
		cin>>g[i].k;//输入第n组物品数量k 
		for(int t=0;t<g[i].k;t++) 
		{
			cout<<"输入第n组物品重量，价值"<<endl; 
			cin>>g[i].w[t]>>g[i].v[t];//输入第n组物品重量w，价值v 
		}
	}
	for(int i=0;i<n;i++)//第i组元素 
	{
		for(int j=V;j>=0;j--)//背包容量 V遍历dp[]数组 
		{
			for(int t=0;t<g[i].k;t++)//遍历第i组元素每个物品 
			if(j>=g[i].w[t]) 
			{
				dp[j]=max(dp[j],dp[j-g[i].w[t]]+g[i].v[t]);//比较价值，拿取物品，更新dp【】数组 
			}
		}
	}
	cout<<dp[V];
	return 0;
}








