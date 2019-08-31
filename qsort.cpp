#include<stdio.h>

void qsort(int *arr,int l,int r)
{
	if(l>=r)return;
	int k=arr[l],i=l,j=r;
	while(i<j)
	{
		while(i<j&&k<=arr[j])j--;
		arr[i]=arr[j];
		while(i<j&&k>=arr[i])i++;
		arr[j]=arr[i];
	}
	arr[i]=k;
	qsort(arr,l,i-1);
	qsort(arr,i+1,r);
}

int num[20005];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	qsort(num,1,n);
	for(int i=1;i<=n;i++)printf("%d%c",num[i],i==n?'\n':' ');
	return 0;
}

