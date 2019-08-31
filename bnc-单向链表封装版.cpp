//.........................//
// author:bnc              //
// email:1010744256@qq.com //
//.........................//

#include<stdio.h>
#include<stdlib.h>
int ans;
class List
{
    private:struct ListNode
    {
        int data;
        ListNode *nxt;
    };
    private:struct ListHead
    {
        int ListSize;
        ListNode *nxt;
    };
    typedef struct ListHead Head;
    typedef struct ListNode Node;
    private:Head *head;
    private:void swap(int &a,int &b){int tmp=a;a=b;b=tmp;}
    public:List():head(NULL){}//初始化，把head指向为NULL
    public:void DestroyList()//摧毁表
    {
        Node *p=head->nxt,*q;
        free(head);
        while(p!=NULL)
        {
            q=p->nxt;
            free(p);
            p=q;
        }
        head=NULL;
    }
    public:void ListInit()//初始化
    {
        if(head!=NULL)DestroyList();
        head=(Head*)malloc(sizeof(Head));
        head->ListSize=0;
        head->nxt=NULL;
    }
    public:int ListSize()//表的尺寸
    {
        return head->ListSize;
    }
    public:bool ListEmpty()//表是否为空
    {
        return head->ListSize==0;
    }
    public:int FindElem(int data)//第一个位置
    {
        Node *p;
        p=head->nxt;
        int cnt=0;
        while(p!=NULL)
        {
            ++cnt;
            if(p->data==data)return cnt;
            p=p->nxt;
        }
        return -1;
    }
    public:void AddData(int data)//
    {
//        if(FindElem(data)!=-1){printf("已存在\n");return;}
        Node *p,*q;
        if(head->nxt==NULL)
        {
            p=(Node*)malloc(sizeof(Node));
            p->data=data;
            p->nxt=NULL;
            head->nxt=p;
            head->ListSize++;
        }
        else
        {
            p=head->nxt;
            while(p->nxt!=NULL)p=p->nxt;
            q=(Node*)malloc(sizeof(Node));
            q->data=data;
            q->nxt=NULL;
            p->nxt=q;
            head->ListSize++;
        }
    }
    public:void DeletByData(int data)//删除表中所有大小为data的节点
    {
        Node *p,*q;
        p=head->nxt;
        if(p->data==data)//如果第一个节点就是data，那么头节点的下一个指针要变成第二个节点的位置
        {
            head->nxt=p->nxt;
            free(p);
        }
        p=head->nxt;
        q=p;
        while(p->nxt!=NULL)
        {
            p=p->nxt;
            if(p->data==data)//如果当前这个节点是data，那么前一个节点的下一个指针就要变成当前节点的下一个节点的指针
            {
                q->nxt=p->nxt;
                free(p);
                head->ListSize--;
                p=q;
            }
            else
            {
                q=q->nxt;
                p=q;
            }
        }
    }
    public:void DeletByPos(int pos)//删除某一位置的节点
    {
        if(pos>(head->ListSize)||pos<=0)
        {
            printf("-1\n");
            return;
        } 
		Node *p,*q;
  		p=head->nxt;
        if(pos==1)
        {
        	printf("%d\n",p->data);
			head->nxt=p->nxt;
			free(p);
        }
        else
        {
        	int now=1;
	        while(now<pos)
	        {
	            q=p;
	            p=p->nxt;
	            now++;
	        }
	        printf("%d\n",p->data);
	        q->nxt=p->nxt;
	        free(p);
        }
        head->ListSize--;
    }
    public:int GetElem(int pos)//获取某一个位置的数
    {
        if(pos>(head->ListSize)||pos<=0)
        {
            return -1;
        }
        int now=1;
        Node *p;
        p=head->nxt;
        while(now<pos)
        {
            p=p->nxt;
            now++;
        }
        return p->data;
    }
    public:void PrintList()//打印表中所有数
    {
        //printf("有%d个元素\n",head->ListSize);
        ans=0;
        Node*p;
        p=head->nxt;
        int pp=1;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            ans+=p->data;
            p=p->nxt;
            pp^=1;
        }
        printf("\n");
    }
    public:void Union(List &b)//把表b的元素加入到这个表中
    {
        for(int i=1;i<=b.ListSize();i++)
        {
            int data=b.GetElem(i);
            //if(FindElem(data)==-1)
			AddData(data);
        }
    }
    /*
    public:void ListSort()//选择排序On^2
    {
        Node *fir=head->nxt;
        if(head==NULL||fir->nxt==NULL)return;
        Node*p =fir->nxt,*pstart=new Node,*pend=fir;
        pstart->nxt=fir;
        while(p!=NULL)
        {
            Node*tmp=pstart->nxt,*pre=pstart;
            while(tmp!=p&&p->data>=tmp->data) //找到插入位置
                {tmp=tmp->nxt;pre=pre->nxt;}
            if(tmp==p)pend=p;
            else
            {
                pend->nxt=p->nxt;
                p->nxt=tmp;
                pre->nxt=p;
            }
            p=pend->nxt;
        }
        fir=pstart->nxt;
        delete pstart;
        head->nxt=fir;
    }
    */
    private:Node *ListSortMerge(Node *head1,Node *head2)//归并排序，Onlogn
    {
        if(head1==NULL)return head1;
        if(head2==NULL)return head2;
        Node *res,*p ;
        if(head1->data<head2->data)
            {res=head1;head1=head1->nxt;}
        else{res=head2;head2=head2->nxt;}
        p=res;
        while(head1!=NULL&&head2!=NULL)
        {
            if(head1->data<head2->data)
            {
                p->nxt=head1;
                head1=head1->nxt;
            }
            else
            {
                p->nxt=head2;
                head2=head2->nxt;
            }
            p=p->nxt;
        }
        if(head1!=NULL)p->nxt=head1;
        else if(head2!=NULL)p->nxt=head2;
        return res;
    }
    private:Node *Sort(Node *fir)
    {
        if(fir==NULL||fir->nxt==NULL)return fir;
        else
        {
            ListNode *fast=fir,*slow=fir;//快慢指针找到中间节点
            while(fast->nxt!=NULL&&fast->nxt->nxt!=NULL)
            {
                fast=fast->nxt->nxt;
                slow=slow->nxt;
            }
            fast=slow;
            slow=slow->nxt;
            fast->nxt=NULL;
            fast=Sort(fir);//前半段排序
            slow=Sort(slow);//后半段排序
            return ListSortMerge(fast,slow);
        }
    }
    public:void ListSort()
    {
        head->nxt=Sort(head->nxt);
    }
    public:void ListClear()
    {
        if(head->ListSize==0)return; 
		Node *p=head->nxt,*q;
        while(p!=NULL)
        {
            q=p->nxt;
            free(p);
            p=q;
        }
        head->ListSize=0;
        head->nxt=NULL;
    }
    public:void InsertData(int pos,int data)
    {
    	if(pos<=0||pos>head->ListSize+1)
    	{
	    	printf("-1\n");
	    	return;
	    }
	    Node *p=head->nxt,*q,*pp;
	    q=(Node*)malloc(sizeof(Node));
	    if(pos==1)
	    {
    		q->data=data;
    		q->nxt=p;
    		head->nxt=q;
    	}
    	else if(pos<=head->ListSize)
    	{
	    	int now=1;
	    	while(now<pos)now++,pp=p,p=p->nxt;
	    	q->data=data;
	    	q->nxt=p;
	    	pp->nxt=q;
	    }
	    else if(pos==head->ListSize+1)
	    {
    		int now=1;
    		while(now<head->ListSize)now++,p=p->nxt;
    		q->data=data;
    		q->nxt=NULL;
    		p->nxt=q;
    	}
	    head->ListSize++;
    }
    public:void ListReseve()
    {
    	if(head->ListSize==1||head->ListSize==0)return;
    	Node *p=head->nxt,*q=p->nxt,*r;
    	p->nxt=NULL;
		r=q->nxt;
    	q->nxt=p;
    	while(r!=NULL)
    	{
	    	p=q,q=r;
			r=q->nxt;
	    	q->nxt=p;
	    }
	    head->nxt=q;
    } 
};

//用法: 
int main()
{
    List L;//定义一个表 
	L.ListInit();//要初始化一下 
	L.AddData(1);//在表尾加一个数据 
	L.DestroyList();//摧毁表
	L.ListSize();//表的大小
	L.ListEmpty();//表是否为空
	L.FindElem(data);//获得第一个大小为data得位置 
	L.DeletByData(data);// 删除表中所有的大小为data的节点 
	L.DeletByPos(pos);//删除位置为pos的节点 
	L.GetElem(pos);//获得位置为pos的值 
	L.PrintList();//打印表 
	L.Union(List B);//把表B的所有的元素加入到表L中 
	L.ListSort();//排序 
	L.ListClear();//清空 
	L.InsertData(pos,data);//在位置pos加入data 
	L.ListReseve();//反转表，已更新 
}