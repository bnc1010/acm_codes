#include<iostream>
#define maxn 1000010 
using namespace std;
int _next[maxn];
char t[maxn],s[maxn];
int slen,tlen;
void getnext()
{
	int k=-1,j=0;
	_next[0]=-1;
	while(j<tlen)
	{
		if(k==-1||t[k]==t[j])_next[++j]=++k;
		else k=_next[k];
	}
}
int kmp()
{
	int j=0,i=0;
	getnext();
	for(int i=0;i<tlen;i++)printf("%d\n",_next[i]);
	while(i<slen&&j<tlen)
	{
		if(j==-1||s[i]==t[j])
		{
			j++;
			i++;
		}
		else j=_next[j];
	}
	if(j==tlen) return i-tlen+1;//返回主串中第一个字符的位置 
	else return -1;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		scanf("%d%d",&tlen,&slen);
		scanf("%s",t);
		scanf("%s",s);
		int temp=kmp();
	} 
	
}