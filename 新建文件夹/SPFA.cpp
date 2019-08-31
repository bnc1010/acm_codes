#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int mod = (int) 1e9+7;

int n,m,dis[51][51],dist[51];
bool inq[51]; //inq[i]代表i是不是在队列中 
void spfa(int x){
	queue<int> q;
	dist[x]=0;
	q.push(x);
	inq[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0; //u点已经离开队列，就把inq[u]置为0 
		for(int i=0;i<n;i++){
			if(dist[i]-dis[u][i]>dist[u]){
				dist[i]=dist[u]+dis[u][i]; //更新i点到起点的距离 
				if(inq[i])continue; //如果已经在队列里，跳过后续步骤 
				q.push(i); //把i点放入队列 
				inq[i]=1; //更新inq[i] 
			}
		}
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(dis,125,sizeof(dis));
		memset(dist,125,sizeof(dist));
		for(int i=0;i<=n;i++)dis[i][i]=0;
		int x,y;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			dis[x][y]=1;
		}
		spfa(1);
		if(dist[n]>mod)printf("no\n");
		else printf("yes\n");
	}
	return 0;
}