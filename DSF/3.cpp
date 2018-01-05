#include <iostream>
using namespace std;
#define MAXQSIZE 6
typedef int QElemType; 
typedef struct{
	QElemType *base;
	int front;
	int rear ; //β�� 
}SqQueue;
bool IsEmpty(SqQueue q){//�п�
	if(q.front==q.rear) return 1;
	else return 0; 
}
void InitQueue(SqQueue &q){//�������� 
	q.base=new QElemType[MAXQSIZE];
	if(!q.base) return ;//����ʧ��
	q.front = 0;q.rear=0; 
}
void EnQueue(SqQueue &q,QElemType e){//��� 
	if((q.rear +1)%MAXQSIZE==q.front)  //���� 
		return ;
	q.base[q.rear] =e;
	q.rear=(q.rear+1)%MAXQSIZE;
} 
void DeQueue(SqQueue &q){//����
	 	if(IsEmpty(q))  //�ӿ�
	 	return ;
	 	
		q.front = (q.front+1)%MAXQSIZE; 
	 	
}

int main(){
	SqQueue q;
	InitQueue(q);
	cout<<IsEmpty(q)<<endl;
	for(int i=0;i<5;i++) EnQueue(q,i);
	for(int i=0;i<5;i++) {
		cout<<q.base[i];
		DeQueue(q);
	}
	cout<<endl;
	cout<<IsEmpty(q)<<endl;
	
} 
