#include<iostream> 
#include<algorithm>
#include<queue>
using namespace std;
int vis[105][105];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct jiego{
	int x,y,step;//结构体定义时定义结构体名加变量名。含义是结构体类型变量，存结构体的结构。 
};
int N,M;
int Z,D; 
int main()
{
	cout<<"请输入迷宫终点"; 
	cin>>Z>>D;
	cout<<"请输入迷宫规格";
	cin>>M>>N;
	int maze[M][N];
	cout<<"请输入迷宫结构" ;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>maze[i][j];//双层for循环输入i*j(N*M)规格迷宫 
		}
	}
	queue<jiego> q;
	q.push({0,0,0});//先添加队头不要急着弹出，先判断条件在while循环里面弹出 
	vis[0][0]=1;
	while(!q.empty())
	{
		jiego cur=q.front();
		q.pop();
		if(cur.x==Z&&cur.y==D)
		{
			cout<<cur.step;
		}
		for(int i=0;i<4;i++)
		{
			//循环四个方向判断哪边能走添加队头，标记坐标，增加计数 
			int nx=cur.x+dx[i];
			int ny=cur.y+dy[i];
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&vis[nx][ny]==0&&maze[nx][ny]==0)
			{
				vis[nx][ny]=1;
				q.push({nx,ny,cur.step+1});
			}
		}
	}
	return 0; 
 } 
 



