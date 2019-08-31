#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int mod = (int) 1e9+7;

int n,m,dis[51][51],dist[51];
bool inq[51]; //inq[i]����i�ǲ����ڶ����� 
void spfa(int x){
	queue<int> q;
	dist[x]=0;
	q.push(x);
	inq[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0; //u���Ѿ��뿪���У��Ͱ�inq[u]��Ϊ0 
		for(int i=0;i<n;i++){
			if(dist[i]-dis[u][i]>dist[u]){
				dist[i]=dist[u]+dis[u][i]; //����i�㵽���ľ��� 
				if(inq[i])continue; //����Ѿ��ڶ���������������� 
				q.push(i); //��i�������� 
				inq[i]=1; //����inq[i] 
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