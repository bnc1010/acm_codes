#include<stdio.h>
#include<stdlib.h>
typedef long long ll;

class Queue
{
    typedef struct Node
    {
        ll data;
        Node *nxt,*pre;
    }*Elemt;
    Elemt Front,Back;
    ll Size;
    public:void Init()
    {
        Size=0;
        Front=(Elemt)malloc(sizeof(Node));
        Back=(Elemt)malloc(sizeof(Node));
        Front->pre=NULL;
        Back->pre=Front;
        Back->nxt=NULL;
        Front->nxt=Back;
    }
    public:void Push_Back(ll data)
    {
        Elemt p=(Elemt)malloc(sizeof(Node)),q=Back->pre;
        p->data=data;
        p->pre=q;
        p->nxt=Back;
        q->nxt=p;
        Back->pre=p;
        Size++;
    }
    public:void Push_Front(ll data)
    {
        Elemt p=(Elemt)malloc(sizeof(Node)),q=Front->nxt;
        p->data=data;
        p->nxt=q;
        p->pre=Front;
        q->pre=p;
        Front->nxt=p;
        Size++;
    }
    public:ll Get_Back()
    {
        if(Size==0){return -1;}
        return Back->pre->data;
    }
    public:ll Get_Front()
    {
        if(Size==0){return -1;}
        return Front->nxt->data;
    }
    public:void Pop_Back()
    {
        if(Size==0)return;//{printf("队列为空\n");return;}
        Elemt p=Back->pre,q=p->pre;
        free(p);
        if(q!=Front)
        {
            q->nxt=Back;
            Back->pre=q;
        }
        else
        {
            Front->nxt=Back;
            Back->pre=Front;
        }
        Size--;
    }
    public:void Pop_Front()
    {

        if(Size==0)return;//{printf("队列为空\n");return;}
        Elemt p=Front->nxt,q=p->nxt;
        free(p);
        if(q!=Back)
        {
            q->pre=Front;
            Front->nxt=q;
        }
        else
        {
            Front->nxt=Back;
            Back->pre=Front;
        }
        Size--;
    }
    public:void Clear()
    {
        Elemt p=Front->nxt;
        while(Front->nxt!=Back)
        {
            Front->nxt=p->nxt;
            free(p);
            p=Front->nxt;
        }
        Size=0;
    }
    public:ll Qsize()
    {
        return Size;
    }
};

int main()
{
    Queue q;
    q.Init();
    int n;
    long long tp;
    scanf("%d",&n);
    char op[10];
    for(int i=1;i<=n;i++)
    {
        scanf("%s",op);
        if(op[0]=='e')
        {
            scanf("%lld",&tp);
            q.Push_Back(tp);
        }
        else
        {
            printf("%lld\n",q.Get_Front());
            q.Pop_Front();
        }
    }
    return 0;
}

