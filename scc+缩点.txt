#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
const int N=2e3+5;

int head[N],head2[N],cnt;
int indegree[N],outdegree[N];

struct node{
    int v,nxt;
}edge[N<<2],edge2[N<<2];


void addedge(int u,int v){
    edge[++cnt].v=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}

void addedge2(int u,int v){
    edge2[++cnt].v=v;
    edge2[cnt].nxt=head2[u];
    head2[u]=cnt;
}

int dfn[N],low[N],st[N],scc[N],top,tt,sccid;

void tarjan(int u){
    if(dfn[u])return;
    low[u]=dfn[u]=++tt;
    st[++top]=u;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!scc[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        sccid++;
        while(top){
            int now=st[top--];
            scc[now]=sccid;
            if(now==u)break;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        int v;
        while(true){
            scanf("%d",&v);
            if(!v)break;
            addedge(i,v);
        }
    }
    for(int i=1;i<=n;i++){
        tarjan(i);
    }
    memset(head2,-1,sizeof(head2));
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=head[i];~j;j=edge[j].nxt){
            int v=edge[j].v;
            if(scc[i]==scc[v])continue;
            addedge2(scc[i],scc[v]);
            //printf("%d %d\n",scc[i],scc[v]);
            indegree[scc[v]]++;
            outdegree[scc[i]]++;
        }
    }
    int ans1=0,ans2=0,tp1=0,tp2=0;
    for(int i=1;i<=sccid;i++){
        if(!indegree[i]){
            ans1++;
            tp1++;
        }
        if(!outdegree[i]){
            tp2++;
        }
    }
    ans2=max(tp1,tp2);
    if(sccid==1){
        printf("1\n0\n");
    }
    else{
        printf("%d\n%d\n",ans1,ans2);
    }
    return 0;
}