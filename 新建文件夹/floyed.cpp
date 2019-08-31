#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int mod = (int) 1e9+7;

int n,m,dis[205][205];

int main()
{
    while(~scanf("%d%d",&n,&m)){
        memset(dis,125,sizeof(dis)); //�������ʼ����һ���ܴ���� 
        for(int i=0;i<n;i++)dis[i][i]=0; //�Լ����Լ��ľ���Ϊ0 
        int x,y,z;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&x,&y,&z);
            dis[x][y]=dis[y][x]=min(dis[x][y],z); //˫��� 
        }
        for(int k=0;k<n;k++){ //ѡȡһ���㣬�������Բ�������·���� 
            for(int i=0;i<n;i++){ //ѡȡ��� 
                for(int j=0;j<n;j++){ //ѡȡһ���յ� 
                    if(dis[i][j]-dis[k][j]>dis[i][k]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        scanf("%d%d",&x,&y);
        if(dis[x][y]>mod)printf("-1\n");
        else printf("%d\n",dis[x][y]);
    }
    return 0;
}