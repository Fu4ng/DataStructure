#include <iostream>
using namespace std;
#define MAXQSIZE 6
typedef int QElemType; 
typedef struct QNode{  //���ṹ�� 
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{      //����ṹ�壬����ͷβָ�� 
	QueuePtr f;
	QueuePtr r; 
}LinkQueue;

bool IsEmpty(LinkQueue q){//�п�
	if(q.f->next == NULL) return 1;
	else return 0; 
}
void InitQueue(LinkQueue &q){//�������� 
	q.f = new QNode;
	q.r = new QNode;
	q.f =q.r;           //�п�������r = f 
	q.f->next =NULL;    //ͷָ���ÿ� 
} 
void EnQueue(LinkQueue &q,QElemType e){//��� 
	QueuePtr p =new QNode;
	p->data = e;
	p->next = NULL; q.r->next = p;
	q.r = p;
} 
void DeQueue(LinkQueue &q){//����
	 	if(IsEmpty(q))  //�ӿ�
	 	return ;
		
		QueuePtr p = new QNode;
		p = q.f->next;
		q.f->next = q.f->next->next;
		//���һ��ͷָ��
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
