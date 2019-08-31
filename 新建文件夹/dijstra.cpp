#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int mod = (int) 1e9+7;

int n,m,dist[205],head[205],vis[205],now;
struct edge{
	int to,next,val;
}e[2005];
void init(int x,int y,int v){
	e[++now].to=y,e[now].val=v,e[now].next=head[x],head[x]=now;
//	e[++now].to=x,e[now].val=v,e[now].next=head[y],head[y]=now;
}

struct node{
	int id,val;
	node(int id,int val):id(id),val(val){}
	bool operator < (const node &x)const{
		return val > x.val;
	}
};
priority_queue<node> q; 
void dij(int x){
	dist[x]=0;
	q.push(node(x,0));
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		vis[u]=1; 
		for(int i=head[u];~i;i=e[i].next){
			int v=e[i].to; 
			if(vis[v])continue;
			if(dist[v]-e[i].val>dist[u]){ 
				dist[v]=dist[u]+e[i].val;
				q.push(node(v,dist[v])); 
			}
		}
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dist,-1,sizeof(dist));
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		now=0;
		int x,y,z,w;
		scanf("%d",&m);
		for(int i=1;i<m;i++)
		{
			scanf("%d%d%d%d",&x,&y,&z,&w);
			init(x,y,z);
			init(y,x,w);
		}
		int p;
		scanf("%d",&p);
		while(p--)
		{
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			dij(t1);
			printf("%d\n",dist[t2]);
		}
		
	}
	return 0;
}