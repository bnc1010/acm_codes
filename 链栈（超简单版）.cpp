#include<stdio.h>
#include<stdlib.h>

#define ERROR -1

class Stack
{
    typedef struct StNode
    {
        int data;
        StNode *per;
    }Node;
    struct
    {
        Node *top;
        int StackSize;
    }St;
    public:void InitStack()
    {
        St.top=NULL;
        St.StackSize=0;
    }
    public:int GetTop()
    {
        if(St.top==NULL)return ERROR;
        else return St.top->data;
    }
    public:void Push(int data)
    {
        Node *p=(Node*)malloc(sizeof(Node));
        p->data=data;
        p->per=St.top;
        St.top=p;
        St.StackSize++;
    }
    public:void Pop()
    {
        if(St.StackSize==0)return;
        Node *p=St.top;
        St.top=St.top->per;
        St.StackSize--;
        free(p);
    }
    public:bool Empty()
    {
        return St.StackSize==0;
    }
    public:int Size()
    {
        return St.StackSize;
    }
};

int main()
{
    int n,m,tp;
    scanf("%d%d",&n,&m);
    Stack st;
    st.InitStack();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tp);
        st.Push(tp);
    }
    char op[5];
    for(int i=1;i<=m;i++)
    {
        scanf("%s",op);
        if(op[1]=='u')
        {
            scanf("%d",&tp);
            st.Push(tp);
        }
        else
        {
            printf("%d\n",st.GetTop());
            st.Pop();
        }
        printf("%d**\n",st.Size());
    }
}
