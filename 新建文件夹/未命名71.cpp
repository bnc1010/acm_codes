#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[500][500],a[500],b[500];
int main()
{
	int n,m,k,s;
	while(~scanf("%d%d%d%d",&n,&m,&k,&s))
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<k;i++)
		scanf("%d%d",&a[i],&b[i]);
		for(int i=0;i<k;i++)
			for(int j=b[i];j<=m;j++)
				for(int h=s;h>=1;h--)
					dp[j][h]=max(dp[j][h],dp[j-b[i]][h-1]+a[i]);
		int i;
		for(i=0;i<=m;i++)
		{
			if(dp[i][s]>=n)
			break;
		}
		if(i>m)cout<<-1<<endl;
		else cout<<m-i<<endl;
		
	}
	return 0;
}