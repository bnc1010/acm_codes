#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sum[1000010];
int n;
struct node
{
	int x,pos;
}a[1000010];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
void updata(int pos,int val)
{
	while(pos<=n)
	{
		sum[pos]+=val;
		pos+=(pos&-pos);//末尾的1进位 
	}
}
int query(int pos)
{
	int  ans=0;
	while(pos>0)
	{
		ans+=sum[pos];
		pos-=(pos&-pos);//去掉末尾的1 
	}
	return ans;
}
int main()
{
	int nxs=0;
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)//当数字是1-n时 
	{
		scanf("%d",&x);
		updata(x,1);
		int temp=query(x);
		nxs+=x-temp;
	} 
/* 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);
		a[i].pos=i;		
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		updata(a[i].pos,1);
		int temp=query(a[i].pos);
		nxs+=i-temp;
	}//当数字不是按照1-n时排序，弄一个小hash 
*/ 
	printf("%d\n",nxs);
	return 0;
}