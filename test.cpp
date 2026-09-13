#include<iostream>
#include<queue>
using namespace std;
struct jiego{
	int x,y,temp;
};
int vis[105][105];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int maze[5][5]={
0,1,0,0,0,
0,1,0,1,0,
0,0,0,1,0,
0,1,1,1,0,
0,0,0,0,0,
};
  int main()
  {
  	queue<jiego> q;
  	q.push({0,0,0});
  	vis[0][0]=1;
  	while(!q.empty())
  	{
  		jiego u=q.front();
  		q.pop();
  		// 判断是不是走到终点
		  if(u.x==4&&u.y==4)
		  {
		  	cout<<u.temp<<endl;
		  	return 0;
		   } 
		  //  四个方向
		  for(int i=0;i<4;i++)
		  {
		  	int nx=u.x+dx[i];
		  	int ny=u.y+dy[i];
		  	//边界·不是墙·没走过
			  if(nx>=0&&nx<5&&ny>=-0&&ny<5&&maze[nx][ny]==0&&vis[nx][ny]==0){
			  	vis[nx][ny]=1;
			  	q.push({nx,ny,u.temp+1});
			  } 
		  }
	  }
	  return 0;
	}  
    
    
    
