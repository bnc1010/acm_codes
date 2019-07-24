//
// Created by bnc on 19-7-24.
//
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
#define N 100005
int num[N],ls[N];
int root[N];
int tsize[N*25],lchild[N*25],rchild[N*25];
int tot;


void updata(int last,int cur,int l,int r,int k)
{
    tsize[cur]=tsize[last]+1;
    lchild[cur]=lchild[last];
    rchild[cur]=rchild[last];
    if(l==r)return;
    int mid=(l+r)>>1;
    if(k<=mid)updata(lchild[last],lchild[cur]=++tot,l,mid,k);
    else updata(rchild[last],rchild[cur]=++tot,mid+1,r,k);
}

int query(int last,int cur,int L,int R,int k)
{
    if(L==R)return L;
    int mid=(L+R)>>1;
    int lson=tsize[lchild[cur]]-tsize[lchild[last]];
    if(lson>=k)return query(lchild[last],lchild[cur],L,mid,k);
    else return query(rchild[last],rchild[cur],mid+1,R,k-lson);
}
int sum;

int get_kth(int l,int r,int k){
    return num[query(root[l-1],root[r],1,sum,k)];
}

int main()
{
    int n,q;
    while (~scanf("%d%d",&n,&q)){
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]),ls[i]=num[i];
        sort(num+1,num+1+n);
        sum=unique(num+1,num+1+n)-num-1;
        tot=0;
        for(int i=1;i<=n;i++)updata(root[i-1],root[i]=++tot,1,sum,lower_bound(num+1,num+1+sum,ls[i])-num);
        int l,r;
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&l,&r);
            ll ans=-1;
            for(int k=r-l+1;k>=3;k--){
                int a=get_kth(l,r,k);
                int b=get_kth(l,r,k-1);
                int c=get_kth(l,r,k-2);
                if(a<b+c){
                    ans=1ll*a+1ll*b+1ll*c;
                    break;
                }
            }
            printf("%lld\n",ans);
        }
    }
}
