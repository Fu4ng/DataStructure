#include <iostream>
using namespace std;
#define MAXQSIZE 6
typedef int QElemType; 
typedef struct QNode{  //结点结构体 
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{      //链表结构体，包含头尾指针 
	QueuePtr f;
	QueuePtr r; 
}LinkQueue;

bool IsEmpty(LinkQueue q){//判空
	if(q.f->next == NULL) return 1;
	else return 0; 
}
void InitQueue(LinkQueue &q){//创建队列 
	q.f = new QNode;
	q.r = new QNode;
	q.f =q.r;           //判空条件是r = f 
	q.f->next =NULL;    //头指针置空 
} 
void EnQueue(LinkQueue &q,QElemType e){//入队 
	QueuePtr p =new QNode;
	p->data = e;
	p->next = NULL; q.r->next = p;
	q.r = p;
} 
void DeQueue(LinkQueue &q){//出队
	 	if(IsEmpty(q))  //队空
	 	return ;
		
		QueuePtr p = new QNode;
		p = q.f->next;
		q.f->next = q.f->next->next;
		//最后一个头指针
		if(q.r == p) q.r=q.f; 	
	 	delete p;
}

int main(){
	LinkQueue q;
	InitQueue(q);
	cout<<IsEmpty(q)<<endl;
	for(int i=0;i<5;i++) EnQueue(q,i);
	DeQueue(q);
	QueuePtr t = q.f->next;
	for(int i=0;i<4;i++) {
		cout<<t->data;
		t = t->next;
	}
	cout<<endl;
	cout<<IsEmpty(q)<<endl;
	
} 
