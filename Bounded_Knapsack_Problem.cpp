#include<iostream> 
#include<algorithm>
using namespace std;
const int N=10005;
int n,V;
int cnt=0;
int dp[N];
int nw[N],nv[N];
int main()
{
	cout<<"请输入物品种类数量，背包容量" ;
	cin>>n>>V;
	int w,v,s;
	/*二进制优化思路：把物品按分2的n次方分组循环拿取时拿多件减少循环*/ 
	for(int i=0;i<n;i++)
	{
		cout<<"请依次输入每种物品重量，价值，数量" ; 
		cin>>w>>v>>s;
		int k=1;
	    while(s>0){
		int take=min(k,s);//比较物品数量，防止多拿 
		cnt++;
		nw[cnt]=take*w;//take件物品 
		nv[cnt]=take*v;
		s-=take;
		k*=2;//分组多件拿取 
	    }
	}
	for(int i=0;i<=cnt;i++)//i<=cnt不是n，有cnt组元素 
	{
		for(int j=V;j>=nw[i];j--)
		{
			dp[j]=max(dp[j],dp[j-nw[i]]+nv[i]);
		}
	}
	cout<<"最优方案价值"; 
	
	cout<<dp[V];
	return 0;
}





