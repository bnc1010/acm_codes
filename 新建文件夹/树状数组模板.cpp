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
		pos+=(pos&-pos);//ĩβ��1��λ 
	}
}
int query(int pos)
{
	int  ans=0;
	while(pos>0)
	{
		ans+=sum[pos];
		pos-=(pos&-pos);//ȥ��ĩβ��1 
	}
	return ans;
}
int main()
{
	int nxs=0;
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)//��������1-nʱ 
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
	}//�����ֲ��ǰ���1-nʱ����Ūһ��Сhash 
*/ 
	printf("%d\n",nxs);
	return 0;
}