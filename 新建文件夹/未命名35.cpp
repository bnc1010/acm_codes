#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

char mp[105];
int state[(1<<10)+5],dp[102][100][100],sum[(1<<10)+5];
int tot,top;
int n,m;
int cur[101];
void init()
{
    memset(dp,0,sizeof(dp));
    tot=1<<m;
    top=0;
    for(int i=0;i<tot;i++)
    {
        if((i&(i<<1))||(i&(i<<2)))continue;
        state[++top]=i;
        int tmp=i;
        sum[top]=0;
        while(tmp)
        {
            if(tmp&1)
			sum[top]++;
            tmp>>=1;
        }
    }
}

bool judge(int x,int pos)
{
    return !(x&cur[pos]);
}

int main()
{

    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=n;i++)
    {
    	scanf("%s",mp);
    	for(int j=1;j<=m;j++)
    	{
	    	if(mp[j-1]=='H')
	    	{
	    		cur[i]+=(1<<(m-j));
	    	}
	    }
    }
    for(int i=1;i<=top;i++)
    {
        if(judge(state[i],1))
        {
            dp[1][i][1]=sum[i];
        }
    }
    for(int i=1;i<=top;i++)
    {
        if(!judge(state[i],2))continue;
        for(int j=1;j<=top;j++)
        {
            if(state[i]&state[j])continue;
            if(!judge(state[j],0))continue;
            dp[2][i][j]=sum[i]+sum[j];
        }
    }
    for(int k=3;k<=n;k++)
    {
        for(int i=1;i<=top;i++)
        {
            if(!judge(state[i],k))continue;
            for(int j=1;j<=top;j++)
            {
                if(state[i]&state[j])continue;
                if(!judge(state[j],k-1))continue;
                for(int l=1;l<=top;l++)
                {
                    if(state[i]&state[l]||state[j]&state[l])continue;
                    if(!judge(state[l],k-2))continue;
                        dp[k][i][j]=max(dp[k][i][j],dp[k-1][j][l]+sum[i]);
                }
            }
        }
    }
    int ans=0;
    for (int j=1;j<=top;j++)
         for (int k=1;k<=top;k++)
             ans=max(ans,dp[n][j][k]);
    printf("%d\n",ans);
}



