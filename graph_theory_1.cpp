/*
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
const int N=1e5+3;

int head[N],cnt;
int ans1,ans2;
struct node{
    int u,v,nxt;
}edge[N<<1];

void addedge(int u,int v){
    edge[++cnt].v=v;
    edge[cnt].u=u;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}

int dfn[N],low[N],st[N],bcc[N],top,tt,bccid;
bool vis[N<<1];

void tarjan(int u){
    if(dfn[u])return;
    low[u]=dfn[u]=++tt;
    st[++top]=u;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(vis[i])continue;
        vis[i]=vis[i^1]=true;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v]){
                ans1++;
            }
        }
        else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        bccid++;
        while(top){
            int now=st[top--];
            bcc[now]=bccid;
            if(now==u)break;
        }
    }
}

int tmp[N],point[N];
int main(){
    int n,m;
    while (~scanf("%d%d",&n,&m)){
        if(!n&&!m)break;
        memset(head,-1, sizeof(head));
        cnt=0;
        for(int i=1,u,v;i<=m;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        memset(bcc,0, sizeof(bcc));
        memset(dfn,0, sizeof(dfn));
        memset(vis,0, sizeof(vis));
        top=tt=bccid=0;
        ans1=ans2=0;
        for(int i=0;i<n;i++){
            if(!dfn[i]){
                tarjan(i);
            }
        }

        memset(tmp,0, sizeof(tmp));
        memset(point,0, sizeof(point));
        for(int i=1;i<=cnt;i+=2){
            int u=edge[i].u;
            int v=edge[i].v;
            //printf("u:%d v:%d   ubcc:%d   vbcc:%d\n",u,v,bcc[u],bcc[v]);
            if (bcc[u]==bcc[v]){
                tmp[bcc[u]]++;
            }
        }
        for(int i=0;i<n;i++){
            point[bcc[i]]++;
        }
        for(int i=1;i<=bccid;i++){
            if(tmp[i]!=point[i]){
                ans2+=tmp[i];
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
*/


#include<stdio.h>
#include<iostream>
#include<string.h>
#include <math.h>
using namespace std;

const int N=1e3+5;
const double inf=1e18;

struct _point{
    double x,y;
}p[N];

int head[N],cnt;

struct node{
    int u,v,nxt;
    double w;
}ed[N*N];

int pre[N], scc[N], vis[N];
double in[N];

double solve(int root, int n, int m){
    double ret = 0;
    while(true){
        for(int i=1; i<=n; i++) in[i] = inf; //维护最小入边
        in[root] = 0;
        for(int i=1; i<=m; i++){
            int u = ed[i].u, v = ed[i].v;
            if(ed[i].w < in[v] && u != v){
                pre[v] = u;//维护来源，保证了入边只有一条
                in[v] = ed[i].w;
            }
        }
        for(int i=1; i<=n; i++){
            if(in[i] == inf) return -1;//除了以外有点没有入边，则根从无法到达?
        }
        int cnt = 1;//统计环的个数
        memset(scc, -1, sizeof(scc));
        memset(vis, -1, sizeof(vis));
        for(int i=1; i<=n; i++){//标记每个环
            ret += in[i];
            int v = i;
            while(vis[v] != i && scc[v] == -1 && v != root){
                //每个点寻找其前序点，要么最终寻找至根部，要么找到一个环
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && scc[v] == -1){//找到环之后缩点
                for(int u=pre[v]; u!=v; u=pre[u])
                    scc[u] = cnt;
                scc[v] = cnt++;
            }
        }
        if(cnt == 1) break; //无环
        for(int i=1; i<=n; i++)
            if(scc[i] == -1) scc[i] = cnt++;
        for(int i=1; i<=m; i++){//重新建图
            int u = ed[i].u, v = ed[i].v;
            ed[i].u = scc[u];
            ed[i].v = scc[v];
            if(scc[u] != scc[v])//如果是在一个环里面的，我们已经计算过了，不再考虑
                ed[i].w -= in[v];//如果不在一个环里面 ，那么我们选这条边时，就可以删掉之前连向它的边
        }
        n = cnt - 1;
        root = scc[root];
    }
    return ret;
}


double dis(_point a,_point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
    int n,m;
    while (~scanf("%d%d",&n,&m)){
        if(!n&&!m)break;
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        for(int i=1,u,v;i<=m;i++){
            scanf("%d%d",&u,&v);
            double w=dis(p[u],p[v]);
            ed[i].u=u;
            ed[i].v=v;
            ed[i].w=w;
            if(u==v)ed[i].w=inf;
        }

        double ans=solve(1,n,m);
        if(ans==-1){
            printf("poor snoopy\n");
        }
        else{
            printf("%.2f\n",ans);
        }
    }
    return 0;
}

